#include <string.h>
#include <stdlib.h>

//StudybarCommentBegin
#include <iostream>
#include<stdio.h>
using namespace std;

int maxValue(int w[], int v[], int length, int capacity);

int main()
{
	char w_char[10000];
	char v_char[10000];
	int length;
	cin.getline(w_char, 10000);
	cin.getline(v_char, 10000);
	cin >> length;

	int knapsack_capacity;
	cin >> knapsack_capacity;

	int w[1000];
	int v[1000];
	char* tmpStrX = strtok(w_char, " ");
	for (int i = 0; i < length; i++)
	{
		w[i] = atof(tmpStrX);
		tmpStrX = strtok(NULL, " ");
	}
	char* tmpStrY = strtok(v_char, " ");
	for (int j = 0; j < length; j++)
	{
		v[j] = atof(tmpStrY);
		tmpStrY = strtok(NULL, " ");
	}
	cout << maxValue(w, v, length, knapsack_capacity) << endl;
	return 0;
}
//StudybarCommentEnd

int maxV(int w[], int v[], int length, int capacity,int nowweight,int nowvalue){
	int all=w[length]+nowweight;
	if(length==0){
		if(all>capacity) return nowvalue;
		else return nowvalue+v[0];
	}
	int left=0;
	if(all<=capacity)
		left=maxV(w,v,length-1,capacity,all,nowvalue+v[length]);
	int right=maxV(w,v,length-1,capacity,nowweight,nowvalue);
	return right>left?right:left;
}
int maxValue(int w[], int v[], int length, int capacity){
	return maxV(w,v,length-1,capacity,0,0);
}
