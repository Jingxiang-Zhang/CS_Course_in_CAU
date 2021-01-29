#include <stdio.h>
#include "pl0.h"
#include "string.h"
 

//该程序为独立的词法头文件 
void init()
{
	int i;

	/* 设置单字符符号 */
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

	/* 设置保留字名字,按照字母顺序，便于折半查找 */
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

	/* 设置保留字符号 */
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

	/* 设置指令名称 */
	strcpy(&(mnemonic[lit][0]), "lit");
	strcpy(&(mnemonic[opr][0]), "opr");
	strcpy(&(mnemonic[lod][0]), "lod");
	strcpy(&(mnemonic[sto][0]), "sto");
	strcpy(&(mnemonic[cal][0]), "cal");
	strcpy(&(mnemonic[inte][0]), "int");
	strcpy(&(mnemonic[jmp][0]), "jmp");
	strcpy(&(mnemonic[jpc][0]), "jpc");

	/* 设置符号集 */
	for (i=0; i<symnum; i++)
	{
		declbegsys[i] = false;
		statbegsys[i] = false;
		facbegsys[i] = false;
	}

	/* 设置声明开始符号集 */
	declbegsys[constsym] = true;
	declbegsys[varsym] = true;
	declbegsys[procsym] = true;

	/* 设置语句开始符号集 */
	statbegsys[beginsym] = true;
	statbegsys[callsym] = true;
	statbegsys[ifsym] = true;
	statbegsys[whilesym] = true;
	statbegsys[readsym] = true;
	statbegsys[writesym] = true;

	/* 设置因子开始符号集 */
	facbegsys[ident] = true;
	facbegsys[number] = true;
	facbegsys[lparen] = true;
}


/*
* 初始化
*/

/*
* 用数组实现集合的集合运算
*/
int inset(int e, bool* s)
{
	return s[e];
}

int addset(bool* sr, bool* s1, bool* s2, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		sr[i] = s1[i]||s2[i];
	}
	return 0;
}

int subset(bool* sr, bool* s1, bool* s2, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		sr[i] = s1[i]&&(!s2[i]);
	}
	return 0;
}

int mulset(bool* sr, bool* s1, bool* s2, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		sr[i] = s1[i]&&s2[i];
	}
	return 0;
}

/*
*   出错处理，打印出错位置和错误编码
*/
void error(int n)
{
	char space[81];
	memset(space,32,81);

	space[cc-1]=0; //出错时当前符号已经读完，所以cc-1

	printf("****%s!%d\n", space, n);
	fprintf(fa1,"****%s!%d\n", space, n);

	err++;
}

/*
* 漏掉空格，读取一个字符。
*
* 每次读一行，存入line缓冲区，line被getsym取空后再读一行
*
* 被函数getsym调用。
*/
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
		printf("%d ", cx);
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

/*
* 词法分析，获取一个符号
*/
int getsym()
{
	int i,j,k;

	/* the original version lacks "\r", thanks to foolevery */
	while (ch==' ' || ch==10 || ch==13 || ch==9)  /* 忽略空格、换行、回车和TAB */
	{
		getchdo;
	}
	if (ch>='a' && ch<='z')
	{           /* 名字或保留字以a..z开头 */
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
		i = 0;
		j = norw-1;
		do {    /* 搜索当前符号是否为保留字 */   //折半查找是否为保留字
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
			sym = ident; /* 搜索失败则，是名字或数字 */
		}
	}
	else
	{
		if (ch>='0' && ch<='9')
		{           /* 检测是否为数字：以0..9开头 */
			k = 0;
			num = 0;
			sym = number;
			do {
				num = 10*num + ch - '0';
				k++;
				getchdo;
			} while (ch>='0' && ch<='9'); /* 获取数字的值 */
			k--;
			if (k > nmax)
			{
				error(30);
			}
		}
		else
		{
			if (ch == ':')      /* 检测赋值符号 */
			{
				getchdo;
				if (ch == '=')
				{
					sym = becomes;
					getchdo;
				}
				else
				{
					sym = nul;  /* 不能识别的符号 */
				}
			}
			else
			{
				if (ch == '<')      /* 检测小于或小于等于符号 */
				{
					getchdo;
					if (ch == '=')
					{
						sym = leq;
						getchdo;
					}
					else
					{
						sym = lss;
					}
				}
				else
				{
					if (ch=='>')        /* 检测大于或大于等于符号 */
					{
						getchdo;
						if (ch == '=')
						{
							sym = geq;
							getchdo;
						}
						else
						{
							sym = gtr;
						}
					}
					else
					{
						sym = ssym[ch];     /* 当符号不满足上述条件时，全部按照单字符符号处理 */
						//getchdo;
						//richard
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



/*
* 生成虚拟机代码
*
* x: instruction.f;
* y: instruction.l;
* z: instruction.a;
*/
int gen(enum fct x, int y, int z )
{
	if (cx >= cxmax)
	{
		printf("Program too long"); /* 程序过长 */
		return -1;
	}
	code[cx].f = x;
	code[cx].l = y;
	code[cx].a = z;
	cx++;
	return 0;
}


/*
* 测试当前符号是否合法
*
* 在某一部分（如一条语句，一个表达式）将要结束时时我们希望下一个符号属于某集?
* （该部分的后跟符号），test负责这项检测，并且负责当检测不通过时的补救措施，
* 程序在需要检测时指定当前需要的符号集合和补救用的集合（如之前未完成部分的后跟
* 符号），以及检测不通过时的错误号。
*
* s1:   我们需要的符号
* s2:   如果不是我们需要的，则需要一个补救用的集?
* n:    错误号
*/

int test(bool* s1, bool* s2, int n)
{
	if (!inset(sym, s1))
	{
		error(n);
		/* 当检测不通过时，不停获取符号，直到它属于需要的集合或补救的集合 */
		while ((!inset(sym,s1)) && (!inset(sym,s2)))
		{
			getsymdo;
		}
	}
	return 0;
}
















