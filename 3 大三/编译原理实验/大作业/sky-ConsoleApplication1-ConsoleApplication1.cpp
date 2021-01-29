// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include "lexer.h"
#include "symboltable.h"
#include "runningtime.h"
#include "phraser.h"
#include "initfunction.h"

void split(char* src, const char* separator, char** dest, int* num);
void welcome_show();

int main(int argc, char** argv)
{	
	if (argc == 2) {
		try {
			running_table_class* table = new running_table_class();
			table->in_import(argv[1]);
			lexer* lex = new lexer(argv[1]);
			init_function initfun(table);
			phraser phr(lex, table);
			phr.run();
			printf("\n");
			printf("\n");
		}
		catch (const char* c) {
			printf("lethal error happend, type: %s.\n\n", c);
		}
		catch (...) {
			printf("lethal error happend, type: unkonwn.\n\n");
		}
		printf("\n\n输入任意键继续...");
		_getch();
		return 0;
	}

	printf("type \"?\" to see the commmand\n");
	welcome_show();
	while (true) {
		printf(">>");
		std::string name;
		
		std::getline(std::cin, name);
		char* buf = (char*)name.c_str();
		char* revbuf[8] = { 0 }; //存放分割后的子字符串 
		int num = 0;
		split(buf, " ", revbuf, &num); //调用函数进行分割 
		if (num == 0) {
			continue;
		}
		if (strcmp(revbuf[0], "quit") == 0) {
			if (num != 1) {
				printf("parameter error!\n\n");
			}
			else {
				break;
			}
		}
		else if (strcmp(revbuf[0], "?") == 0) {
			printf("  quit      --quit the shell\n");
			printf("  run       --run a py0 program\n");
			printf("  version   --the version of the program\n");
			printf("\n\n");
		}
		else if (strcmp(revbuf[0], "version") == 0) {
			if (num != 1) {
				printf("parameter error!\n\n");
			}
			else {
				welcome_show();
			}
		}
		else if (strcmp(revbuf[0], "run") == 0) {
			if (num != 2) {
				printf("parameter error!\n\n");
			}
			else if (strcmp(revbuf[1], "?") == 0) {
				printf("  PATH      --the path of the program, no space is permitted\n");
			}
			else {
				try {
					running_table_class* table = new running_table_class();
					table->in_import(revbuf[1]);
					lexer* lex = new lexer(revbuf[1]);
					init_function initfun(table);
					phraser phr(lex, table);
					phr.run();
					printf("\n");
					printf("\n");
				}
				catch (const char *c) {
					printf("lethal error happend, type: %s.\n\n",c);
				}
				catch(...){
					printf("lethal error happend, type: unkonwn.\n\n");
				}
			}
		}
		else {
			printf("command error!\n\n");
		}
	}

}


void split(char* src, const char* separator, char** dest, int* num)
{
	/*
		src 源字符串的首地址(buf的地址)
		separator 指定的分割字符
		dest 接收子字符串的数组
		num 分割后子字符串的个数
	*/
	char* pNext;
	int count = 0;

	if (src == NULL || strlen(src) == 0) //如果传入的地址为空或长度为0，直接终止 
		return;

	if (separator == NULL || strlen(separator) == 0) //如未指定分割的字符串，直接终止 
		return;
	char* buf;
	pNext = (char*)strtok_s(src, separator, &buf); //必须使用(char *)进行强制类型转换(虽然不写有的编译器中不会出现指针错误)
	while (pNext != NULL) {
		*dest++ = pNext;
		++count;
		pNext = (char*)strtok_s(NULL, separator, &buf);  //必须使用(char *)进行强制类型转换
	}
	*num = count;
}


void welcome_show() {
	printf("\nprogram language py0 [version: 1.0 beta]\nRelease day: 2020/6/7 ");
	printf("\nAuthor: CAU-CIEE  Zhang Jingxiang - Ethan.\nTo score the source code please connect to 1967527237@qq.com\n\n");

}