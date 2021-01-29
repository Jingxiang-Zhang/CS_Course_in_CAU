int x[10];
//StudybarCommentBegin
#include<stdio.h>
int main()
{
	void in_num(int *x);
	void exchange(int *x);
	void out_num(int *x);
	int x[10];
	in_num(x);
	exchange(x);
	out_num(x);
	return 0;
}
//StudybarCommentEnd

void in_num(int *x)
{
	int a;
	for(a=0;a<10;a++)
		scanf("%d",&x[a]);
}
void exchange(int *x)
{
	int b,c,d,z,y;
	c=x[0];y=x[0];
	for(b=0;b<10;b++)
		if(x[b]<c) {c=x[b];d=b;}
    for(b=0;b<10;b++)
		if(x[b]>y) {y=x[b];z=b;}
	b=x[0];x[0]=x[d];x[d]=b;
	b=x[9];x[9]=x[z];x[z]=b;
}
void out_num(int *x)
{
	int a;
	for(a=0;a<10;a++)
	{printf("%d",x[a]);
	if(a!=9) printf(" ");}
}
