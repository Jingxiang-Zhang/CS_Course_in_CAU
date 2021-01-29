#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cmath>
using namespace std; 
int* create_data(int size){
	int *temp=new int[size];
	srand((int)time(0));
	for(int i=0;i<size;i++)
		temp[i]=rand()%1000;
	return temp;
}
int partition(int arr[], int left, int right){
    int i=left+1;
    int j=right;
    int temp=arr[left];
    while(i<=j){
        while(arr[i]<temp)
            i++;
        while(arr[j]>temp)
            j--;
        if(i<j)
            swap(arr[i++], arr[j--]);
        else i++;
    }
    swap(arr[j],arr[left]);
    return j;
}

void quick_sort(int arr[],int left,int right) {
    if (left>right)
        return;
    int j=partition(arr,left,right);
    quick_sort(arr,left,j-1);
    quick_sort(arr,j+1,right);
}
void show(int *data,int size){
	printf("This set of random data is:\n");
	int leng=int(sqrt(double(size)));
	printf("            ");
	for(int i=1;i<=leng;i++)
		printf("row:%2d  ",i);
	printf("\n");
	for(int i=0;i<size;){
		printf("line: %2d",(i+1)/leng+1);
		for(int j=0;j<leng&&i<size;i++,j++)
			printf("%8d",data[i]);
		printf("\n");
	}	 
} 
void seq_search(int *data,int size,int val){
	int i;
	for(i=0;i<size;i++)
		if(data[i]>=val)
			break;
	cout<<"times: "<<i<<endl;
 	if(data[i]!=val){
 		cout<<"no such an elment"<<endl;
 		return;
	} 
 	int leng=int(sqrt(double(size)));
	int line=(i+1)/leng;
	int row=i+1-line*leng;
	printf("the elment is in row:%2d, line:%2d",row,line+1);
}
int H_search(int *data,int begin,int end,int val){
	static int times=0;
	if(begin<=end){
		int mid=(end+begin)/2;
		times++;
		cout<<"search: "<<data[mid]<<endl;
		if(data[mid]==val) {
			cout<<"Eureka! total "<<times<<" times"<<endl;
			return mid;
		}
		int loc;
		if(data[mid]>val)
			loc=H_search(data,begin,mid-1,val);
		else
			loc=H_search(data,mid+1,end,val);
		if(loc==-1) return -1;
		return loc;
	}
	return -1;
}
void half_search(int *data,int size,int val){
 
	int loc=H_search(data,0,size-1,val);
	if(loc==-1){
		cout<<"no such an elment"<<endl;
		return;
	} 
	int leng=int(sqrt(double(size)));
	int line=(loc+1)/leng;
	int row=loc+1-line*leng;
	printf("the elment is in row:%2d, line:%2d",row,line+1);
}
int main(int argc, char** argv) {
	int *data;
	int size;
	cout<<"Please enter the size: ";
	cin>>size;
	data=create_data(size);
	quick_sort(data,0,size-1);
	show(data,size);
	cout<<endl<<endl;
	
	int val;
	cout<<"Please enter the element you want to find: ";
	cin>>val;
	cout<<"\n\nSequential search: \n";
	seq_search(data,size,val);
	cout<<"\n\n\nBinary search:\n";
	half_search(data,size,val);
	getchar(); 
	cout<<"\n\npress enter to exit";
	getchar(); 
	
	return 0;
}
