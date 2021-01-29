`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

module Idecode32(read_data_1,read_data_2,Instruction,read_data,ALU_result,
                 Jal,RegWrite,MemorIOtoReg,RegDst,Sign_extend,clock,reset,opcplus4);
    output[31:0] read_data_1;               // 输出的第一操作数
    output[31:0] read_data_2;               // 输出的第二操作数
    input[31:0]  Instruction;               // 取指单元来的指令
    input[31:0]  read_data;   				//  从DATA RAM or I/O port取出的数据
    input[31:0]  ALU_result;   				// 从执行单元来的运算的结果，需要扩展立即数到32位
    input        Jal;                       //  来自控制单元，说明是JAL指令 
    input        RegWrite;                  // 来自控制单元
    input        MemorIOtoReg;              // 来自控制单元
    input        RegDst;                    //  来自控制单元
    output[31:0] Sign_extend;               // 扩展后的32位立即数
    input		 clock,reset;                // 时钟和复位
    input[31:0]  opcplus4;                 // 来自取指单元，JAL中用
    
    wire[31:0] read_data_1;
    wire[31:0] read_data_2;
    reg[31:0] register[0:31];			   //寄存器组共32个32位寄存器
    reg[4:0] write_register_address;        // 要写的寄存器的号
    reg[31:0] write_data;                   // 要写寄存器的数据放这里

    wire[4:0] read_register_1_address;    // 要读的第一个寄存器的号（rs）
    wire[4:0] read_register_2_address;     // 要读的第二个寄存器的号（rt）
    wire[4:0] write_register_address_1;   // r-form指令要写的寄存器的号（rd）
    wire[4:0] write_register_address_0;    // i-form指令要写的寄存器的号(rt)
    wire[15:0] Instruction_immediate_value;  // 指令中的立即数
    wire[5:0] opcode;                       // 指令码
    
    assign opcode = Instruction[31:26];						//OP
    assign read_register_1_address = Instruction[25:21];   	//rs
    assign read_register_2_address = Instruction[20:16];    //rt
    assign write_register_address_1 = Instruction[15:11];	//rd(r-form)
    assign write_register_address_0 = Instruction[20:16];	//rt(i-form)
    assign Instruction_immediate_value = Instruction[15:0];	//data,rladr(i-form)
    
    wire sign;                      // 取符号位的值
    assign sign = Instruction_immediate_value[15];
    assign Sign_extend[31:0] = ((opcode==6'b001100)     // andi
                      ||(opcode==6'b001101)             // ori
                      ||(opcode==6'b001110)             // xori
                      ||(opcode==6'b001011))            // sltiu
                      ? {16'h0000,Instruction_immediate_value[15:0]}  // 立即数0扩展
                      :{sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,Instruction_immediate_value[15:0]};  //立即数符号扩展
    
    assign read_data_1 = register[read_register_1_address];
    assign read_data_2 = register[read_register_2_address];
    
    always @* begin                                            //这个进程指定不同指令下的目标寄存器
        if((RegDst==1) && (Jal==0)) //r-form jal (pc+1 > sp[$Rlast])
            write_register_address = write_register_address_1; //RD(15-11)  R-form指令
        else if((RegDst==0) && (Jal==1))
            write_register_address = 5'b11111;                 //JAL 指令需要将下个指令的地址给最后一个寄存器
        else  write_register_address  = write_register_address_0;//i-form rt(20-16)
    end
    
    always @* begin  //这个进程基本上是实现结构图中右下的多路选择器 ,lw $5,$3(100)
        if((MemorIOtoReg==0) && (Jal== 0)) begin               //不是LW and IO, 也不是JAL指令
            write_data = ALU_result[31:0];
        end else if((MemorIOtoReg==0) && (Jal== 1)) begin      //不是LW，但是是jal,下个地址存$15
            write_data = opcplus4;
        end else begin
            write_data = read_data; 		                   //是LW指令
        end
    end
    
    integer i;
    always @(posedge clock) begin       // 本进程写目标寄存器
        if(reset==1) begin              // 初始化寄存器组
            for(i=0;i<32;i=i+1) register[i] <= i;
        end else if(RegWrite==1) begin  // 注意寄存器0恒等于0
            case(write_register_address[4:0])
                5'd0:register[0] <= 32'd0;
                5'd1:register[1] <= write_data;
                5'd2:register[2] <= write_data;
                5'd3:register[3] <= write_data;
                5'd4:register[4] <= write_data;
                5'd5:register[5] <= write_data;
                5'd6:register[6] <= write_data;
                5'd7:register[7] <= write_data;
                5'd8:register[8] <= write_data;
                5'd9:register[9] <= write_data;
                5'd10:register[10] <= write_data;
                5'd11:register[11] <= write_data;
                5'd12:register[12] <= write_data;
                5'd13:register[13] <= write_data;
                5'd14:register[14] <= write_data;
                5'd15:register[15] <= write_data;
                5'd16:register[16] <= write_data;
                5'd17:register[17] <= write_data;
                5'd18:register[18] <= write_data;
                5'd19:register[19] <= write_data;
                5'd20:register[20] <= write_data;
                5'd21:register[21] <= write_data;
                5'd22:register[22] <= write_data;
                5'd23:register[23] <= write_data;
                5'd24:register[24] <= write_data;
                5'd25:register[25] <= write_data;
                5'd26:register[26] <= write_data;
                5'd27:register[27] <= write_data;
                5'd28:register[28] <= write_data;
                5'd29:register[29] <= write_data;
                5'd30:register[30] <= write_data;
                5'd31:register[31] <= write_data;
                default:register[0] <= 32'd0;
            endcase
        end
    end
endmodule
