#include<stdio.h>
int main()
{
	int son=fork();
	if(son<0)
		printf("Creat son error!\n");
	if(son==0){
		printf("using t2-1\n");
		execlp("./t2-1","s1","s2",NULL);
		printf("others");
	}
	else if(son>0){
		wait(NULL);
		printf("I am 2017304010413,son id: %d\n",son);
		sleep(10);
	}
}
