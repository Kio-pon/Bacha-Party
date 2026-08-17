`timescale 1ns / 1ps

module leds(
    input clk,
    input rst,
    input [31:0] writeData,
    input writeEnable,
    input readEnable,
    input [29:0] memAddress,
    
    output reg  [31:0] readData = 0, // not to be read       
    output reg [15:0] leds
    );
    
    
   
endmodule


