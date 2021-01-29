#include <iostream>
using namespace std;
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double a,b,c,d,e,f;
	double der,m,n;   //der 为判别表达式，m为根号下的实数，n为虚数 
	double x,y,t;     //x,y为开根号后的值 
	double ch1,ch2,ch3,ch4,che;
	double x2,x3,y2,y3;
	cin>>a>>b>>c>>d>>e>>f;
	m=c*c-d*d-4*a*e+4*b*f;
	n=2*c*d-4*b*e-4*a*f; 
	t=(sqrt(m*m+n*n)+m)/2;
	x=sqrt(t);
	t=(sqrt(m*m+n*n)-m)/2;
	y=-sqrt(t);
	x2=x-c;y2=y-d;   //以下为除法
	x3=-x-c;y3=-y-d;
	a=a*2;b=b*2;
	
	ch1=(x2*a+b*y2)/(a*a+b*b);
	ch2=(a*y2-b*x2)/(a*a+b*b);  //第一个的虚数部分 
	ch3=(x3*a+b*y3)/(a*a+b*b);
	ch4=(a*y3-b*x3)/(a*a+b*b);  //第二个的虚数部分 
	 
	if(ch4>0 && ch2<0) {che=ch1;ch1=ch3;ch3=che;che=ch2;ch2=ch4;ch4=che;	}                                                                       if(e==0) {ch2=1;ch4=0;}

	if(ch2>=0){printf("(%.2f+%.2fi)\n",ch1,ch2);}
	else  printf("(%.2f%.2fi)\n",ch1,ch2);
	if(ch4>=0){printf("(%.2f+%.2fi)\n",ch3,ch4);}
	else  printf("(%.2f%.2fi)\n",ch3,ch4);	
	
	
	
	return 0;
}
