`timescale 1ns / 1ps
module Joystick8Directions(
    input clk,
    input [3:0] Vrx,
    input [3:0] Vry,
    output reg [7:0] direction
);
    // Constants for center detection
    parameter CENTER_LOW = 6;
    parameter CENTER_HIGH = 9;
    parameter CENTER_X = 8;  // Center X value (assuming 0-15 range)
    parameter CENTER_Y = 8;  // Center Y value (assuming 0-15 range)
    
    // Working variables
    reg signed [4:0] dx, dy;  // Differences from center (using signed values)
    reg is_centered;          // Flag to indicate if joystick is centered
    
    always @(posedge clk) begin
        // Calculate distance from center (as signed values)
        dx = Vrx - CENTER_X;
        dy = Vry - CENTER_Y;
        
        // Check if joystick is in center position
        is_centered = (Vrx >= CENTER_LOW && Vrx <= CENTER_HIGH) && 
                     (Vry >= CENTER_LOW && Vry <= CENTER_HIGH);
        
        if (is_centered) begin
            // No direction active when in center
            direction <= 8'b00000000;
        end
        else begin
            // Initialize direction to all zeros
            direction <= 8'b00000000;
            
            // Determine active directions
            // N = 0, NE = 1, E = 2, SE = 3, S = 4, SW = 5, W = 6, NW = 7
            
            // Check East/West direction
            if (dx > 0) begin  // East side
                if (dy > 0) begin  // Northeast quadrant
                    if (dx > dy * 2)
                        direction[2] <= 1;  // Primarily East
                    else if (dy > dx * 2)
                        direction[0] <= 1;  // Primarily North
                    else
                        direction <= direction | 8'b00000101;  // Both N and E (NE)
                end
                else if (dy < 0) begin  // Southeast quadrant
                    if (dx > -dy * 2)
                        direction[2] <= 1;  // Primarily East
                    else if (-dy > dx * 2)
                        direction[4] <= 1;  // Primarily South
                    else
                        direction <= direction | 8'b00010100;  // Both E and S (SE)
                end
                else  // Pure East
                    direction[2] <= 1;
            end
            else if (dx < 0) begin  // West side
                if (dy > 0) begin  // Northwest quadrant
                    if (-dx > dy * 2)
                        direction[6] <= 1;  // Primarily West
                    else if (dy > -dx * 2)
                        direction[0] <= 1;  // Primarily North
                    else
                        direction <= direction | 8'b01000001;  // Both N and W (NW)
                end
                else if (dy < 0) begin  // Southwest quadrant
                    if (-dx > -dy * 2)
                        direction[6] <= 1;  // Primarily West
                    else if (-dy > -dx * 2)
                        direction[4] <= 1;  // Primarily South
                    else
                        direction <= direction | 8'b01010000;  // Both W and S (SW)
                end
                else  // Pure West
                    direction[6] <= 1;
            end
            else begin  // dx == 0
                if (dy > 0)      // Pure North
                    direction[0] <= 1;
                else if (dy < 0) // Pure South
                    direction[4] <= 1;
            end
        end
    end
endmodule