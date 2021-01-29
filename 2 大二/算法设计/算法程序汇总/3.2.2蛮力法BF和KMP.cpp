#include <iostream>
using namespace std;
 
int BF(char S[ ], char T[ ]){
    int i=1; 
	int j=1;   
    while (i<=S[0] &&i+T[0]<= S[0] && j<=T[0]) {
    //	cout<<char(S[i])<<" "<<char(T[j])<<endl;
        if (S[i]==T[j]){
		 	i++;
			j++;
		}  
        else{
			i=i-j+2;
			j=1;
		}   
    }
    if (j>T[0]) 
		return (i-j+1);   
    else 
		return -1;
}
void GetNext(char T[ ], int next[ ]){
   next[1]=0;
   int j=1; 
   int k=0;
   while (j<T[0])//0位存放数组长度
        if ((k==0)||(T[j]==T[k])) {
        	j++;
        	k++;
        	next[j]=k;
     	}
     	else 
			k=next[k];
}
int KMP(char* s, char* p)  
{  
	int next[100];
	GetNext(p,next);
    int i=1;  
    int j=1;  
    int sLen=s[0];  
    int pLen=p[0];  
    while (i<=sLen && j<=pLen){  
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
        if(j==0 || s[i]==p[j])  {  
            i++;  
            j++;  
        }
        else
            j=next[j];  
    }
    if (j>pLen)  
        return i-j+1;  
    else  
        return -1;  
}  
int main(int argc, char** argv) 
{
	char c[20]="0abcdefghi";
	char m[20]="0cde";
	c[0]=10;
	m[0]=3;
	cout<<BF(c,m)<<endl;
	cout<<KMP(c,m)<<endl;
	return 0;
}
