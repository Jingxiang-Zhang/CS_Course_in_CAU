#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std; 
int main()
{
	int i,j,k,min,brief,n;
	int D[20][20];
	cout<<"顶点个数：";
	cin>>n;
	int b=(int)pow(2,n-1);
  	for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
      		cin>>D[i][j];
  	int ** Route = (int **)calloc(n, sizeof(int *));
  	int ** Mat = (int **)calloc(n, sizeof(int *));
  	for(i=0;i<n;i++)
  	{
    	Route[i] = (int *)calloc(b*b, sizeof(int))+i*b;
    	Mat[i] = (int *)calloc(b*b, sizeof(int))+i*b;
  	}
  	for(i=0;i<b;i++)
   		for(j=0;j<n;j++)
	    {
			Route[j][i] = -1;
   			Mat[j][i] = -1;
	    }
  	for(i=0;i<n;i++)//初始化第0列 
    	Route[i][0] = D[i][0];    
  	for(i=1;i<b-1;i++)
	    for(j=1;j<n;j++)//依次进行第i次迭代 
			if( ((int)pow(2,j-1) & i) == 0)//子集V[j不包含i 
			{
				min=999;
				for(k=1;k<n;k++)
				if( (int)pow(2,k-1) & i )
				{
					brief = D[j][k] + Route[k][i-(int)pow(2,k-1)]; 
					if(brief < min)
					{
						min = brief;
						Route[j][i] = min;
						Mat[j][i] = k;//局部最优决策
					}
				}    
			}
	min=999;
  	for(k=1;k<n;k++)
	{
		brief = D[0][k] + Route[k][b-1 - (int)pow(2,k-1)];
		if(brief < min)
		{
			min = brief;
			Route[0][b-1] = min;//最优解
			Mat[0][b-1] = k;
		}
	}
	cout<<"最短路径长度："<<Route[0][b-1]<<endl;//最短路径长度
	cout<<"最短路径："<<"1";
	for(i=b-1,j=0; i>0; )
	{
		j = Mat[j][i];
		i = i - (int)pow(2,j-1);
		cout<<"->"<<j+1;
	}
	cout<<"->1"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<b;j++)
  			cout<<Route[i][j]<<" ";
		cout<<endl;
	}
	free(Route);
	free(Mat);
	return 0;
}
 
