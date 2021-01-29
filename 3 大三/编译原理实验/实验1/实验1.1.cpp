//StudybarCommentBegin
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int *numbs;
int* QuickSort(int[10]);
int main()
{
	int test1[10]={5,8,12,33,24,3,7,6,18,2};
	int test2[10]={1,3,2,5,4,7,6,9,8,10};
	int test3[10]={12,23,32,15,4,2,9,8,3,5};
	int i;
	scanf("%d",&i);
	{
		switch(i)
		{
			case 1:numbs=test1;break;
			case 2:numbs=test2; break;
			case 3:numbs=test3; break;

		}
		int *SortedNums=QuickSort(numbs);
		int num_size=10;
		for (int i=0;i<num_size;i++)
            if(i<num_size-1)
                printf("%d,",SortedNums[i]);
            else
                printf("%d",SortedNums[i]);
	}
	return 0;
}
//StudybarCommentEnd


int Partition(int *r, int first, int end){
    int i=first; 
	int j=end;         //³õÊ¼»¯
    while (i<j){  
        while (i<j && r[i]<=r[j]) j--;
        if(i<j) { 
            int temp=r[i];
            r[i]=r[j];
            r[j]=temp;
            i++; 
        }
        while (i<j && r[i]<= r[j]) i++;
        if(i<j) {
            int temp=r[i];
            r[i]=r[j];
            r[j]=temp;            
			j--; 
        }
    }
    return i; 
}


void QuickSort2(int *lis,int first,int end){
	if(first<end){
		int pivot=Partition(lis,first,end);
		QuickSort2(lis,first,pivot);
		QuickSort2(lis,pivot+1,end);
	}
}
int* QuickSort(int *cont)
{
	QuickSort2(cont,0,9);
	return cont;
}


