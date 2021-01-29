#include<iostream>
using namespace std;
int MAX = 0;
int len,cap;
void maxValue(int start,int w[], int v[], int nw, int nv);
int main(){
	
	int capacity,size,i;
	
	cin>>size;
	cin>>capacity;
	len = size;
	cap = capacity;
	
	int *w = new int[size];
	int *v = new int[size];
	
	for(i=0;i<size;i++){
		int W;
		cin>>W;
		w[i] = W;
	}
	for(i=0;i<size;i++){
		int V;
		cin>>V;
		v[i] = V;
	}
	maxValue(0,w,v,0,0);
	cout<<MAX; 
	return 0;
} 
void maxValue(int start,int w[], int v[], int nw, int nv){
	if(nw>cap){
		return;
	}
		if(start==len){
		if(nv>MAX)MAX=nv;
		return;
	}
	nw+=w[start];
	nv+=v[start];
	maxValue(++start,w,v,nw,nv);
	nw-=w[start-1];
	nv-=v[start-1];
	maxValue(start,w,v,nw,nv);
}

