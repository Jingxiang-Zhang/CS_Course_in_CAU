#include <iostream>
#include <string.h>
using namespace std;

int Divide(int x[],int s,int e){
	if(s>=e) return 0;
	int leftmax,rightmax,middlemax;
	int mid=(s+e)/2;
	leftmax=Divide(x,s,mid);
	rightmax=Divide(x,mid+1,e);
	int middleleft=0,middleright=0;
	int i,summ=0;
	for(i=mid;i>=s;i--){
		summ+=x[i];
		if(summ>middleleft)	middleleft=summ;
	}
	summ=0;
	for(i=mid+1;i<=e;i++){
		summ+=x[i];
		if(summ>middleright) middleright=summ;
	}
	middlemax=middleleft+middleright;
	int tempmax=leftmax>rightmax?leftmax:rightmax;
	tempmax=tempmax>middlemax?tempmax:middlemax;
	return tempmax;
}

int main(int argc, char** argv) 
{
	int n[100]={5,4,8,1,6,3,2,9,7,0};
	cout<<Divide(n,0,9);
	
 	
	
	return 0;
}
