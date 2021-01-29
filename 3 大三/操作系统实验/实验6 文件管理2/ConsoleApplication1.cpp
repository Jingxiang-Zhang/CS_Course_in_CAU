

#include <iostream>
#include "FCB.h"
#include "tools.h"
#include "CMD.h"
using namespace std;
int main()
{
	printf("Providence Azure [版本 1.0.001]\n");
	printf("(c) 2019 计算机172，张靖祥 Inc。保留所有权利。\n");
	Command cmd;
	string com;
	
	while (true) {
		if (cmd.login() == 1)
			break;
	}
	
	while (true) {
		cmd.showPWD();
		getline(cin, com);
		int result = cmd.execute((char*)com.c_str());
		if (result == 0) break;
	}
	
}

