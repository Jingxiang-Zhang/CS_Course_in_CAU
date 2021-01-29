
#include "pl0.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base_path[15] = "base.data";
char save_path[15] = "save.s";

void write_mips_inst(FILE *save_file,int *jump_record){
	
	int i; 
	for(i=0;i<cx-1;i++)
   	{
   		char buffer[50] = {0};
		char temp_buf[25] = {0};
		
		//输出翻译的行号
		char line_num[10] = {'#'};
		char tempt[10] = {0}; 
		itoa(i, tempt, 10);
		strcat(line_num, tempt);
		strcat(line_num, "\n");
		fputs(line_num, save_file);
		
		//判断是否需要跳转
		if(jump_record[i]!=-1){
			char tempt2[20] = "user_location_";
			char tempt22[10];
			itoa(i, tempt22, 10);
			strcat(tempt2, tempt22);
			strcat(tempt2, ":\n");
			fputs(tempt2, save_file);
		} 
		
   		switch(code[i].f)
		{
			case lit:
				strcat(buffer, "        ori $t4, $zero, ");
				itoa(code[i].a, temp_buf, 10);
				strcat(buffer, temp_buf);
				strcat(buffer, "\n        jal _lit\n");  
				break;
			case opr:        
				strcat(buffer, "        jal _opr_");
				itoa(code[i].a, temp_buf, 10);
				strcat(buffer, temp_buf);
				strcat(buffer, "\n");
				break;
			case lod:       
				strcat(buffer, "        ori $t4, $zero, ");
				itoa(code[i].a * 4, temp_buf, 10);
				strcat(buffer, temp_buf);  //ori $t4, $zero, number
				strcat(buffer, "\n        ori $t5, $zero, "); 
				itoa(code[i].l, temp_buf, 10);
				strcat(buffer, temp_buf);  //ori $t5, $zero, number
				strcat(buffer, "\n        jal _lod\n");  
				break;
			case sto:       
				strcat(buffer, "        ori $t4, $zero, ");
				itoa(code[i].a * 4, temp_buf, 10);
				strcat(buffer, temp_buf);  //ori $t4, $zero, number
				strcat(buffer, "\n        ori $t5, $zero, "); 
				itoa(code[i].l, temp_buf, 10);
				strcat(buffer, temp_buf);  //ori $t5, $zero, number
				strcat(buffer, "\n        jal _sto\n");  
				break;		
			case cal:       //cal指令有待调试   
			    strcat(buffer, "        jal _cal\n        sw $ra, ($t9)\n        addi $t9, 4\n        j user_location_");
				itoa(code[i].a, temp_buf, 10);
				strcat(buffer, temp_buf);  //ori $t4, $zero, number
				strcat(buffer, "\n");   
				break;		
			case inte:      
				strcat(buffer, "        ori $t4, $zero, ");
				itoa(code[i].a * 4, temp_buf, 10);
				strcat(buffer, temp_buf);  //ori $t4, $zero, number
				strcat(buffer, "\n        jal _inte\n");
				break;			
			case jmp: 
				strcat(buffer, "        j user_location_");
				itoa(code[i].a, temp_buf, 10);
				strcat(buffer, temp_buf);
				strcat(buffer, "\n");
				break;
			case jpc:
				strcat(buffer, "        jal _jpc\n        beq $t6, $zero, user_location_");
				itoa(code[i].a, temp_buf, 10);
				strcat(buffer, temp_buf);
				strcat(buffer, "\n");
	    		break;
	    		
		}
		fputs(buffer, save_file);
   	}
   	char tempt2[20] = "user_location_";
	char tempt22[10];
	itoa(i, tempt22, 10);
	strcat(tempt2, tempt22);
	strcat(tempt2, ":\n        j _end\n");
	fputs(tempt2, save_file);
} 

void interpret_to_mips(){
	FILE *base_file = fopen(base_path,"r");  //打开基础编译文件 
	FILE *save_file = fopen(save_path,"w");   //打开待写入文件 
	
	int *jump_record = new int[cx];           //第一遍，读取所有跳转位置，并做标记
	for(int i=0;i<cx;i++)  jump_record[i] = -1;
	for(int i=0;i<cx;i++){
   		if(code[i].f == jmp || code[i].f == jpc || code[i].f == cal){
   			int target = code[i].a;
   			jump_record[target] = i;
		}
   	}
   	
   	//将基本编译文件写入save文件
	char buffer[200];
	fgets(buffer,100,base_file);
	while(!feof(base_file)){
	    fputs(buffer,save_file);
	    fgets(buffer,100,base_file);
	}
	
	//写入编译指令 
	write_mips_inst(save_file,jump_record);
	//释放空间
	delete jump_record;
   	//关闭文件 
	fclose(base_file);
	fclose(save_file);
}


