#include <iostream>
#include <math.h>
using namespace std; 
int main(int argc, char** argv) {
	int n;
	double C;
	cout<<"该程序以1作为位置的起点，可以为浮点数\n"; 
	cout<<"请分别输入数组元素n的个数和待查找的数字C：";
	cin>>n>>C;
	double *set=new double[n];
	int i,j;
	cout<<"请分别输入这n个数(升序：从小到大)：";
	for(i=0;i<n;i++)
		cin>>set[i];
		
	for(i=0;i<n;i++){
		if(C<=set[i]) break;
	}
	if(C==set[i]){
		//此时找到C元素了
		cout<<"元素C的位置是："<<i+1; 
	}
	else if(i==0){
		cout<<"C小于所有的元素，因此大于x的最小元素位置为"<<1;
	}
	else if(i==n){
		cout<<"C大于所有的元素，因此小于x的最大元素位置为"<<n;
	}
	else{
		cout<<"C介于第"<<i<<"和第"<<i+1<<"号元素之间"; 
	}
	
	 
	return 0;
}
