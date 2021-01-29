#include <stdio.h>
int main()
{
double a,b,c,d;
scanf("%lf %lf %lf",&a,&b,&c);
if(a>b && b>c) d=a;
if(a<b && b<c) d=c;
if(a>c && c>b) d=a;
if(b>a && a>c) d=b;
if(b>c && c>a) d=b;
if(c>a && a>b) d=c;
printf("%.2f",d);



return 0;
}
