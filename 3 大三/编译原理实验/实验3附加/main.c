#include <stdio.h>
#include "otherfunction.h"
#include "string.h"

int main()
{
	bool nxtlev[symnum];  
	fin = fopen("F:\\大三下\\编译原理实验\\Fibonacci_e02.txt", "r");
	int trigernode=0;
	char c;
	printf("Open tree node[y/n]?");
	scanf("%c",&c);
	if(c=='y' || c=='Y')  trigernode=1;
	
	if(fin){
		ch=' ';
		init();     // 初始化 
		start_ofme(trigernode);
		fclose(fin);
	}
	else{
		printf("Can't open file!\n");
	}
	return 0;
} 

void start_ofme(int trigernode){
	trigernode_key=trigernode;
	printf("开始程序分析：\n"); 
	int i;
	getsymdo;
	program();
	levelup;
	getsymdo;
	printf("程序分析结束：\n");
}	

void program(){
	levelup;
	if (sym == constsym)    {
		// 收到常量声明符号，开始处理常量声明 
		getsymdo;
		constdeclaration_ofme();
	}
	if (sym == varsym){
		// 收到变量声明符号，开始处理变量声明 
		getsymdo;
		vardeclaration_ofme();
	}
	do{
		if (sym == procsym){
			getsymdo;
			procedure_ofme();
		}
	}while(sym==procsym);
	statement_ofme();
	leveldown;
}


void procedure_ofme(){
	levelup;
	if (sym == ident) {getsymdo;}
	else error(4);   // procedure后应为标识符
	if (sym == semicolon) {getsymdo;}
	else error(5);   // 漏掉了分号 
	program();
	leveldown;
}

void constdeclaration_ofme(){
	levelup;
	if (sym == ident){
		getsymdo;
		if (sym==eql){
			getsymdo;
			if (sym == number){
				getsymdo;
			}
			else error(2);   // 常量说明=后应是数字 
		}
		else error(3); //常量说明标识后应是=
	}
	else error(4);   //const后应是标识 
	while(sym==comma){
		getsymdo;
		if (sym == ident){
			getsymdo;
			if (sym==eql){
				getsymdo;
				if(sym == number){
					getsymdo;
				}
				else error(2);   // 常量说明=后应是数字 
			}
			else error(3); //常量说明标识后应是=
		}
		else error(4);   //const后应是标识 
	}
	if (sym == semicolon) {getsymdo;}
	else error(5);   //漏掉了逗号或者分号
	leveldown;
}


void vardeclaration_ofme(){
	levelup;
	if (sym == ident) {getsymdo;}
	else error(4);   // var后应是标识 
	while (sym == comma){
		getsymdo;
		if (sym == ident)  {getsymdo;}
		else error(4);   // var后应是标识 
	}
	if (sym == semicolon)  {getsymdo;}
	else error(5);   //漏掉了逗号或者分号
	leveldown;
}

void statement_ofme(){
	levelup;
	if (sym == ident) { // 准备按照赋值语句处理 
		getsymdo;
		allot_number();
	}
	else if (sym == readsym){ // 准备按照赋值语句处理 
		getsymdo;
		read_number();
	}
	else if(sym == writesym){    // 准备按照write语句处理，与read类似
		getsymdo;
		write_number();
	}
	else if(sym == callsym){   //准备按照call语句处理
		getsymdo;
		call_ofme();
	}
	else if(sym == ifsym){    // 准备按照if语句处理
		getsymdo;
		if_ofme();
	}
	else if(sym == beginsym){   //准备按照复合语句处理
		getsymdo;
		complex_statement();
	}	
	else if(sym == whilesym){   //准备按照whilesym语句处理
		getsymdo;
		while_ofme();
	}
	else{
		error(100);  //没有配对的语句 
	}
	
	//判断句子结束
	if (sym == semicolon || sym == endsym || sym == period){
		if (sym == semicolon || sym == semicolon) {getsymdo;}
	}
	else {
		error(5);   //漏掉了逗号或者分号
	}
	leveldown;
}

void while_ofme(){
	levelup;
	condition_ofme();
	if (sym == dosym)  {getsymdo;}
	else error(18);  // 缺少do
	statement_ofme();
	leveldown;
} 

void complex_statement(){
	levelup;
	statement_ofme();
	while(sym != endsym){
		statement_ofme();
	}
	if (sym == endsym)  {getsymdo;}
	else error(18); 
	leveldown; 
}

void if_ofme(){
	levelup;
	condition_ofme();
	if (sym == thensym) {getsymdo;}
	else error(16);  // 缺少then 
	statement_ofme();
	leveldown;
}


void call_ofme(){
	levelup;
	if (sym != ident) error(14);  // call后应为标识符 	
	getsymdo;
	leveldown;	
}


void write_number(){
	levelup;
	if (sym != lparen) error(34);  // 格式错误，应是左括号 
	do{
		getsymdo;
		expression_ofme();
	}while (sym == comma);
	if(sym == rparen) {getsymdo;}
	else error(33);
	leveldown;
}

void read_number(){
	levelup;
	if (sym != lparen) error(34);  // 格式错误，应是左括号 
	do{
		getsymdo;
		if (sym == ident) {getsymdo;}	
		else error(35);	
	}while (sym == comma);
	if(sym == rparen) {getsymdo;}
	else error(33);
	leveldown;
}


void allot_number(){
	levelup;
	if(sym == becomes) {getsymdo;}
	else error(13);  // 没有检测到赋值符号 
	expression_ofme();
	leveldown;
}

void condition_ofme(){
	levelup;
	expression_ofme();
	if (sym!=eql && sym!=neq && sym!=lss && sym!=leq && sym!=gtr && sym!=geq)
		error(20);
	getsymdo;
	expression_ofme();
	leveldown;
}

void expression_ofme(){
	levelup;
	if(sym==plus || sym==minus) {
	// 开头的正负号，此时当前表达式被看作一个正的或负的项 
		getsymdo;
		term_ofme();
	}
	else term_ofme();
	while (sym==plus || sym==minus){
		getsymdo;
		term_ofme();
	}
	leveldown;
}

void term_ofme(){
	levelup;
	factor_ofme(); 
	while(sym==times || sym==slash){
		getsymdo;
		factor_ofme();
	}
	leveldown;
}

void factor_ofme(){
	levelup;
	if(sym == ident){    // 因子为常量或变量 
		getsymdo;
	}
	else if(sym == number){
		getsymdo;
	}
	else if (sym == lparen){
		getsymdo;
		expression_ofme();
		if (sym == rparen) {getsymdo;}
		else error(22);  // 缺少右括号 
	}
	leveldown;
}









