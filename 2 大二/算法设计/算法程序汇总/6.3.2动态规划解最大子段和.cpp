
#include<iostream>
using namespace std;
#include <algorithm>

int fun(int *a,int N)
{
     int max=0;
     int flag=0;
     for (int i=0;i<N;i++)
     {
        if(a[i]+flag>0)
            flag=a[i]+flag;
        else 
            flag=0;
        if(flag>max)
            max=flag;
     }
     return max;
}

int main()
{
	int x[7]={-2,2,3,-2,5,6,7};
	cout<<fun(x,7)<<endl;
  
	return 0;
}
 
