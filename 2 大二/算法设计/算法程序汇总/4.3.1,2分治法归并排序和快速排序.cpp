#include <iostream>
#include <string.h>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int i, k;
    int *tmp = new int[high-low+1];
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;

    for(k=0; left_low<=left_high && right_low<=right_high; k++){  // 比较两个指针所指向的元素
        if(arr[left_low]<=arr[right_low]){
            tmp[k] = arr[left_low++];
        }else{
            tmp[k] = arr[right_low++];
        }
    }

    if(left_low <= left_high){  //若第一个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, arr+left_low, (left_high-left_low+l)*sizeof(int));
    for(i=left_low;i<=left_high;i++)
        tmp[k++] = arr[i];
    }
    
    if(right_low <= right_high){
    //若第二个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, arr+right_low, (right_high-right_low+1)*sizeof(int));
        for(i=right_low; i<=right_high; i++)
            tmp[k++] = arr[i];
    }

    for(i=0; i<high-low+1; i++)
        arr[low+i] = tmp[i];
    delete[] tmp;
    return;
}

void merge_sort(int arr[], unsigned int first, unsigned int last){
    int mid = 0;
    if(first<last){
        mid = (first+last)/2; /* 注意防止溢出 */
        /*mid = first/2 + last/2;*/
        //mid = (first & last) + ((first ^ last) >> 1);
        merge_sort(arr, first, mid);
        merge_sort(arr, mid+1,last);
        merge(arr,first,mid,last);
    }
    return;
}

void change(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int Partition(int r[ ], int first, int end){
    int i=first; 
	int j=end;         //初始化
    while (i<j){  
        while (i<j && r[i]<=r[j]) j--;  //右侧扫描
        if(i<j) { 
            change(&r[i],&r[j]);           //将较小记录交换到前面
            i++; 
        }
        while (i<j && r[i]<= r[j]) i++;  //左侧扫描
        if(i<j) {
            change(&r[i],&r[j]);            //将较大记录交换到后面
            j--; 
        }
    }
    return i;    // i为轴值记录的最终位置
}

void QuickSort(int r[ ], int first, int end){
     if (first<end) {      
        int pivot=Partition(r, first, end);  
          //问题分解，pivot是轴值在序列中的位置
        QuickSort(r, first, pivot-1); 
          //递归地对左侧子序列进行快速排序
        QuickSort(r, pivot+1, end);
         //递归地对右侧子序列进行快速排序
     }
  }

int main(int argc, char** argv) 
{
	int n[100]={5,4,8,1,6,3,2,9,7,0};
	int m[100];
	merge_sort(n,0,9);
	for(int i=0;i<10;i++)
		cout<<n[i]<<" ";
	cout<<endl; 
	
	int n2[100]={5,4,8,1,6,3,2,9,7,0};
	QuickSort(n2,0,9);
	for(int i=0;i<10;i++)
		cout<<n2[i]<<" ";
	cout<<endl;
	
	return 0;
}
