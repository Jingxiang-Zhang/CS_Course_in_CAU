#include <iostream>
#include <math.h>
using namespace std; 
int main(int argc, char** argv) {
	int n,C;
	cout<<"请分别输入集合元素n的个数和C(注意，时间复杂度为2的n次方*n，所以n不宜过大)：";
	cin>>n>>C;
	int *set=new int[n];
	int i,j;
	cout<<"请分别输入这n个数：";
	for(i=0;i<n;i++)
		cin>>set[i];
	
	bool exist=false;
	int times=pow(2,n);
	cout<<"需要进行"<<times<<"次循环"<<endl;
	for(i=0;i<times;i++){   //这里生成一个从00...00到11...11的序列 
		int sum=0;
		int nowi=i;
		for(j=0;j<n;j++){
			if(nowi%2==1){				
				sum+=set[j];
			}
			nowi=nowi/2;
		}
		if(sum==C) {
			exist=true;
			break;
		}
	} 
	if(exist) cout<<"存在";
	else cout<<"不存在"; 
	
	 
	return 0;
}
