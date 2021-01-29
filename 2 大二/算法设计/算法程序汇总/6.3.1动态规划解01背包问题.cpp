
#include<iostream>
using namespace std;
#include <algorithm>
 
int main()
{
	int w[5] = { 0 , 2 , 3 , 4 , 5 };			//商品的体积2、3、4、5
	int v[5] = { 0 , 3 , 4 , 5 , 6 };			//商品的价值3、4、5、6
	int bagV = 8;					        //背包大小
	int dp[5][9] = { { 0 } };			        //动态规划表
 
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= bagV; j++) {
			if (j < w[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
 
	//动态规划表的输出
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	
	cout<<"\n物品列表："<<endl; 
	int x[100],j=8;
	for(int i=4;i>0;i--){
       if (dp[i][j]>dp[i-1][j]) {
        	x[i]=1;
        	j=j-w[i];
		}
		else 
			x[i]=0;
	}
	for(int i=1;i<=4;i++)
		cout<<x[i]<<" ";
	

 
	return 0;
}
 
