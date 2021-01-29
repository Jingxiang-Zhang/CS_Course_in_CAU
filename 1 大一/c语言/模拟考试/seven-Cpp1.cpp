#include<stdio.h>
int judge(int a)
{
	int x;
	for(x=2;x<a;x++)	if(a%x==0) break;
	if(x==a)return(1);
	else return(0);
}
int reverse(int a)
{
	int x,y,z,t;
	x=a%10;
	a=(a-x)/10;
	y=a%10;
	a=(a-y)/10;
	z=a;
    t=100*x+10*y+z;
	return(t);
}

int main()
{
	int a,b,c=0;
	int x[30],t=0;
 	   for(t=0;t<30;t++) x[t]=0;
	   t=0;  

	   for (a=100;a<=1000;a++)
	   {
	   b=reverse(a);
	   if(judge(a)==1 && judge(b)==1 && b!=x[0]&& b!=x[1]&& b!=x[2]&& b!=x[3]&& b!=x[4]&& b!=x[5]&& b!=x[6]&& b!=x[7]&& b!=x[8]&& b!=x[9]
		   && b!=x[10]&& b!=x[11]&& b!=x[12]&& b!=x[13]&& b!=x[14]&& b!=x[15]&& b!=x[16]&& b!=x[17]&& b!=x[18]&& b!=x[19]
		   && b!=x[20]&& b!=x[21]&& b!=x[22]&& b!=x[23]&& b!=x[24]&& b!=x[25]&& b!=x[26]&& b!=x[27]&& b!=x[28]&& b!=x[29])
	   { 
	   printf("%d,%d\n",a,b) ;
	   c++;
	   x[t]=a;
	   t++;
	   }
   }
   printf("count=%d",c);
 
}