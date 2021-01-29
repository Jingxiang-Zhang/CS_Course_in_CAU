#include<stdio.h>
int main()
{
	int son=fork();
	if(son<0)
		printf("Creat son error!\n");
	if(son==0){
		printf("I am son process,my id: %d, parent id: %d\n",getpid(),getppid());
		int grandson=fork();
		if(grandson==0){
               		printf("I am grandson,id: %d, parent id: %d\n",getpid(),getppid());
		}
		else if(grandson>0){
               		printf("this is son process\n");
		}
		else{
			printf("Creat grandson error!\n");
		}
	}
	else if(son>0){
		wait(NULL);
		printf("I am 2017304010413,son id: %d\n",son);
		sleep(10);
	}
}
