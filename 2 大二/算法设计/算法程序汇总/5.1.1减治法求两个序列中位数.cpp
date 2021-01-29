
#include<iostream>
using namespace std;
#include <algorithm>

int MidNum(int a[],int b[],int n){
    int s1,e1,s2,e2,mid1,mid2;
    s1=0;
	s2=0;
	e1=n-1;
	e2=n-1;
    while(s1<e1 && s2<e2){
        mid1 = (s1+e1)/2;
        mid2 = (s2+e2)/2;
        if(a[mid1] == b[mid2])
            return a[mid1];
        if(a[mid1] < b[mid2]){
            if((s1+e1)%2 == 0)
                s1 = mid1;
            else
                s1 = mid1+1;
            e2 = mid2;
        }
        else
        {
            if((s2+e2)%2 == 0)
                s2 = mid2;
            else
                s2 = mid2+1;
            e1 = mid1;
        }

    }
    if(a[s1] < b[s2])
        return a[s1];
    else
        return b[s2];

}

int main()
{
	int x[5]={11,13,15,17,19};
	int y[5]={2,4,10,15,20};
	
	cout<<MidNum(x,y,5)<<endl;
  
	return 0;
}
 
