//StudybarCommentBegin

#include<stdio.h>
#include<string.h>

#include<stdlib.h>
char prog[80];  //保存带检测的字符 
char token[8];   //返回取出的字符 
char ch;  //临时变量 
int syn, p, m = 0, n, sum = 0; //p 是缓冲区 prog 的指针，m 是 token 的指针
char rwtab[6][6] = { "begin","if","then","while","do","end" };
//同学们需要写一个scaner()函数，然后上传。函数名如下，需要把函数体中的“代码填空”自行填充上传，共有7部分代码需要填充。填充后去掉函数外部的/*   */注释命令，以.c格式的文件上传。系统会合并前缀+上传函数+后缀，进行编译。

//StudybarCommentEnd

void scaner()
{
	for (n = 0;n<8;n++)
		token[n] = '\0';
	ch = prog[p++];
	while (ch == ' ') //空字符
 		//代码填空1//忽略空格
 		ch = prog[p++];
 	
	if ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z'))//标识符和保留字
	{
		m = 0;
		while ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z') || (ch >= '0'&&ch <= '9'))
		{
			token[m++] = ch;
			ch = prog[p++];
		}
		token[m++] = '\0';
		p--;
		syn = 10; //设置单词种别码 syn 为 10（标识符）
		for (n = 0;n<6;n++)
			if (!memcmp(token, rwtab[n], m - 1))
			{
				syn=n+1;
 				//代码填空2//设置单词种别码 syn（保留字）
				break;
			}
	}
	else
		if (ch >= '0'&&ch <= '9')//数字
		{
			sum = 0;
			while (ch >= '0'&&ch <= '9') //将数字串转换为数值存入 sum
			{
				sum=sum*10+ch-'0';
				ch = prog[p++];
 				//代码填空3
			}
			if ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z')) {
				while ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z'))
				{
					ch = prog[p++];
				}
				p--;
				syn=-1; 	
				//代码填空4 //设置单词种别码 syn 为-1（出错）
			}
			else {
				p--;
 				syn=11;//设置单词种别码 syn
			}
		}
		else
			switch (ch)//不是数字和字母
			{
				case'>':
					m = 0;
					token[m++] = ch;
					ch = prog[p++];
					if (ch == '=')
					{
						syn = 24; //设置单词种别码 syn 为 24（>=）
						token[m++] = ch;
					}
					else
					{
						syn = 23; //设置单词种别码 syn 为 23（>）
						p--;
					}
					break;
				case'<':
				 	//代码填空5//检测<、<=、<>号，设置单词种别码syn的值
				 	m = 0;
					token[m++] = ch;
					ch = prog[p++];
					if (ch == '=')
					{
						syn = 22; 
						token[m++] = ch;
					}
					else if (ch == '>')
					{
						syn = 21; 
						token[m++] = ch;
					}
					else
					{
						syn = 20; 
						p--;
					}
                    break;
				case':':
					m = 0;
					token[m++] = ch;
					ch = prog[p++];
					if (ch == '=')
					{
						syn = 18; 
					 	//代码填空6//设置单词种别码 syn
						token[m++] = ch;
					}
					else
					{
						syn = 17; 
					 	//代码填空7//设置单词种别码 syn
						p--;
					}
					break;
				case'-':syn = 13;token[0] = ch;break;
				case'+':syn = 14;token[0] = ch;break;
				case'*':syn = 15;token[0] = ch;break;
				case'/':syn = 16;token[0] = ch;break;
				case';':syn = 26;token[0] = ch;break;
				case')':syn = 27;token[0] = ch;break;
				case'(':syn = 28;token[0] = ch;break;
				case'#':syn = 0;token[0] = ch;break;
				default:syn = -1;
			}
}



//StudybarCommentBegin
int main()
{
	char test1[80]="begin A1:=9; X1:=2*3; B:=A1+X1 end#";
	char test2[80]="while r<>0 do begin q:=m/n r:=m-q*n; m:=n; n:=r; end#";
	char test3[80]="begin if m<n then r:=m; m:=n; n:=r; end;#";
	char test4[80]="1a#";
	int i;
	scanf("%d",&i);
	{ 
		switch(i)
		{
			case 1:strcpy(prog,test1); break;
			case 2:strcpy(prog,test2);break;
			case 3:strcpy(prog,test3); break;
			case 4:strcpy(prog,test4);break;
		}
		p = 0;
		do
		{
			scaner();
			switch (syn)
			{
				case 11: printf("(11,%d)",sum ); break;
				case -1: printf("error!"); break;
				default: printf("(%d,%s)", syn, token );
			}
		} while (syn != 0);
		printf("\n");
	}
	return 0;
}
//StudybarCommentEnd
