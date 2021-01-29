#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int jud(int a)
{
    int b,c,d,e,k;
    k=a;
	b=k%10;k=(k-b)/10;
	c=k%10;k=(k-c)/10;
	d=k;
	if(d==0) k=10*b+c;
	else 
	k=100*b+10*c+d;
	if(k==a) return(1);
	else return(0);	
} 
int judd(int a)
{
	int b,c,d;
	for(b=2;b<a;b++)
	if(a%b==0) break;
	if(b==a) return(1);
	else return(0);
}

int main(int argc, char *argv[]) {
	int a,b,c=0,d=0;
	for(a=1;a<=1000;a++)
	if(jud(a) && judd(a)) c++;
	for(a=1;a<=1000;a++)
	if(jud(a) && judd(a)) {printf("%d",a);d++;if(c!=d)printf(" ");}
	return 0;
}
