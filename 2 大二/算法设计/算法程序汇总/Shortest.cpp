#include<iostream>
using namespace std;
int step = 999;
void Path(int start,int now,int *arr,int size);
int main(){
	
	int size,i;
	cin>>size;
	int * arr = new int [size];
	for(i = 0; i < size ; i++){
		int num;
		cin>>num;
		arr[i] = num;
	}
	Path(0,0,arr,size);
	if(step == 0)cout<<-1;
	else cout<<step;
	return 0;
} 
void Path(int start,int now,int *arr,int size){
	//cout<<now;
	int i = start;
	if(start>=size-1){
		if(now<step)step = now;
		return;
	}
	if(arr[start] == 0){
		return;
	}
	int j = 1;
	while(j<=arr[i]){
		now++;
		Path(i+j,now,arr,size);
		now--;
		j++;
	}
	
}
