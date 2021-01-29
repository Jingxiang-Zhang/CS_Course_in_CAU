#include <string.h>
#include <stdlib.h>
//StudybarCommentBegin
#include <iostream>
using namespace std;

int BruteForce(int x[], int length);
int DivideConquer(int x[], int length);
int DynamicProgramming(int x[], int length);

int main()
{
	char x_char[10000];
	int length;
	int method_id;
	cin.getline(x_char, 10000);
	cin >> length;
	cin >> method_id;

	int x[1000];

	char* tmpStrX = strtok(x_char, " ");
	for (int i = 0; i < length; i++)
	{
		x[i] = atoi(tmpStrX);
		tmpStrX = strtok(NULL, " ");
	}

	int r = 0;
	switch (method_id)
	{
	case 1:
		r = BruteForce(x, length);
		break;
	case 2:
		r = DivideConquer(x, length);
		break;
	case 3:
		r = DynamicProgramming(x, length);
		break;
	default:
		break;
	}
	cout << r << endl;
	return 0;
}
//StudybarCommentEnd

int cal(int x[],int i,int j){
	int summ=0;
	for(int k=i;k<=j;k++)
		summ+=x[k];
	return summ;
}
int BruteForce(int x[], int length){
	int i,j;
	int maxvalue=0;
	for(i=0;i<length;i++)
		for(j=i;j<length;j++)
			if(cal(x,i,j)>maxvalue)
				maxvalue=cal(x,i,j);
	return maxvalue;
} 	
int Divide(int x[],int s,int e){
	if(s>=e) return 0;
	int leftmax,rightmax,middlemax;
	int mid=(s+e)/2;
	leftmax=Divide(x,s,mid);
	rightmax=Divide(x,mid+1,e);
	int middleleft=0,middleright=0;
	int i,summ=0;
	for(i=mid;i>=s;i--){
		summ+=x[i];
		if(summ>middleleft)	middleleft=summ;
	}
	summ=0;
	for(i=mid+1;i<=e;i++){
		summ+=x[i];
		if(summ>middleright) middleright=summ;
	}
	middlemax=middleleft+middleright;
	int tempmax=leftmax>rightmax?leftmax:rightmax;
	tempmax=tempmax>middlemax?tempmax:middlemax;
	return tempmax;
}
int DivideConquer(int x[], int length){
	return Divide(x,0,length-1);
}

int DynamicProgramming(int x[], int length){
	int **mapp=new int*[length];
	int i,j;
	for(i=0;i<length;i++)
		mapp[i]=new int[i+1];
	for(i=0;i<length;i++){
		mapp[i][i]=x[i];
	}
	for(i=1;i<length;i++){
		for(j=0;j<length-i;j++){
			int k=i+j;
			//mapp[k][j];
			int maxl=mapp[k-1][j];
			int maxr=mapp[k][j+1];
			int midd=cal(x,j,k);
			int temp=(maxl>maxr)?maxl:maxr;
			temp=temp>midd?temp:midd;
			mapp[k][j]=temp;
		}
	}
	return mapp[length-1][0];
}






