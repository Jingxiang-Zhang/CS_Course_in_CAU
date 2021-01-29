#include<vector>
#include<algorithm>
#include<iostream>
#include <time.h>

#define SORT_SET 1
//定义这个头文件的标识 
using namespace std;
struct vote{
	int number;
	int point;
}; 

/*
本来想用类去实现，但是后来发现如果使用类，没发用函数名作为参数进行传递参数
所以就把类取消了 。不过在这里可以看到所以的函数名 

class Sort{
	private:
		void merge(vote *result, int low, int mid, int high);
		void exchange(vote *a,vote *b);
		int Partition(vote *r,int first,int end);
		int max_digit(vote *result,int first,int end);
		void rectify_max_heap(vote *result,int start,int end); 
	public:		
		void bubble_sort(vote *result,int begin,int end);
		void merge_sort(vote *result,int first,int last);
		void bubble_sort2(vote *result,int begin,int end);
		void quickSort(vote *result,int first,int end);
		void select_sort(vote *result,int first,int end);
		void bucket_sort(vote *result,int first,int end);
		void counting_sort(vote *result,int first,int end);
		void base_sort(vote *result,int first,int end);
		void insert_sort(vote *result,int first,int end);
		void shell_sort(vote *result,int first,int end);
		void heap_sort(vote *result,int len);
}; 

*/
inline void exchange(vote *a,vote *b){
	/**************
		进行两个变量的交换 
	*/
	int temp=a->number;
	a->number=b->number;
	b->number=temp;
	temp=a->point;
	a->point=b->point;
	b->point=temp;
}

void shell_sort(vote *result,int first,int end) {
	/***************************************************************
		希尔排序：改进版的插入排序，希望尽量减少交换的次数和比
		较的次数。该算法为非稳定型的算法。设置一个增量序列，安
		装这个增量序列进行插入排序，然后再调整增量序列，相当于
		把原本为O(n2)复杂度的插入排序分解为若干个，每个都是O(m2)
		复杂度的小型的插入排序。无法计算时间复杂度，但是时间复杂
		度要大于O(nlogn)并小于O(n2)。	 
	****************************************************************/
    int increment=end-first+1; 
    int temp_point;
    int temp_number; 
    int i,j;
    do{
        increment=increment/3+1;
        for(i=first+increment;i<=end;++i){    //对每个划分进行直接插入排序
            if(result[i-increment].point>result[i].point){
                temp_point=result[i].point;
                temp_number=result[i].number;
                j=i-increment;
                do{  
                    result[j+increment].point=result[j].point;
                    result[j+increment].number=result[j].number;
                    j-=increment;
                }
				while(j>=first&&result[j].point>temp_point);
                result[j+increment].point=temp_point;  //插入元素
                result[j+increment].number=temp_number;
            }
        }
    }while(increment>1);
   	for(i=first;i<first+(end-first)/2;i++)
		exchange(&result[i],&result[end+first-i]);
}
 

void insert_sort(vote *result,int first,int end){
	/*************************************************************
		插入排序：数列的开头开始遍历，遍历到的位置之前都变为有
		序数列，之后每选中一个数字，就把该数字不断与之前的的数
		字进行交换，直达这个位置之前的数字再次的变为有序数列，
		时间复杂度为O(n2)	 
	*************************************************************/
	int i,j;
	for(int i=first+1;i<=end;i++){
		int temp_num=result[i].number;
		int temp_point=result[i].point;
		for(j=i-1;j>=first;j--){
			if(result[j].point<temp_point){
				result[j+1].point=result[j].point;
				result[j+1].number=result[j].number;
			}
			else break;
		}
		result[j+1].point=temp_point;
		result[j+1].number=temp_num;
	}

}

int max_digit(vote *result,int first,int end){
	//用于获取最大数字的最大位数 
	int max_num=0;
	int i,j;
	for(i=first;i<=end;i++){
		int count=1;
		int tem=result[i].point;
		while(tem/10!=0){
			tem=tem/10;
			count++;
		}
		if(count>max_num)
			max_num=count;//把最大位数赋值max
	}
	return max_num;
}
void base_sort(vote *result,int first,int end){
	/*************************************************************
		基数排序：设待排序列为n个记录，d个关键码，关键码的取值
		范围为radix，则时间复杂度为O(d(n+radix))。原理为，一般
		关键码为10，对于十进制的数，每次取出一位，将所有的数根
		据这一位进行排序，然后合并为一个数列。再取下一个位对这
		个数列进行重新的排序，一共进行d次，d为这列数最大数的位数。
	*************************************************************/
	int maxx=max_digit(result,first,end); 
	int num=1;
	int i,j,k;
	for(i=0;i<maxx;i++){ 
		int count[10];
		int *temp_num[10];
		int *temp_point[10];
		for(j=0;j<10;j++){
			count[j]=0;
			temp_num[j]=new int[end-first+1];
			temp_point[j]=new int[end-first+1];
			for(k=0;k<end-first+1;k++){
				temp_num[j][k]=0;
				temp_point[j][k]=0;
			}
		}
		for(j=first;j<=end;j++){
			k=result[j].point/num;
			k=k%10;
			count[k]++;
			int te=count[k]-1;
			temp_point[k][te]=result[j].point;
			temp_num[k][te]=result[j].number;
		}
		int locate=0;
		for(j=0;j<10;j++){
			for(k=0;k<count[j];k++){ 
				result[locate].number=temp_num[j][k];
				result[locate].point=temp_point[j][k];
				locate++;
			}
		}
		num=num*10;
	}
	for(i=first;i<first+(end-first)/2;i++)
		exchange(&result[i],&result[end+first-i]);
	
}

 
void counting_sort(vote *result,int first,int end){
	/*************************************************************
		计数排序：假设整个数列的最大值和最小值分别是max和min，
		开辟一个大小为max-min的数组空间，遍历一遍待排序数列，
		将每个数对应下标位置的数组+1，最后从大到小遍历一遍新
		开辟的数组，输出对应位置的数字出现次数次的标号+min即
		可。时间复杂度为O(n)，空间复杂度为O(max-min)。
	*************************************************************/
	int max_num=0;
	int min_num=100000;
	int i,j,k;
	for(i=first;i<=end;i++){
		if(max_num<result[i].point)
			max_num=result[i].point;
		if(min_num>result[i].point)
			min_num=result[i].point;
	}
	int *space=new int[max_num-min_num+1];
	vector<int> *num=new vector<int>[max_num-min_num+1];
	
	for(i=0;i<max_num-min_num+1;i++){
		space[i]=0;
	}
	for(i=first;i<=end;i++){
		space[result[i].point-min_num]++;
		num[result[i].point-min_num].push_back(result[i].number);
	}
	int locate=first;
	for(i=max_num-min_num+1-1;i>=0;i--){
		for(j=0;j<space[i];j++){
			result[locate].point=i+min_num;
			result[locate].number=num[i][j];
			locate++;
		}
	}
}
 
void bucket_sort(vote *result,int first,int end){
	/*************************************************************
		木桶排序：将n个数除以区间大小分成k个组，假设平均每组m
		个数，每个组内进行排序，根据时间复杂度不同可能为O(m2)
		或O(mlogm)，最后按照大小顺序进行输出。
	*************************************************************/
	int max_num=0;
	int min_num=100000;
	int i,j,k;
	for(i=first;i<=end;i++){
		if(max_num<result[i].point)
			max_num=result[i].point;
		if(min_num>result[i].point)
			min_num=result[i].point;
	}
	int part=(max_num-min_num)/10+1;
	vector<vote> res[10];
	for(i=first;i<=end;i++){
		int index=result[i].point;
		index=(index-min_num)/part;
		res[index].push_back(result[i]);
	}
	for(i=0;i<10;i++){
		for(j=0;j<int(res[i].size())-1;j++){
			for(k=0;k<int(res[i].size())-1-j;k++){
				if(res[i][k].point<res[i][k+1].point){
					int temp=res[i][k].point;
					res[i][k].point=res[i][k+1].point;
					res[i][k+1].point=temp;
					temp=res[i][k].number;
					res[i][k].number=res[i][k+1].number;
					res[i][k+1].number=temp;
				}
			}	
		}
		
	}
	int locate=first;
	for(i=9;i>=0;i--){
		for(j=0;j<res[i].size();j++){
			result[locate]=res[i][j];
			locate++;
		}
	}
}
void select_sort(vote *result,int first,int end){
	/*************************************************************
		选择排序：时间复杂度为O(n2)，每次进行选出剩余数据中最
		大的，并把这个数与第一个数进行交换。
	*************************************************************/
    int i;
    for(i=first;i<end;i++){
        int j=i;
        int min_index=i;
        for(j=i+1;j<=end;j++){
            if(result[j].point>result[min_index].point){
                min_index=j;
            }
        }
        if(min_index!=i){
            exchange(&result[i],&result[min_index]);  
        }
    }
}

int Partition(vote *result,int first,int end){
	//用于快速排序的分割 
    int i=first; 
	int j=end;  
    while(i<j){  
        while (i<j&&result[i].point>=result[j].point)j--; 
        if(i<j){ 
            exchange(&result[i],&result[j]);           
            i++; 
        }
        while(i<j&&result[i].point>=result[j].point)i++;  
        if(i<j){
            exchange(&result[i],&result[j]);            
            j--; 
        }
    }
    return i;    
}

void quickSort(vote *result,int first,int end){
	/*************************************************************
		快速排序：最经典的排序算法之一，随机选择一个标志，将整
		个数组分开，使比其大的在其右边，比其小的在其左边。再递
		归左右两个子数组。时间复杂度为O(nlogn)。
	*************************************************************/
     if(first<end){      
        int pivot=Partition(result,first,end);  
        quickSort(result,first,pivot-1); 
        quickSort(result,pivot+1,end);
     }
  }

void bubble_sort(vote *result,int begin,int end){
	/*************************************************************
		进行两次遍历，每次两两比较进行交换，时间复杂度为O(n2)。
	*************************************************************/
	for(int i=begin;i<end;i++)
		for(int j=begin;j<end-i;j++){
			if(result[j].point<result[j+1].point){
				exchange(&result[j],&result[j+1]);
			}
		}
}
void bubble_sort2(vote *result,int begin,int end){
	/*************************************************************
		优化版冒泡排序：在冒泡排序的基础上，设置标志位，每次比
		较之后进行判断，如果不需要交换则直接进行下一次的循环，
		理论时间复杂度小于O(n2)，由于每次循环多了一次判断，效率
		反而低于普通版冒泡排序。
	*************************************************************/
    int exchange_=end;          //第一趟起泡排序的范围是r[1]到r[n]
    while (exchange_!=-1){      //仅当上一趟排序有记录交换才进行本趟排序
        int bound=exchange_;
		exchange_=-1;  
        for(int j=begin;j<bound;j++)          //一趟起泡排序
            if(result[j].point<result[j+1].point){
                exchange(&result[j],&result[j+1]);
                exchange_=j;         //记录每一次发生记录交换的位置
            }
    }
}

void merge(vote *result, int low, int mid, int high){
	//用于归并排序后的合并 
    int i, k;
    vote *temp=new vote[high-low+1];
    int left_low=low;
    int left_high=mid;
    int right_low=mid+1;
    int right_high=high;

    for(k=0; left_low<=left_high && right_low<=right_high; k++){  
        if(result[left_low].point>=result[right_low].point){
        	temp[k].number=result[left_low].number ;
            temp[k].point=result[left_low].point ;
            left_low++;
        }
		else{
			temp[k].point=result[right_low].point;
            temp[k].number=result[right_low].number;
            right_low++;
        }
    }

    if(left_low<=left_high){  
	    for(i=left_low;i<=left_high;i++){
	    	temp[k].point=result[i].point;
            temp[k].number=result[i].number;
            k++;
		}
    }
    
    if(right_low <= right_high){
        for(i=right_low;i<=right_high;i++){
        	temp[k].point=result[i].point;
            temp[k].number=result[i].number;
            k++;
		}
    }

    for(i=0; i<high-low+1; i++){
    	result[low+i].point=temp[i].point;
    	result[low+i].number=temp[i].number;
	}
        
    delete[] temp;
    return;
}


void merge_sort(vote *result,int first,int last){
	/*************************************************************
	 	归并排序:采用分治的思想，将待排序数组反复一分为二，直
		 至最后剩两个数可以直接交换得到，再依次合并得到已排序
		 数组。时间复杂度为O(nlogn)，需要O(n)的空间开销。
	*************************************************************/
    int mid = 0;
    if(first<last){
        mid = (first+last)/2; 
        merge_sort(result, first, mid);
        merge_sort(result, mid+1,last);
        merge(result,first,mid,last);
    }
    return;
}

void rectify_max_heap(vote *result,int start,int end){  
	int dad = start;
	int son = 2*dad+1;
	//一直筛选到最下层 
	while(son<=end){
		if(son+1<=end&&result[son].point<result[son+1].point){
			son++;
		}
		if(result[dad].point<result[son].point){
			swap(result[son],result[dad]);
			dad = son;
			son = 2*dad+1;
		}
		else{
			return ;
		}
	}
} 

void heap_sort(vote *result,int begin,int end){
	/*************************************************************
		以O(logn)的时间复杂度建堆，以O(logn)的时间复杂对维护一
		次堆，需要维护n次，故时间复杂度为O(nlogn)。在一些维护代
		价较小的场合使用较多。
	*************************************************************/
	//建堆 
	int i;
	for(i=(end+1-begin)/2-1;i>-1;i--){
		rectify_max_heap(result,i,end-begin);
	}
	//取堆顶，即最大值与堆尾交换，维护堆 
	for(i=(end-begin);i>0;i--){
		swap(result[0],result[i]);
		rectify_max_heap(result,0,i-1);
	}	
	for(i=begin;i<begin+(begin-end)/2;i++)
		exchange(&result[i],&result[end+begin-i]);
} 
 

void ssort(vote *result,int begin,int end){
	/**************
	这种算法类似于stl中的排序算法，首先判断，如果数据的范围小则调用计数排序
	否则随机取一种排序算法 
	*/
	int i;
	int minn=100000;
	int maxx=-100000;
	for(i=begin;i<=end;i++){
		if(result[i].point>maxx)
			maxx=result[i].point;
		if(result[i].point<minn)
			minn=result[i].point;
	}	
	if(maxx-minn<=200000)
		counting_sort(result,begin,end);
	else{
		srand((unsigned)time(NULL));
		int num=rand()%5;
		switch(num){
			case 0:
				merge_sort(result,begin,end);
				break;
			case 1:
				quickSort(result,begin,end);
				break;
			case 2:
				shell_sort(result,begin,end);
				break;
			case 3:
				heap_sort(result,begin,end);
				break;
			case 4:
				base_sort(result,begin,end);
				break;
		}
	}
}
 
