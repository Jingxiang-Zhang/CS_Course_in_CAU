#include <stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d %d %d",&a,&b,&c);
	if(a%4==0 && a%100!=0)
		d=1;
	else if (a%400==0) 	
		d=1;
	else d=0;
	
	if(c>1)c=c-1;
	else if(c==1 && b==1) 
	{
		c=31;
		b=12;
		a=a-1;
	}
	else if(b==2){b=b-1;c=31;}
	else if(b==3 && d==1){b=2;c=29;}
	else if(b==3 && d==0){b=2;c=28;}
	else if(b==4){b=b-1;c=31;}
	else if(b==5){b=b-1;c=30;}
	else if(b==6){b=b-1;c=31;}
	else if(b==7){b=b-1;c=30;}
	else if(b==8){b=b-1;c=31;}
	else if(b==9){b=b-1;c=31;}
	else if(b==10){b=b-1;c=30;}
	else if(b==11){b=b-1;c=31;}
	else if(b==12){b=b-1;c=30;}
	printf("%d %d %d",a,b,c);

	

return 0;
}
