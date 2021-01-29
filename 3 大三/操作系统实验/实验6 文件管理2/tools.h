#pragma once
#include <string.h>





void split(char* src, const char* separator, char** dest, int* num) {
	char* pNext;
	int count = 0;
	if (src == NULL || strlen(src) == 0)
		return;
	if (separator == NULL || strlen(separator) == 0)
		return;
	pNext = strtok(src, separator);
	while (pNext != NULL) {
		*dest++ = pNext;
		++count;
		pNext = strtok(NULL, separator);
	}
	*num = count;
}
/*
用法示意
char buf[] = "    name  sex    age   class id       ";
char* revbuf[8] = { 0 };
int num = 0;
split(buf, " ", revbuf, &num);
int i = 0;
for (i = 0; i < num; i++) {
	printf("%s\n", revbuf[i]);
}

*/