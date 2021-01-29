#include <iostream>
using namespace std; 
int main(int argc, char** argv) {
	int n;
	cout<<"请输入集合元素的个数：";
	cin>>n;
	int *set=new int[n];
	int i,j;
	cout<<"请分别输入这n个数：";
	for(i=0;i<n;i++)
		cin>>set[i];
	int maxtimes=0;
	int maxvalue=0;
	for(i=0;i<n;i++){
		int nowvalue=set[i];
		if(nowvalue==maxvalue) continue;
		int nowtimes=0;
		for(j=0;j<n;j++){
			if(set[j]==nowvalue){
				nowtimes++;
			}
		}
		if(nowtimes>maxtimes){
			maxtimes=nowtimes;
			maxvalue=nowvalue;
		}
		if(nowtimes==maxtimes){
			if(nowvalue<maxvalue)
				maxvalue=nowvalue;
		}
	}	
	cout<<"众数为："<<maxvalue;
	return 0;
}
