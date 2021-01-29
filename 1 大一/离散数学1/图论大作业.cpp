#include <iostream>
#include<fstream> 
using namespace std;

int main(int argc, char** argv) {
	ofstream aa;	
	ifstream kk;
	char c,s;
	char m[20];
	int x,y;
	
	int number1=0,number2=0,times;
	int data[30000];
	aa.open("f1",ios::out) ;          //写入文件 
	kk.open("ka.tsv",ios::binary);    //读入文件 
	for(int k=0;k<25;k++) {kk.get(c);cout<<c;}                                 
	for(x=0;x<20;x++) m[x]='\0';
	for(x=0;x<30000;x++) data[x]=0;
	
    while(!kk.eof() )               //一直读到文件结束 
{

    for(x=0;x<20;x++)     //x为一组的长度 
    {
    	kk.get(m[x]);
    	if(m[x]=='\n') break;
	} 
	for(y=0;y<20;y++)    //读出第一个数字 
	{
		if(m[y]>='0'&&m[y]<='9') number1=number1*10+m[y]-48;
		else break;
	}
	for(y++;y<x;y++)    //读出第二个数字 
	{
		if(m[y]>='0'&&m[y]<='9') number2=number2*10+m[y]-48;
      	else break;
	}
 
	for(y++;y<x;y++)    //读出合作次数 
	{
		if(m[y]>='0'&&m[y]<='9') times=times*10+m[y]-48;
		else break;
	}
    data[number1]=times+data[number1];
	data[number2]=times+data[number2]; 
    for(x=0;x<20;x++) m[x]='\0';
    number1=0;number2=0;times=0;
 
    
}
    int tt;              //将数组排序 
    for(x=0;x<29999;x++)
    for(y=0;y<29999;y++)
    if(data[y]<data[y+1]) {tt=data[y];data[y]=data[y+1];data[y+1]=tt;	} 
    
    int degree[30000],size[30000],ma=0,na;    
    for(x=0;x<30000;x++) {degree[x]=0;size[x]=0;}
    
    for(x=0,y=-1;x<30000;x++)    //计算每个度数（degree）有多少个结点（size）  
    {
    	if(ma!=data[x]) 
    	{
    		y++;
    		ma=data[x];
    		size[y]++;
			degree[y]=ma; 
		}
		else if(ma==data[x])
		{
			size[y]++;
		}
	}                         //y是总的行数
	
	for(x=0;x<y;x++) 
	{
		aa<<degree[x]<<"  "<<size[x]<<endl;    //写入文件 
	}
	aa.close() ; 
	kk.close() ;
	return 0;
}
