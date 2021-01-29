#include <iostream>
#include <string.h>
using namespace std;
 
void insert(char c1[],char c2[],char c,int i){
//将c 插入c1 并将c1复制到c2
	int j;
	for(j=0;j<i;j++)
		c2[j]=c1[j];
	c2[i]=c;
	for(j=i+1;j<=strlen(c1)+1;j++)
		c2[j]=c1[j-1];
}
void perml(int n){
//为生成排列集合元素的个数
	int i,j,k,m=1;
	char **c[2];//采用两个字符序列存储，分别存储i-1和i的全排列
	
	c[1]=new char*[1];
	c[1][0]=new char[2];
	c[1][0][0]='1'; 
	c[1][0][1]=0;
	
	for(i=2;i<=n;i++){
		m=m*(i-1);
		c[i%2]=new char*[m*i];
		for(j=0;j<m;j++){
			for(k=0;k<i;k++){
				c[i%2][j*i+k]=new char[i+1];
				insert(c[(i+1)%2][j],c[i%2][j*i+k],char(i+'0'),k);
			}
			delete[] c[(i+1)%2][j];
		}
		delete[] c[(i+1)%2];
	}
	for (i=0;i<m*n;i++){
		cout<<"第"<<i+1<<"排列："<<c[n%2][i]<<endl;
		delete[] c[n%2][i];
	}
}
/*
生成子集
    1．初始化一个长度为n的比特串s=00…0并将对应的子集输出；
    2．for (i=1; i<2n; i++)
          2.1  s++；
          2.2  将s对应的子集输出
*/
int main(int argc, char** argv) 
{
	perml(5);

	return 0;
}
