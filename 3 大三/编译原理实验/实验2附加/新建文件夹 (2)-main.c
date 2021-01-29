#include <stdio.h>
#include "pl0.h"
#include "string.h"
void startsplit();
//该程序为独立的词法分析程序
//F:\大三下\编译原理实验\Fibonacci_e02.txt
int main()
{
	bool nxtlev[symnum];
	//printf("Input a file:");
	//scanf("%s", fname);    
	fin = fopen("F:\\大三下\\编译原理实验\\Fibonacci_e02.txt", "r");
	
	
	if(fin){
		ch=' ';
		init();     // 初始化 
		
		startsplit();
		fclose(fin);
	}
	else{
		printf("Can't open file!\n");
	}
	return 0;
} 

char name[10]="";
void startsplit(){
	printf("开始分析：\n"); 
	int i;
	while(true){
		getsym();
		printf("(%s,%d)\n",name,sym);
		if(name[0]=='.')
			break;
	}
	printf("分析结束：\n");
}

void init()
{
	int i;

	// 设置单字符符号 
	for (i=0; i<=255; i++)
	{
		ssym[i] = nul;
	}
	ssym['+'] = plus;
	ssym['-'] = minus;
	ssym['*'] = times;
	ssym['/'] = slash;
	ssym['('] = lparen;
	ssym[')'] = rparen;
	ssym['='] = eql;
	ssym[','] = comma;
	ssym['.'] = period;
	ssym['#'] = neq;
	ssym[';'] = semicolon;

	// 设置保留字名字,按照字母顺序，便于折半查找 
	strcpy(&(word[0][0]), "begin");
	strcpy(&(word[1][0]), "call");
	strcpy(&(word[2][0]), "const");
	strcpy(&(word[3][0]), "do");
	strcpy(&(word[4][0]), "end");
	strcpy(&(word[5][0]), "if");
	strcpy(&(word[6][0]), "odd");
	strcpy(&(word[7][0]), "procedure");
	strcpy(&(word[8][0]), "read");
	strcpy(&(word[9][0]), "then");
	strcpy(&(word[10][0]), "var");
	strcpy(&(word[11][0]), "while");
	strcpy(&(word[12][0]), "write");

	// 设置保留字符号 
	wsym[0] = beginsym;
	wsym[1] = callsym;
	wsym[2] = constsym;
	wsym[3] = dosym;
	wsym[4] = endsym;
	wsym[5] = ifsym;
	wsym[6] = oddsym;
	wsym[7] = procsym;
	wsym[8] = readsym;
	wsym[9] = thensym;
	wsym[10] = varsym;
	wsym[11] = whilesym;
	wsym[12] = writesym;
	// 设置指令名称 
	strcpy(&(mnemonic[lit][0]), "lit");
	strcpy(&(mnemonic[opr][0]), "opr");
	strcpy(&(mnemonic[lod][0]), "lod");
	strcpy(&(mnemonic[sto][0]), "sto");
	strcpy(&(mnemonic[cal][0]), "cal");
	strcpy(&(mnemonic[inte][0]), "int");
	strcpy(&(mnemonic[jmp][0]), "jmp");
	strcpy(&(mnemonic[jpc][0]), "jpc");

	// 设置符号集 
	for (i=0; i<symnum; i++)
	{
		declbegsys[i] = false;
		statbegsys[i] = false;
		facbegsys[i] = false;
	}

	// 设置声明开始符号集 
	declbegsys[constsym] = true;
	declbegsys[varsym] = true;
	declbegsys[procsym] = true;

	// 设置语句开始符号集 
	statbegsys[beginsym] = true;
	statbegsys[callsym] = true;
	statbegsys[ifsym] = true;
	statbegsys[whilesym] = true;
	statbegsys[readsym] = true;
	statbegsys[writesym] = true;

	//设置因子开始符号集 
	facbegsys[ident] = true;
	facbegsys[number] = true;
	facbegsys[lparen] = true;
}

void error(int n)
{
	char space[81];
	memset(space,32,81);

	space[cc-1]=0; //出错时当前符号已经读完，所以cc-1

	printf("****%s!%d\n", space, n);
	fprintf(fa1,"****%s!%d\n", space, n);

	err++;
}

int getch()
{
	if (cc == ll)  //cc和ll用于记录读取指针。每次调用的时候，如果cc=ll说明缓冲区取完了，要重新读取文件
	{              //每次读取文件，ll记录一行的长度，cc记录当前位置。每次调用该函数，则ch中保存下一个字符
		if (feof(fin))
		{
			printf("program incomplete");
			return -1;
		}
		ll=0;
		cc=0;
		printf("当前句子：");
		fprintf(fa1,"%d ", cx);  //写入
		ch = ' ';
		while (ch != 10)     //一直读到换行符为止
		{
			//fscanf(fin,"%c", &ch)
			//richard
			if (EOF == fscanf(fin,"%c", &ch))   //如果读到了结尾，退出
			{
				line[ll] = 0;
				break;
			}
			//end richard
			printf("%c", ch);
			fprintf(fa1, "%c", ch);
			line[ll] = ch;
			ll++;
		}
		printf("\n");
		fprintf(fa1, "\n");
	} 
	ch = line[cc];
	cc++;
	return 0;
}


int getsym()
{
	int i,j,k;
	
	// the original version lacks "\r", thanks to foolevery 
	while (ch==' ' || ch==10 || ch==13 || ch==9)  // 忽略空格、换行、回车和TAB 
	{
		getchdo;
	}
	if (ch>='a' && ch<='z')
	{           // 名字或保留字以a..z开头 
		k = 0;
		do {    //取出一个词
			if(k<al)
			{
				a[k] = ch;
				k++;
			}
			getchdo;
		} while (ch>='a' && ch<='z' || ch>='0' && ch<='9');
		a[k] = 0;
		strcpy(id, a);
		strcpy(name, a);
		
		i = 0;
		j = norw-1;
		
		do {    //搜索当前符号是否为保留字    //折半查找是否为保留字
			k = (i+j)/2;
			if (strcmp(id,word[k]) <= 0)
			{
				j = k - 1;
			}
			if (strcmp(id,word[k]) >= 0)
			{   //两个if同时满足，是保留字，则 j比i小2
				i = k + 1;
			}
			
		} while (i <= j);
		
		if (i-1 > j)
		{
			sym = wsym[k];   //获取到一个保留字
			
		}
		else
		{
			sym = ident; // 搜索失败则，是名字或数字 
		}
	}
	else
	{
		if (ch>='0' && ch<='9')
		{           // 检测是否为数字：以0..9开头 
			k = 0;
			num = 0;
			sym = number;
			do {
				num = 10*num + ch - '0';
				name[k]=ch;
				k++;
				getchdo;
			} while (ch>='0' && ch<='9'); // 获取数字的值 
			name[k]='\0'; 
			k--;
			if (k > nmax)
			{
				error(30);
			}
		}
		else
		{
			if (ch == ':')      // 检测赋值符号 
			{
				name[0]=':';
				getchdo;
				if (ch == '=')
				{
					sym = becomes;
					name[1]='=';
					name[2]='\0';
					getchdo;
				}
				else
				{
					sym = nul;  // 不能识别的符号 
					name[0]='n';
					name[1]='i';
					name[2]='l';
					name[3]='\0';
				}
			}
			else
			{
				if (ch == '<')      // 检测小于或小于等于符号 
				{
					name[0]='<';
					getchdo;
					if (ch == '=')
					{
						name[1]='=';
						name[2]='\0';
						sym = leq;
						getchdo;
					}
					else
					{
						name[1]='\0';
						sym = lss;
					}
				}
				else
				{
					if (ch=='>')        // 检测大于或大于等于符号 
					{
						name[0]='>';
						getchdo;
						if (ch == '=')
						{
							name[1]='=';
							name[2]='\0';
							sym = geq;
							getchdo;
						}
						else
						{
							name[1]='\0';
							sym = gtr;
						}
					}
					else
					{
						sym = ssym[ch];     // 当符号不满足上述条件时，全部按照单字符符号处理 
						//getchdo;
						//richard
						name[0]=ch;
						name[1]='\0';
						if (sym != period)
						{
							getchdo;
						}
						//end richard
					}
				}
			}
		}
	}
	return 0;
}



