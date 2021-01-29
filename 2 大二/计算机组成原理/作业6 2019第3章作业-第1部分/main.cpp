#include <iostream>
#include <windows.h>
using namespace std; 
void transfor(bool *re,int value){
	re[0]=(value>=0)?0:1;
	int i;
	for(i=31;i>0;i--){
		re[i]=value%2;
		value=value/2;
	} 
}
void transfor2(bool *re,int value){
	re[32]=(value>=0)?0:1;
	int i;
	for(i=0;i<32;i++)
		re[i]=0;
	for(i=63;i>32;i--){
		re[i]=value%2;
		value=value/2;
	} 
}
void show(bool *re){
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++)
			if(re[i*8+j]==0) cout<<0;
			else cout<<1;
		cout<<" ";
	}
	cout<<endl;
}
void show2(bool *re){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++)
			if(re[i*8+j]==0) cout<<0;
			else cout<<1;
		cout<<" ";
	}
	cout<<endl;
}
void show3(bool *re){
	for(int i=4;i<8;i++){
		for(int j=0;j<8;j++)
			if(re[i*8+j]==0) cout<<0;
			else cout<<1;
		cout<<" ";
	}
	cout<<endl;
}
bool Add(bool *re1,bool *re2){
	int i;
	bool carry=0;
	for(i=0;i<32;i++){
		bool temp=re1[31-i]^re2[31-i]^carry;
		if((re1[31-i]&&re2[31-i]) || (re1[31-i]&&carry) ||
			(carry&&re2[31-i]))
			carry=1;
		else carry=0;
		re2[31-i]=temp;
	}
	return carry;
}
void translation(bool carry,bool *register2){
	int i;
	for(i=63;i>=1;i--){
		register2[i]=register2[i-1];
	} 
	register2[0]=carry;
}
int translate_to_dismal(bool *re){
	int result=0;
	int i;
	for(i=33;i<64;i++){
		int temp=(re[i]==0)?0:1;
		result=result*2+temp;
	}
	result=(re[32]==0)?result:-result;
	return result;
}
int main(int argc, char** argv) {
	int value1,value2;
	cout<<"Please input two multipliers"<<endl;
	cin>>value1>>value2; 
	bool register1[32];  //寄存器1表示被乘数 
	bool register2[64];  //寄存器2的后32位是乘积寄存器
	transfor(register1,value1);  //将乘数转化为2进制并存入寄存器中 
	transfor2(register2,value2);
	cout<<"register1:";
	show(register1);	//展示寄存器中的内容 
	cout<<"register2:";
	show2(register2);
	int i;
	for(i=0;i<32;i++){
		cout<<"number"<<i+1<<":"<<endl; 
		Sleep(100);  //模拟时钟周期 
		bool enable=register2[63];  //取最后一位，判断是否需要相加
		bool carry=0;
		if(enable)		//如果需要相加，则进行相加 
			carry=Add(register1,register2); //模拟串行进位加法器，返回进位信号 
		cout<<"After add:";
		show2(register2);
		translation(carry,register2);	//平移 
		cout<<"After translation:";
		show2(register2);
		cout<<endl<<endl;
	} 
	if(value1*value2<0)  //补充符号位 
		register2[32]=1;
	cout<<"Final result:";
	show3(register2);
	int finalresult=translate_to_dismal(register2);
	cout<<"To dismal:"<<finalresult;
	
	return 0;
}
