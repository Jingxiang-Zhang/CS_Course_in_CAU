#include <string.h>
#include <stdlib.h>
//StudybarCommentBegin
#include <iostream>
using namespace std;

bool color(int* u, int* v, int length);

int main()
{	
	char u_char[10000];
	char v_char[10000];
	int input_length;
	
	cin.getline(u_char, 10000);
	cin.getline(v_char, 10000);
	cin >> input_length;

	int u[1000];
	int v[1000];

	char* tmpStrX = strtok(u_char, " ");
	for (int i = 0; i < input_length; i++)
	{
		u[i] = atoi(tmpStrX);
		tmpStrX = strtok(NULL, " ");
	}

	char* tmpStrY = strtok(v_char, " ");
	for (int j = 0; j < input_length; j++)
	{
		v[j] = atoi(tmpStrY);
		tmpStrY = strtok(NULL, " ");
	}

	cout << color(u, v, input_length);
	return 0;
}
//StudybarCommentEnd
bool search(int *u,int *v,int length,int *color,int flag,int nowpoint){
	bool result=true;
	int ref=2;
	if(flag==2) ref=1;
	int i;
	for(i=0;i<length;i++){
		if(u[i]==nowpoint || v[i]==nowpoint){
			if(u[i]==nowpoint){
				int po=v[i];
				if(color[po]==0){
					color[po]=flag;
					result=search(u,v,length,color,ref,po);
				}
				else if(color[po]!=flag)
					result=false;
			}
			if(v[i]==nowpoint){
				int po=u[i];
				if(color[po]==0){
					color[po]=flag;
					result=search(u,v,length,color,ref,po);
				}
				else if(color[po]!=flag)
					result=false;
			}
		}
		if(result==false)
			return false;
	}
	return true;
}
bool color(int* u, int* v, int length){
	int *color=new int[length];
	int i,j;
	for(i=0;i<length;i++)
		color[i]=0;
	
	for(i=0;i<length;i++)
		if(color[i]==0)
			break;
	color[i]=1;
	int nowpoint=i;
	int flag=2;
	return search(u,v,length,color,flag,nowpoint);
	
} 
