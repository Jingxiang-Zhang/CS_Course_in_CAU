`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/01/14 15:39:52
// Design Name: 
// Module Name: dffe
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module dffe(
    input clk,
    input clrn,
    input wen,
    input d,
    output reg q
    );
 
    always @(posedge clk or posedge clrn)
    begin
    if (!clrn) q=0;
     else if (!wen) q = d;
    end

endmodule
