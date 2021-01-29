#include <stdio.h>
int main()
{
	int a,b,c,feb,day;
	scanf("%d,%d,%d",&a,&b,&c);
	if(a%4==0 && a%100!=0)
		feb=29;
	else if (a%400==0) 	
		feb=29;
	else feb=28;
	if(b<1 || b>12 || c<1 || c>31)
	{	printf("data error.");return 0;}
	if(b==1) day=c;
	else if(b==2) day=31+c;
	else if(b==3) day=31+feb+c;
	else if(b==4) day=62+feb+c;
	else if(b==5) day=92+feb+c;
	else if(b==6) day=123+feb+c;
	else if(b==7) day=153+feb+c;
	else if(b==8) day=184+feb+c;
	else if(b==9) day=215+feb+c;
	else if(b==10) day=245+feb+c;
	else if(b==11) day=276+feb+c;
	else if(b==12) day=306+feb+c;
	printf("It is the %dth day.",day);


    return 0;
}


