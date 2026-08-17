module led_race_track(
    input wire clk,          // 100 MHz system clock
    input wire rst,          // Reset button
    input wire PS2_CLK,      // PS/2 clock line
    input wire PS2_DATA,     // PS/2 data line
    output reg [15:0] led    // 16 LEDs
);

    // Parameters
    parameter SPACEBAR_CODE = 8'h29;   // PS/2 scan code for space bar
    
    // PS/2 keyboard interface signals
    reg [10:1] ps2_shift_reg = 10'h3FF;
    reg [7:0] ps2_data = 0;
    reg ps2_clk_prev = 1'b1;
    reg [3:0] ps2_bit_count = 0;
    reg is_break_code = 0;
    
    // Space bar detection
    reg space_pressed = 0;
    reg space_pressed_prev = 0;
    
    // PS/2 keyboard interface logic
    always @(posedge clk) begin
        if (rst) begin
            ps2_shift_reg <= 10'h3FF;
            ps2_data <= 0;
            ps2_clk_prev <= 1'b1;
            ps2_bit_count <= 0;
            is_break_code <= 0;
            space_pressed <= 0;
            space_pressed_prev <= 0;
        end else begin
            space_pressed_prev <= space_pressed;
            
            // Detect PS/2 clock falling edge
            if (ps2_clk_prev && !PS2_CLK) begin
                ps2_shift_reg <= {PS2_DATA, ps2_shift_reg[10:2]};
                ps2_bit_count <= ps2_bit_count + 1;
                
                // We have received a full PS/2 frame
                if (ps2_bit_count == 10) begin
                    ps2_bit_count <= 0;
                    ps2_data <= ps2_shift_reg[8:1]; // Extract 8 data bits
                    
                    // Check for break code (F0) or make code
                    if (ps2_shift_reg[8:1] == 8'hF0) begin
                        is_break_code <= 1;
                    end else if (is_break_code) begin
                        is_break_code <= 0;
                        // Key released
                        if (ps2_shift_reg[8:1] == SPACEBAR_CODE) begin
                            space_pressed <= 0;
                        end
                    end else begin
                        // Key pressed
                        if (ps2_shift_reg[8:1] == SPACEBAR_CODE) begin
                            space_pressed <= 1;
                        end
                    end
                end
            end
            
            ps2_clk_prev <= PS2_CLK;
        end
    end
    
    // Simplified LED rotation logic - rotate immediately on space press
    always @(posedge clk) begin
        if (rst) begin
            led <= 16'h0001;  // Initialize with bit 0 set
        end else if (space_pressed && !space_pressed_prev) begin
            // Rotate LED immediately when space bar is pressed
            led <= {led[14:0], led[15]};  // Rotate left with wraparound
        end
    end

endmodule
