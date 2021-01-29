#include <stdio.h>
#include <stdlib.h>
#define row 2	
#define col 3 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int AddMatrix(int A[row][col],int B[row][col],int C[row][col])
{
	int x,y;
	for(x=0;x<2;x++)
	for(y=0;y<3;y++)
	C[x][y]=A[x][y]+B[x][y];
	return 0; 
}
int InputMatrix(int b[row][col])
{
	int x,y;
    for(x=0;x<2;x++)
	for(y=0;y<3;y++)
	scanf("%d",&b[x][y]);
	return 0;
}
void PrintfMatrix(int c[2][3])
{
	int x,y;
    for(x=0;x<2;x++)
	for(y=0;y<3;y++)
	{printf("%d",c[x][y]);
	if(y==0 || y==1)printf(" ");
	if(y==2) printf("\n");}	
}



//StudybarCommentBegin
int main()
{int a[row][col],b[row][col],c[row][col];
printf("input a:\n");
InputMatrix(a);
printf("input b:\n");
InputMatrix(b);
AddMatrix(a,b,c);
printf("result is:\n");
PrintfMatrix(c);
return 0;
}

//StudybarCommentEnd
