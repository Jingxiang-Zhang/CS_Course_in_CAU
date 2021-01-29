#include<stdio.h>
int main()
{
	int i;
	for(i=0;i<2;i++)
	{
		int forknum=fork();
		if(forknum)
		{
			printf("_process id:%d created by:%d\n",getpid(),getppid());
		}
		else
		{
			printf("_process id:%d created by:%d\n",getpid(),getppid());
		}

	}
	wait(NULL);
	wait(NULL);
	return 0;
}
