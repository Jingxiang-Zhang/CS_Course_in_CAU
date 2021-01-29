//StudybarCommentBegin
#include <iostream>
#include<vector>
using namespace std;

bool chess[8][8] = {
	{0,0,0,0,0,0,0,0},		
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
};

void Queen();
void show();
int main()
{
	Queen();
	vector<int> x;
	vector<int> y;
	for (int m = 0; m < 8; m++)
	{
		for (int n = 0; n < 8; n++)
		{
			if (chess[m][n])
			{
				x.push_back(m);
				y.push_back(n);
			}
		}
	}

	if (x.size() != 8 || y.size() != 8)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < x.size()-1; i++)
	{
		for (int j = i+1; j < x.size(); j++)
		{
			if (x[i] == x[j] || y[i] == y[j] || x[i] - x[j] == y[i] - y[j] || x[i] - x[j] == y[j] - y[i])
			{
				cout << 0 << endl;
				return 0;
			}
		}
	}
	
	cout << 1 << endl;
	return 0;
}

//StudybarCommentEnd
#include<ctime>
#include<stdlib.h>
#include<math.h>
bool jud(int r,int loc){
	int result=true;
	for(int i=0;i<r;i++){
		if(chess[i][loc]==1) result=false;
		if(r-i+loc<8)
			if(chess[i][r-i+loc]==1) result=false;
		if(loc-(r-i)>=0)
			if(chess[i][loc-(r-i)]==1) result=false;
		if(!result)
			return false;
	}
	return true;
}
void show(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++)
			cout<<chess[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
void clear(){
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			chess[i][j]=0;
}
void Queen(){//chess
	bool flag=false;
	srand(time(0));
	while(true){

	
		int loc=rand()%8;
		chess[0][loc]=1;
		int loc2=rand()%8;
		while(loc==loc2 || abs(loc2-loc)==1){
			loc2=rand()%8;
		}
		chess[1][loc2]=1;
	
		
		int i=2;
		while(true){
			int j;
			int loc;
			for(loc=7;loc>=0;loc--)
				if(chess[i][loc]==1) break;
			if(loc!=-1) chess[i][loc]=0;
			
			for(j=loc+1;j<8;j++){
				chess[i][j]=1;
				if(jud(i,j)) break;
				chess[i][j]=0;
			}
			if(j==8) i--;
			else 	 i++;
			
			if(i==8){
				flag=true;
				break;
			} 
			if(i==1) break;
		}
		
		if(!flag)
			clear();
		else 
			break;
	}
}
