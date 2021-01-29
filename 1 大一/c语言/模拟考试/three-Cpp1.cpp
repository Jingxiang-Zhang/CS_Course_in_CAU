 //StudybarCommentBegin
#include <stdio.h>
int removeElement(int nums[],int numsSize,int val);
int main(void){
int n,m,val,a[1000];
int i;
scanf("%d%d",&n,&val);
for (i=0;i<n;i++) scanf("%d",&a[i]);
m=removeElement(a,n,val);
for (i=0;i<m;i++) printf("%d ",a[i]);
return 0;
}
//StudybarCommentEnd
int removeElement(int nums[],int numsSize,int val)
{
	int a,b,c,t[1000];
	for(a=0,b=0;a<numsSize;a++)
	{
		if(nums[a]!=val)
		{
			t[b]=nums[a];
			b=b+1;
		}
	}
	for(c=0;c<b;c++) nums[c]=t[c];
	return(b);
}



	

 