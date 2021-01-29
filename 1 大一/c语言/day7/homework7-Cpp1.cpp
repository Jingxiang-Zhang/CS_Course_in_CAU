//StudybarCommentBegin
#include <stdio.h>
int removeElement(int nums[],int numsSize,int val);
int main(void)
{
int n,m,val,a[1000];
int i;
scanf("%d%d",&n,&val);
for (i=0;i<n;i++) scanf("%d",&a[i]);
m=removeElement(a,n,val);
for (i=0;i<m;i++) printf("%d ",a[i]);
return 0;
}
//StudybarCommentEnd


int removeElement(int a[],int n,int val)
{
	int z[1000];
	int e,f,g;
	for(e=0,f=0;e<n;e++)
	{
		if(a[e]!=val) 
		{ z[f]=a[e];
		f=f+1;}
	}
	
	for(e=0;e<f;e++)
		a[e]=z[e];
	return(f);
}