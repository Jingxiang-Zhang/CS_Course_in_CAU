#include <stdio.h>
int main()
{
	int a,b,c;
	scanf("%d",&a);
	if(a%4==0 && a%100!=0)
		printf("y");
	else if (a%400==0) 	
		printf("y");
	else printf("n");


 


return 0;
}