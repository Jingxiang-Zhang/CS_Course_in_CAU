#include <stdio.h>
#include <stdlib.h>
#define row 2	
#define col 3 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void MultiplyMatrix(int a[row][col],int b[col][row],int c[row][row])
{
    c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0]+a[0][2]*b[2][0];
    c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1]+a[0][2]*b[2][1];
    c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0]+a[1][2]*b[2][0];
    c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1]+a[1][2]*b[2][1];
		
}
void InputMatrix1(int a[row][col])
{
	int x,y;
    for(x=0;x<2;x++)
	for(y=0;y<3;y++)
	scanf("%d",&a[x][y]);

}
void InputMatrix2(int b[col][row])
{
	int x,y;
    for(x=0;x<3;x++)
	for(y=0;y<2;y++)
	scanf("%d",&b[x][y]);

}
void PrintfMatrix(int c[2][2])
{
	int x,y;
    for(x=0;x<2;x++)
	for(y=0;y<2;y++)
	{printf("%d",c[x][y]);
	if(y==0)printf(" ");
	if(y==1) printf("\n");}	
}

	
//StudybarCommentBegin
int main()
{
int a[row][col],b[col][row],c[row][row],i,j;
printf("input a:\n");
InputMatrix1(a);
printf("input b:\n");
InputMatrix2(b);
MultiplyMatrix(a,b,c);
printf("result is :\n");
PrintfMatrix(c);
return 0;
}
//StudybarCommentEnd

