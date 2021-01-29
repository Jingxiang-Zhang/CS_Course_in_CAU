#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>


//打开灯的驱动，产生490~505的文件，
//等价于 echo 490 > /sys/class/gpio/export 
void open_light(){
	int fd = open("/sys/class/gpio/export", O_RDWR);
	char n[16];
	if(fd==-1){
		printf("error open light\n");
		exit(EXIT_FAILURE);
	}
	int i;
	for(i=0;i<16;i++){
		//将490~505写入到export驱动中 
		sprintf(n,"%d",490+i);
		write(fd,n,sizeof(n));
	}
	close(fd);
}


//打开490~505地址的灯的out，
//等价于 echo out > /sys/class/gpio/gpio490/direction 
void out_light(){
	char cmd1[50];
	char name[] = "/sys/class/gpio/gpio";
	char n[20];
	int i;
	for(i=0;i<16;i++){
		//产生相关的灯驱动的路径字符串 
		strcpy(cmd1,name);
		sprintf(n,"%d",490+i);
		strcat(cmd1,n);
		strcat(cmd1,"/direction");
		
		//打开灯驱动文件 
		int fd = open(cmd1,O_RDWR);
		if(fd==-1){
			printf("error open out\n");
			printf("%s",cmd1); 
			exit(EXIT_FAILURE);
		}	 
		
		//写入out 
		write(fd,"out",sizeof("out"));
		close(fd);
	}
}


//走马灯控制函数 
void light(char value[17]){
	int i;
	while(1){
		char name[] = "/sys/class/gpio/gpio";
		char cmd2[50];
		char n[20];
		for(i=0;i<16;i++){
			//产生相关的灯驱动的路径字符串 
			strcpy(cmd2,name);
			sprintf(n,"%d",490+i);
			strcat(cmd2,n);
			strcat(cmd2,"/value");
			
			//打开灯驱动文件 
			int fd=open(cmd2,O_RDWR);
			if (fd < 1) {
				printf("error open light led\n");
				printf("%s",cmd2); 
				exit(EXIT_FAILURE);
			}
			
			//写入亮灯指令 
			if(value[i]=='1'){
				write(fd,"1",sizeof("1"));
			}
			else{
				write(fd,"0",sizeof("0"));
			}
		}
		//睡眠2秒 
		usleep(1500000);
		
		//交换灯的顺序 
		char tmp1=value[0];
		char tmp2=value[1];
		for(i=0;i<14;i++){
			value[i]=value[i+2];
		}
		value[14]=tmp1;
		value[15]=tmp2;
		value[16]='\0';
		
	}
}


//小组编号：21 = 10101 
int main(void) {
	
	//打开灯的驱动，产生490~505的文件，等价于 echo 490 > /sys/class/gpio/export 
	open_light();
	
	//打开490~505地址的灯的out，等价于 echo out > /sys/class/gpio/gpio490/direction 
	out_light();
	
	//组号为21，相应的二进制位0b10101，初始定义如下 
	char value[17]={'1','0','1','0','1','0','0','0','0','0','0','0','0','0','0','0','0'};
	//走马灯控制函数 
	light(value);
	
}





