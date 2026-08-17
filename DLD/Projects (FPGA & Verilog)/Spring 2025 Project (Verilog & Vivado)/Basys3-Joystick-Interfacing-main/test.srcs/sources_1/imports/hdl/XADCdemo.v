module XADCdemo(
   input CLK100MHZ,
   input vauxp6,
   input vauxn6,
   input vauxp7,
   input vauxn7,
   input vauxp15,
   input vauxn15,
   input vauxp14,
   input vauxn14,
   output reg [7:0] LED,
   output [3:0] an,
   output dp,
   output [6:0] seg
   // Removed the joystick_direction output to fix pin constraint issue
);
   
   wire enable;  
   wire ready;
   wire [15:0] data;   
   reg [6:0] Address_in;     
   reg [32:0] decimal;   
   reg [3:0] dig0;
   reg [3:0] dig1;
   reg [3:0] dig2;
   reg [3:0] dig3;
   reg [3:0] dig4;
   reg [3:0] dig5;
   reg [3:0] dig6;
   reg [3:0] Vrx; // this can be used in the game logic to get x values (the values are from 01-15)
   reg [3:0] Vry; // this can be used in the game logic to get y values
   reg sw;
   reg [32:0] delay;
   
   // Internal wire for joystick directions - not connected to external pins
   wire [7:0] joystick_direction;

   // Joystick direction detector
   Joystick8Directions joystick_dir(
       .clk(CLK100MHZ),
       .Vrx(Vrx),
       .Vry(Vry),
       .direction(joystick_direction)
   );

   //xadc instantiation connect the eoc_out .den_in to get continuous conversion
   xadc_wiz_0  XLXI_7 (.daddr_in(Address_in), //addresses can be found in the artix 7 XADC user guide DRP register space
                     .dclk_in(CLK100MHZ), 
                     .den_in(enable), 
                     .di_in(), 
                     .dwe_in(), 
                     .busy_out(),                    
                     .vauxp6(vauxp6),
                     .vauxn6(vauxn6),
                     .vauxp7(vauxp7),
                     .vauxn7(vauxn7),
                     .vauxp14(vauxp14),
                     .vauxn14(vauxn14),
                     .vauxp15(vauxp15),
                     .vauxn15(vauxn15),
                     .vn_in(), 
                     .vp_in(), 
                     .alarm_out(), 
                     .do_out(data), 
                     //.reset_in(),
                     .eoc_out(enable),
                     .channel_out(),
                     .drdy_out(ready));
                     
   initial
   begin
      sw=0;
   end
      
   // Display joystick direction on LEDs
   always @(posedge CLK100MHZ) begin
       if (ready == 1'b1) begin
           // Display joystick direction on LEDs
           LED <= joystick_direction;
       end
   end
      
   reg [32:0] count; 
   //binary to decimal conversion
   always @ (posedge(CLK100MHZ))
   begin
       if(count == 10000000)begin
           decimal = data >> 4;
           if(decimal >= 4093)
           begin
               dig0 = 0;
               dig1 = 0;
               dig2 = 0;
               dig3 = 0;
               dig4 = 0;
               dig5 = 0;
               dig6 = 1;
               count = 0;
           end
           else 
           begin
               decimal = decimal * 250000;
               decimal = decimal >> 10;
               
               dig0 = decimal % 10;
               decimal = decimal / 10;
               
               dig1 = decimal % 10;
               decimal = decimal / 10;
                      
               dig2 = decimal % 10;
               decimal = decimal / 10;
               
               dig3 = decimal % 10;
               decimal = decimal / 10;
               
               dig4 = decimal % 10;
               decimal = decimal / 10;
                      
               dig5 = decimal % 10;
               decimal = decimal / 10; 
               
               dig6 = decimal % 10;
               decimal = decimal / 10; 
               
               count = 0;
           end
       end
       count = count + 1;
   end

   // Reduced delay for faster joystick response
   always @(posedge(CLK100MHZ))
   begin
       if (delay == 5000000) // Reduced for faster joystick response
       begin
           sw = ~sw; 
           delay = 0;
       end
       else
           delay = delay+1;
   end
      
   // Switch between reading X and Y values
   always @(posedge(CLK100MHZ))
   begin
       case(sw)
       0:  begin
           Address_in <= 8'h16;
           Vrx <= data[15:12];
       end
       
       1: begin
           Address_in <= 8'h1e;
           Vry <= data[15:12];
       end
       endcase
   end
      
   // This is for debugging and testing the values
   DigitToSeg segment1(.in1(dig3),
                     .in2(dig4),
                     .in3(dig5),
                     .in4(dig6),
                     .in5(),
                     .in6(),
                     .in7(),
                     .in8(),
                     .mclk(CLK100MHZ),
                     .an(an),
                     .dp(dp),
                     .seg(seg));  
endmodule
