`timescale 1ns / 1ps
module switches(
    input clk, rst,
    input [15:0] btns,
    input [31:0] writeData, //  not to be written
    input writeEnable, // not to be used
    input readEnable,
    input [29:0] memAddress,
    input [15:0] switches,
    
    output reg  [31:0] readData
    );
    
    reg [7:0] switchData [3:0]; 
    
    
  
endmodule