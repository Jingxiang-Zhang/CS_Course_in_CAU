`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

module memorio(caddress,address,memread,memwrite,ioread,iowrite,mread_data,
                ioread_data,wdata,rdata,write_data,LEDCtrl,SwitchCtrl,LeddataCtrl);
    input[31:0] caddress;       // from alu_result in executs32
    input memread;				// read memory, from control32
    input memwrite;				// write memory, from control32
    input ioread;				// read IO, from control32
    input iowrite;				// write IO, from control32
    input[31:0] mread_data;		// data from memory
    input[15:0] ioread_data;	// data from io,16 bits
    input[31:0] wdata;			// the data from idecode32,that want to write memory or io
    output[31:0] rdata;			// data from memory or IO that want to read into register
    output[31:0] write_data;    // data to memory or I/O
    output[31:0] address;       // address to mAddress and I/O
	
	output LeddataCtrl;
    output LEDCtrl;				// LED CS
    output SwitchCtrl;          // Switch CS
    
    reg[31:0] write_data;
    wire iorw;
    
    assign  address = caddress;
    assign  rdata = (memread==1) ? mread_data : {16'h00,ioread_data[15:0]};
    assign  iorw = (iowrite||ioread);
	
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	assign	LEDCtrl = ((iorw==1) && (caddress[31:4] == 28'hFFFFFC6)) ? 1'b1:1'b0;
	assign	SwitchCtrl = ((iorw==1) && (caddress[31:4] == 28'hFFFFFC7)) ? 1'b1:1'b0;
	assign  LeddataCtrl = ((iorw==1) && (
	                          caddress[31:4] == 28'hFFFFFD0
	                        ||caddress[31:4] == 28'hFFFFFD1
	                        ||caddress[31:4] == 28'hFFFFFD2
	                        ||caddress[31:4] == 28'hFFFFFD3
	                        ||caddress[31:4] == 28'hFFFFFD4
	                        ||caddress[31:4] == 28'hFFFFFD5
	                        ||caddress[31:4] == 28'hFFFFFD6
	                        ||caddress[31:4] == 28'hFFFFFD7)) ? 1'b1:1'b0;
							
    always @* begin
        if((memwrite==1)||(iowrite==1)) begin
            write_data = wdata;
        end else begin
            write_data = 32'hZZZZZZZZ;
        end
    end
endmodule