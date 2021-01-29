#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 


struct quad{ 
	char result[12]; 
	char ag1[12]; 
	char op[12]; 
	char ag2[12]; 
}; 		//四元式的定义 
char prog[80];	//缓冲区 
int p=0;		//缓冲区 prog的指针 
char token[8];	//单词
int m=0;		//单词 token 的指针 
char ch;		//需要分析的字符 
int syn=0;		//单词的种别码 
int sum=0;		//计算整数 
int n=0;		//计数器 
int	kk=0;		//分析程序开始的标志 
int	k=0; 
const char *rwtab[6]={"begin","if","then","while","do","end"}; //关键字 
void scaner();		//扫描函数 
char* factor();		//因子 
char* term();		//项 
char* expression();	//表达式 
int yucu();			//语句串 
int statement();	//语句 
void emit(char*result,char*ag1,char*op,char*ag2); 
char* newtemp();


void emit(char*result,char*ag1,char*op,char*ag2) { 
	//实现 emit 函数的语句块
	printf("%s=%s%s%s\n",result,ag1,op,ag2); 
} 

char*newtemp() { 
	char*p=(char*)malloc(12); 
	char m[12]; 
	k++; 
	itoa(k,m,10); 
	strcpy(p+1,m);
	p[0]='t'; 
	return(p); 
}


void scaner() { 
	for(n=0;n<8;n++) { 
		token[n]=0;//初始化单词 
	} 
	ch=prog[p++]; 
	while(ch==' ') { 
		ch=prog[p++];//过滤空格 
	} 
	if ((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')) { 
		m=0; 
		while ((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9')) { 
			token[m++]=ch;//将当前字符存入单词 
			ch=prog[p++];//取下一个 
		} 
		token[m++]='\0';//结束符 
		p--;//指针归位 
		syn=10;// 假定是变量 
		for(n=0;n<6;n++) { 
			if (strcmp(token,rwtab[n])==0) {
				syn=n+1;//关键字！
				break;
			}
		}
	}
	else if(ch>='0'&&ch<='9') { 
		sum=0; 
		while(ch>='0'&&ch<='9') { 
			sum=sum*10+ch-'0';//计算数字 
			ch=prog[p++]; 
		}
		p--;//指针归位 
		syn=11;//是数 字！
	} 
	else switch(ch){ 
	case'>': 
		m=0; 
		token[m++]=ch; 
		ch=prog[p++]; 
		if(ch=='=') {
			syn=24;//是">="
			token[m++]=ch;//将"="存入单词
		} 
		else {
			syn=23;//是">" 
			p--;//指针归位
		}
		break;
		
	case'<': 
		m=0; 
		token[m++]=ch; 
		ch=prog[p++]; 
		if(ch=='>') {
			syn=21;//是"<>"
			token[m++]=ch;//将">"存入单 词
		} 
		else if(ch=='=') {
			syn=22;//是"<="
			token[m++]=ch;//将"="存入单 词	
		} 
		else {
			syn=20;//是"<" 
			p--;//指针归位
		}
		break; 
	case':': 
		m=0; 
		token[m++]=ch; 
		ch=prog[p++];
		if(ch=='=') {
			syn=18; 
			token[m++]=ch;
		} 
		else {
			syn=17; 
			p--;
		}
		break;
	case'-': 
		syn=13; 
		token[0]=ch; 
		break;
	case'+': 
		syn=14; 
		token[0]=ch; 
		break; 
	case'*': 
		syn=15; 
		token[0]=ch; 
		break; 
	case'/': 
		syn=16; 
		token[0]=ch; 
		break; 
	case';': 
		syn=26; 
		token[0]=ch; 
		break; 
	case'(': 
		syn=28; 
		token[0]=ch; 
		break; 
	case')': 
		syn=27; 
		token[0]=ch; 
		break; 
	case'#': 
		syn=0; 
		token[0]=ch; 
		break; 
	default:
		syn=-1;
	} 
} 
	
		
int	lrparser() { 
	int schain=0; 
	kk=0; 
	if(syn==1) {//begin
	 	scaner(); 
		schain=yucu(); 
		if(syn==6) {//end
			scaner(); 
			if((syn==0)&&(kk==0)) 
				printf("success!\n");
		} 
		else {
			if(kk!=1) {
				printf("缺少 end!\n"); 
				kk=1;
			}	
		}
	}
	else {
		printf("缺少 begin!\n"); 
		kk=1;
	} 
	return(schain);
}

int yucu() { //语句串
	int schain=0; 
	schain=statement(); 
	while(syn==26){ //； 
		scaner(); 
		schain=statement(); 
	} 
	return(schain); 
}

int statement(){//语句
	int schain=0; 
	char*eplace,*tt; 
	eplace=(char*)malloc(12); 
	tt=(char*)malloc(12); 
	switch(syn) { 
	case 10://标识符 
		strcpy(tt,token); 
		scaner(); 
		if(syn==18) {
			scaner(); 
			strcpy(eplace,expression()); 
			// 生成一个三地址码送到四元式表中 
			emit(tt,eplace,"","");
			schain=0;
		} 
		else {
			printf("缺少赋值符!\n"); 
			kk=1;
		}
	break;
	}
	return(schain);
}

char*expression(void) { 
	char*tp,*ep2,*eplace,*tt; 
	tp=(char*)malloc(12); 
	ep2=(char*)malloc(12); 
	eplace=(char*)malloc(12); 
	tt=(char*)malloc(12); 
	strcpy(eplace,term()); 
	while(syn==13||syn==14) { 
		if(syn==13) 
			strcpy(tt,"-"); 
		else 
			strcpy(tt,"+"); 
		scaner();
		strcpy(ep2,term()); 
		//调用 newtemp()返回一个新的临时变量名,并将其复制到 tp 指向的单元里 
		strcpy(tp,newtemp());
		// 生成一个三地址码送到四元式表中 
		emit(tp,eplace,tt,ep2);
		
		strcpy(eplace,tp); 

		
	} 
	return(eplace);
}	 

char*term(void) { 
	char*tp,*ep2,*eplace,*tt;   //tt表示生成一个当前符号的标号t1 t2 t3 
	tp=(char*)malloc(12); 
	ep2=(char*)malloc(12);  //表达式右侧内容 
	eplace=(char*)malloc(12); 
	tt=(char*)malloc(12);   //表示因子的符号 
	strcpy(eplace,factor()); //表达式左侧的内容 
	while((syn==15 )||(syn==16)) { 
		if(syn==15) 
			strcpy(tt,"*"); 
		else 
			strcpy(tt,"/"); 
		scaner(); 
		strcpy(ep2,factor()); 
		strcpy(tp,newtemp()); 
		// 生成一个三地址码送到四元式表中 
		emit(tp,eplace,tt,ep2);
		strcpy(eplace,tp); 
	} 
	return(eplace); 
}

char*factor(void) { 
	char*fplace; 
	fplace=(char*)malloc(12); 
	strcpy(fplace,""); 
	if(syn==10) {
		strcpy(fplace,token);
		scaner();
	}
	else if(syn==11) { 
		itoa(sum,fplace,10);
		scaner();
	}
	else if(syn==28) { 
		scaner(); 
		fplace=expression(); 
		if(syn==27) 
			scaner();
		else {
			printf("错误 \n"); 
			kk=1;
		}
	}
	else{
		printf("错误 \n"); 
		kk=1;
	}
	return(fplace);
}



int main() { 
	system("color F0");
	printf("请输入测试程序（1,2,3）:\n"); 
	int i; 	
	scanf("%i",&i); 
	switch(i) { 
	case 1:
		strcpy(prog,"begin a:=2+3*4;x:=(a+b)/c end#");
		break; 
	case 2:
		strcpy(prog,"begin a:=(21+31)*41;x:=a+bf+c end#");
		break; 
	case 3:
		strcpy(prog,"begin a:=(21+31)*41;x:=a+bf+c #");
		break; 
	} 
	printf("\n语义分析结果为:\n"); 
	p=0; 
	scaner(); 
	lrparser(); 
	system("pause"); 
	return 0;
}
 
		
