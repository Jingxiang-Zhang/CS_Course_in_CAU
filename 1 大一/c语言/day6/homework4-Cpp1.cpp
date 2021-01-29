#include<stdio.h>
float average(float k[10])
{
	float b;
	int a;
	for(a=0,b=0;a<10;a++)
		b=b+k[a];
	b=b/10;
	return(b);
}



//StudybarCommentBegin
int main()
{
int i;
float score[10],aver;
for(i=0;i<10;i++)scanf("%f",&score[i]);
aver=average(score);
printf("average score is %5.2f",aver);
return 0;
}
//StudybarCommentEnd

