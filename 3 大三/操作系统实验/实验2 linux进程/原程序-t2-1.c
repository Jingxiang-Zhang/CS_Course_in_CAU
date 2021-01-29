#include<stdio.h>
int main(int argc, char *argv[])
{
	printf("there are total %d numbers, there are: \n",argc);
	int i;
	for(i=0;i<argc;i++)
	{
		printf("%s\n",argv[i]);
	}
	printf("I am son process,my id: %d, parent id: %d\n",getpid(),getppid());
}
