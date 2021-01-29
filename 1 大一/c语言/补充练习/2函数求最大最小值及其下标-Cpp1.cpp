#include<stdio.h>

void FindMaxMin(int num[], int n, int *pMax, int *pMaxPos, int *pMin, int *pMinPos) 
{
	int a,b,c,k,m;
	a=num[0];b=num[0];n=0;m=0;
	for(c=0;c<10;c++)
		if(num[c]>a) {a=num[c];k=c;}
	for(c=0;c<10;c++)
		if(num[c]<b) {b=num[c];m=c;}
    *pMax=a;*pMaxPos=k;
    *pMin=b;*pMinPos=m;
    


}

//StudybarCommentBegin
int main()
{
    int num[10];
    int max,maxPos,min,minPos;

    for( int i=0;i<10;i++)
        scanf("%d",&num[i]);

    FindMaxMin(num,10,&max,&maxPos,&min,&minPos);

    printf("Max = %d , Position = %d, Min = %d, Position = %d\n",max,maxPos,min,minPos);
    return 0;
}
//StudybarCommentEnd

