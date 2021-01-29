`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/10/04 10:00:43
// Design Name: 
// Module Name: minisys_sim
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


module minisys_sim(
    );
    // input
    reg clk = 0;
    reg rst = 1;
    reg[23:0] switch2N4 = 24'h000000;
    
    wire[23:0] led2N4;
    wire[7:0] tube_data;
    wire[7:0] tube_addr;
    
    minisys u (.rst(rst),.clk(clk),.led2N4(led2N4),.switch2N4(switch2N4),
            .tube_data(tube_data),.tube_addr(tube_addr));
    
    initial begin
        #7000 rst = 0;

    end
        
    always #10 clk=~clk;
        
endmodule
