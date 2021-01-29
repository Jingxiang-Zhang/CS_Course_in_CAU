#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main ()
{
	while(1)
	{
	int i,number;
	srand((unsigned)time(NULL));
	for(i=0;i<50;i++)
	{
		number=rand()%101;
		printf("%d",number);
	}
	continue;
	}
	return 0;
}