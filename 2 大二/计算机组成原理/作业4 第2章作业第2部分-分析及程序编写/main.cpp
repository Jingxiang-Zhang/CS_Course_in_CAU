#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef unsigned char* byte_poniter; 
void to_bites(byte_poniter start, int len){
	int i,j;
    for (i = len-1; i >= 0 ;i--){
    	printf("%x     ",&start[i]); 
        for (j = 7; j >= 0; j--)
            printf("%d", (start[i] >> j) & 0x1);
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    float x;
	int y;
	short s;
	cout<<"please input a float type number"<<endl; 
	cin>>x;	
    to_bites((byte_poniter)&x, sizeof(float));
    cout<<"please input a int type number"<<endl; 
    cin>>y;
    to_bites((byte_poniter)&y, sizeof(int));
    cout<<"please input a short type number"<<endl; 
    cin>>s;
    to_bites((byte_poniter)&s, sizeof(short));
    return 0;
}
