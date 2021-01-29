`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/10/22 17:44:12
// Design Name: 
// Module Name: mux2x1verilog
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

module mux2x1verilog(
    input a,
    input b,
    input s,
    output c
    );
    wire a1,b1,sel;
    notgate_0 u0(.a(s),.c(sel));
    andgate_0 u1(.a(a),.b(sel),.q(a1));
    andgate_0 u2(.a(s),.b(b),.q(b1));
  //.....   //
endmodule
