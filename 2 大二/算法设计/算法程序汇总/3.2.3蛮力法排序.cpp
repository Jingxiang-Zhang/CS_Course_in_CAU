#include <iostream>
using namespace std;
 
void SelectSort(int r[ ], int n){   
    for(int i=0;i<n;i++){  
        int index=i;
        for(int j=i+1;j<n;j++)
        	if(r[j]<r[index])
				index=j;
        if(index!=i){
        	int temp=r[i];
        	r[i]=r[index];
        	r[index]=temp;
		}
    }
}
void BubbleSort(int r[ ], int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1; j++)
    		if(r[j]>r[j+1]){
    			int temp=r[j];
    			r[j]=r[j+1];
    			r[j+1]=temp;
			}
}
void BubbleSort2(int r[ ], int n){
    int exchange=n-1;          //第一趟起泡排序的范围是r[1]到r[n]
    while (exchange!=-1){      //仅当上一趟排序有记录交换才进行本趟排序
        int bound=exchange;
		exchange=-1;  
        for(int j=0;j<bound;j++)          //一趟起泡排序
            if(r[j]>r[j+1]){
                int temp=r[j];
    			r[j]=r[j+1];
    			r[j+1]=temp;
                exchange=j;         //记录每一次发生记录交换的位置
            }
    }
}

int main(int argc, char** argv) 
{
	int n[10]={5,4,8,1,6,3,2,9,7,0};
	SelectSort(n,10);
	for(int i=0;i<10;i++)
		cout<<n[i]<<" ";
	cout<<endl; 
	
	int n2[10]={5,4,8,1,6,3,2,9,7,0};
	BubbleSort2(n2,10);
	for(int i=0;i<10;i++)
		cout<<n2[i]<<" ";
	cout<<endl; 
	return 0;
}
