#pragma once

#include "filestream.h"
#include "tools.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

class Command {
private:
	FileStream filestream;
	void __changeColor(i_FileMode mode);
	int uid;
public:
	Command();
	int login();
	int execute(char *command);
	void showPWD();
	int list(const char* method);
	int mkdir(char *name, const char *authority);
	int cd(const char *name);
	int del(const char* name);
	int open(const char*mode, const char* name);
	int write(const char* name, const char* content);
	int close(const char* name);
	int read(const char* name);
	int showopen();
};

Command::Command() {

}

int Command::execute(char* command) {
	char* revbuf[8] = { 0 };
	int num = 0;
	split(command, " ", revbuf, &num);
	int i = 0;
	if (num == 0) return 1;
	int result = 2;
	if (strcmp(revbuf[0], "formatdisk") == 0) {
		result = filestream.formatDisk();
	}
	else if (strcmp(revbuf[0], "quit") == 0) {	
		return 0;
	}
	else if (strcmp(revbuf[0], "ls") == 0) {
		if (num == 1) {
			result = list("");
		}
		else if (num == 2) {
			result = list(revbuf[1]);
		}
		else result = 3;
	}
	else if (strcmp(revbuf[0], "mkdir") == 0) {
		if (num == 2) {
			result = mkdir(revbuf[1], "777");
		}
		else if (num == 3) {
			result = mkdir(revbuf[1], revbuf[2]);
		}
		else result = 3;
	}
	else if (strcmp(revbuf[0], "cd") == 0) {
		if (num == 2) {
			result = cd(revbuf[1]);
		}
		else result = 3;
	}
	else if (strcmp(revbuf[0], "del") == 0) {
		if (num == 2) {
			result = del(revbuf[1]);
		}
		else result = 3;
	}
	else if (strcmp(revbuf[0], "open") == 0) {
		if (num == 3) {
			result = open(revbuf[1], revbuf[2]);
		}
		else result = 3;
	}
	else if (strcmp(revbuf[0], "close") == 0) {
		if (num == 2) {
			result = close(revbuf[1]);
		}
		else result = 3;
	}
	else if (strcmp(revbuf[0], "write") == 0) {
		if (num == 3) {
			result = write(revbuf[1], revbuf[2]);
		}
		else result = 3;
	}
	else if (strcmp(revbuf[0], "showopen") == 0) {
		if (num == 1) {
			result = showopen();
		}
		else result = 3;
	}
	else if (strcmp(revbuf[0], "read") == 0) {
		if (num == 2) {
			result = read(revbuf[1]);
		}
		else result = 3;
	}
	switch (result) {
	case -1:printf("can not execute command, you don't have authority.\n"); break;
	case 0:printf("command execute failed.\n"); break;
	case 2:printf("%s is not a vaild command.\n", revbuf[0]); break;
	case 3:printf("invalid parameter.\n"); break;
	}
	return 1;
}

int Command::close(const char* name) {
	filestream.closeFile((char*)name);
	return 1;
}

int Command::read(const char* name) {
	int length;
	char* c = filestream.readFile((char*)name, &length);
	printf("%s\n", c);
	return 1;
}

int Command::open(const char* mode, const char* name) {
	fileOpenMode openmode;
	if (strcmp(mode, "read")==0)
		openmode = fileOpenMode::readmode;
	else if (strcmp(mode, "exe")==0)
		openmode = fileOpenMode::exemode;
	else if (strcmp(mode, "write")==0)
		openmode = fileOpenMode::writemode;
	else if (strcmp(mode, "create") == 0)
		openmode = fileOpenMode::create;
	else 
		return 3;
	filestream.openFile((char*)name, openmode);
	return 1;
}

int Command::showopen() {
	filestream.showopen();
	return 1;
}

int Command::write(const char* name, const char* content) {
	filestream.writeFile((char*)name, (char*)content, strlen(content));
	return 1;
}

int Command::del(const char* name) {
	char* revbuf[20] = { 0 };
	int num = 0;
	char* newchar = new char[200];
	strcpy(newchar, name);
	split(newchar, "\\", revbuf, &num);
	int i = 0;
	if (num == 1) {
		
		filestream.delFile((char*)name);
	}
	else {
		FileStream filestream2;
		filestream2.setUid(uid);
		for (int i = 0; i < num - 1; i++) {
			filestream2.cdDirectory(revbuf[i]);
		}
		filestream2.delFile(revbuf[num - 1]);
		
	}
	return 1;
}

int Command::cd(const char *name) {
	if (strcmp(name, "..") == 0) {
		filestream.depthDeduce();
		return 1;
	}
	else {
		int result = filestream.cdDirectory(name);
		if (result == 0) {
			printf("no such directory.\n");
			return 1;
		}
		else {
			return result;
		}
	}
}

void Command::__changeColor(i_FileMode mode) {
	switch (mode) {
	case i_FileMode::Content: 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		break;
	case i_FileMode::Exe:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
		break;
	case i_FileMode::Link:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		break;
	default:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		break;
	}
	
}

int Command::list(const char *method) {
	fileInfo* info = new fileInfo[1024];
	int length = filestream.getBatchSon(info, 1024);
	
	if (strcmp(method, "") == 0) {
		for (int i = 0; i < length; i++) {
			__changeColor(info[i].mode);
			printf("%15s", info[i].name);
			if ((i + 1) % 5 == 0) printf("\n");
		}
	}
	else if(strcmp(method, "-l") == 0){
		printf("        name  uid  authroity     size   mode    createtime          modifytime\n");
		for (int i = 0; i < length; i++) {
			__changeColor(info[i].mode);
			printf("%10s %5d   %6d %10d     %d    %d/%d/%d %d:%d   %d/%d/%d %d:%d\n", 
				info[i].name, info[i].uid, info[i].authority,info[i].size, info[i].mode,
				info[i].ctime.YY, info[i].ctime.MM, info[i].ctime.DD, info[i].ctime.hh, info[i].ctime.mm,
				info[i].mtime.YY, info[i].mtime.MM, info[i].mtime.DD, info[i].mtime.hh, info[i].mtime.mm);
		}
	}
	else {
		return 3;
	}
	__changeColor(i_FileMode::Empty);
	printf("\n\n");
	return 1;
}

int Command::mkdir(char* name, const char* authority) {
	int a1 = authority[0] - 48;
	int a2 = authority[1] - 48;
	int a3 = authority[2] - 48;
	if (a1 > 7 || a1 < 0 || a2>7 || a2 < 0 || a3>7 || a3 < 0) {
		return 2;
	}
	
	int result=filestream.mk(name, a3 * 100 + a2 * 10 + a1 , i_FileMode::Content);
	if (result == 0) {
		printf("directory has already exist.\n");
		return 1;
	}
	return result;
}



void Command::showPWD() {
	filestream.getPWD();
}

int Command::login() {
	printf("account: ");
	string account;
	getline(cin, account);
	printf("pwd: ");
	string pwd;
	for (int i = 0; i < 15; i++) {
		char c = getch();
		if (!((c >='A' && c<='Z' )|| (c >= '0' && c <= '9')|| (c >= 'a' && c <= 'z'))) {
			break;
		}
			
		pwd.append(1, c);
	}
	if (account == "root" && pwd == "root") {
		filestream.setUid(0);
		printf("\n\nlogin successful. user: root\n");
		return 1;
	}
	
	filestream.setUid(0);
	uid = 0;
	printf("\n\nlogin successful. user: root\n");
	return 1;
	return 0;
}







