#include <iostream>
#include <fstream> 
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

void QuickSort(int *lis,int first,int end);
int *copydata(int *data,int length);
void showdata(int *data,int length);
bool checkResult(int *data,int length);


int main(int argc, char** argv) {
	//参数设定 
	char filename[]="data.txt";
	int datalength=100000;
	//读入文件 
	ifstream datafile(filename);
	clock_t startTime,endTime;
	int *data=new int[datalength];
	char c;
	for(int i=0;i<datalength;i++){
		datafile>>data[i];
		datafile>>c; 
	}	
	datafile.close();
	
	
	//快速排序 
	cout<<endl<<endl<<"下面开始快速排序"<<endl;	
	int *copy=copydata(data,datalength);
	startTime = clock();
	QuickSort(copy,0,datalength-1);
	endTime = clock();
	cout<<"排序的时间为："<<(double)(endTime - startTime)/1000 <<"s"<<endl;
	bool result=checkResult(copy,datalength);
	cout<<"数组长度为："<<datalength<<"。排序结果为：";
	showdata(copy,datalength);
	if(result){
		cout<<"经检验，排序结果正确"<<endl; 
	}
	delete copy;
	
	//标准模板库排序 
	cout<<endl<<endl<<"下面开始模板库排序"<<endl;
	copy=copydata(data,datalength);
	
	startTime = clock();
	sort(copy,copy+datalength);
	endTime = clock();
	
	cout<<"排序的时间为："<<(double)(endTime - startTime)/1000 <<"s"<<endl;
	result=checkResult(copy,datalength);
	cout<<"数组长度为："<<datalength<<"。排序结果为：";
	showdata(copy,datalength);
	if(result){
		cout<<"经检验，排序结果正确"<<endl; 
	}
	return 0;
}

void showdata(int *data,int length){
	for(int i=0;i<4;i++)
		cout<<data[i]<<",";
	cout<<"  ....  ";
	for(int i=length-5;i<length;i++){
		cout<<data[i];
		if(i!=length-1)
			cout<<",";
		else cout<<endl; 
	}
	
}

bool checkResult(int *data,int length){
	for(int i=0;i<length-1;i++){
		if(data[i]>data[i+1])
			return false;
	}
	return true;
}

int *copydata(int *data,int length){
	int *copy=new int[length];
	for(int i=0;i<length;i++){
		copy[i]=data[i];
	}
	return copy;
}

int Partition(int *r, int first, int end){
    int i=first; 
	int j=end;         //初始化
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

void QuickSort(int *lis,int first,int end){
	if(first<end){
		int pivot=Partition(lis,first,end);
		QuickSort(lis,first,pivot);
		QuickSort(lis,pivot+1,end);
	}
}


