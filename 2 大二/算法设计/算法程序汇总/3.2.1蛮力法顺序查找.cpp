#include <iostream>
using namespace std;
 
int SeqSearch2(int r[ ], int n, int k)  //数组r[1] ~ r[n]存放查找集合
{   
    r[0]=k; 
	int i=n;
    while (r[i]!=k)
		i--;
    return i;
}

int main(int argc, char** argv) 
{
	int i,a[10];
	for(i=0;i<10;i++)
		a[i]=i;
	cout<<SeqSearch2(a,9,5);
	
	return 0;
}
