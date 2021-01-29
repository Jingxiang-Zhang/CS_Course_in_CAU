`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/05/29 22:32:22
// Design Name: 
// Module Name: dffe_sim
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


module dffe_sim();
reg clk=1;
reg clrn=1;
reg wen=1;
reg d=1;
wire q;
 dffe u(.clk(clk),.clrn(clrn),.wen(wen),.d(d),.q(q));
initial  
     begin  
         clk = 0;  
        clrn = 0;  
        wen= 0;  
           
         forever  
         begin  
             #60 d <= 1;  
             #30 d <= 0;  
             #20  d <= 1;  
             #10  d <= 0;  
             #5 d <= 0;    
         end  
     end  
     always #940 clrn <= ~clrn;  
     always #360 wen <= ~wen;  
     always #20  clk <= ~clk;  
endmodule
