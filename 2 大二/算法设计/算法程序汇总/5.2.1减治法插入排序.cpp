
#include<iostream>
using namespace std;
#include <algorithm>

void InsertSort(int r[],int n) { //设置监视哨
	for(int i=2;i<=n;i++){
    //进行n-1次插入，依次插入r[2],r[3],…,r[n]
    	r[0]=r[i];        //r[0]是监视哨
    //顺序比较和移动，查找r[i]的插入位置
    	int j;
    	for(j=i-1;r[0]<r[j];j--) {   
      		r[j+1]=r[j]; //记录后移，继续向前搜索 
    	}
    	r[j+1]=r[0];   //插入r[i]
  }
}


int main()
{
	int x[11]={0,5,6,2,1,8,9,3,4,7,0};
	InsertSort(x,10);
	for(int i=1;i<=10;i++)
		cout<<x[i]<<" ";
	
  
	return 0;
}
 
