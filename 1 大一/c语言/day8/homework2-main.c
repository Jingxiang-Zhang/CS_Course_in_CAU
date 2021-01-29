
//StudybarCommentBegin
#include <stdio.h>
struct student
{
    char name[10];
    int no;
    float score[2];
};
void maxscore(struct student *pst,int n);
void average(struct student *pst,int n);

//StudybarCommentEnd

int main()
{
	struct student stu[45];
	int n,a,b,c;
	scanf("%d",&n);
	for(a=0;a<n;a++)
	{
		scanf("%s",&stu[a].name);
		scanf("%d",&stu[a].no);
		scanf("%f%f",&stu[a].score[0],&stu[a].score[1]);
	}
	maxscore(student stu[45],n);
	average(student stu[45],n);
}
void maxscore(struct student *pst,int n)
{
	int a,b=1,c;
	double m;
	m=student[0].score[0];c=0;
	for(a=0;a<n;a++)
	if(student[a].score[0]>m){m=student[a].score[0];c=a;}
	for(a=0;a<n;a++)
	if(student[a].score[1]>m){m=student[a].score[1];c=a;b=2;}
    printf("MaxSore=%5.1f,Name is %s,No=%ld,Score.No=%d\n",m,student[c].name,student[c].no,student[c],b);
}







