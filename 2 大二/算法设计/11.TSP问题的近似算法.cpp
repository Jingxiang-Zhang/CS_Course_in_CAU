//StudybarCommentBegin
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int* tsp(double* px, double* py, int length);

int main()
{
	char x_char[10000];
	char y_char[10000];
	int length;
	double optimal;

	cin.getline(x_char, 10000);
	cin.getline(y_char, 10000);
	cin >> length;
	cin >> optimal;

	double x[1000];
	double y[1000];

	char* tmpStrX = strtok(x_char, " ");
	for (int i = 0; i < length; i++)
	{
		x[i] = atof(tmpStrX);
		tmpStrX = strtok(NULL, " ");
	}

	char* tmpStrY = strtok(y_char, " ");
	for (int j = 0; j < length; j++)
	{
		y[j] = atof(tmpStrY);
		tmpStrY = strtok(NULL, " ");
	}
	


	int* path = tsp(x, y, length);
	double cost = 0;
	for (int k = 0; k < length; k++)
	{
		int a = path[k];
		int b = path[(k + 1) % length];

		double d = (x[a] - x[b])* (x[a] - x[b]) + (y[a] - y[b])*(y[a] - y[b]);
		if (d == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		cost += sqrt(d);
	}
	
	if (cost > 2 * optimal)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << 1 << endl;
	return 0;
}

//StudybarCommentEnd
#include <vector>
#include <set>
struct point{
	double x;
	double y;
	vector<int> nexpoint;
};
struct cost{
	int start;
	int end;
	double weight;
	bool visited;
};
point *po;
vector<int> travel;
set<int> visit;
void travel_tree(int root){
	int i;
	int oldsize=visit.size();
	visit.insert(root);
	int newsize=visit.size();
	if(newsize!=oldsize)
		travel.push_back(root);


	for(i=0;i<po[root].nexpoint.size();i++){
		travel_tree(po[root].nexpoint[i]);
	}

}
int* tsp(double* px, double* py, int length){
	int i,j,k;

	po=new point[length];
	for(i=0;i<length;i++){
		po[i].x=px[i];
		po[i].y=py[i];
	}
	cost *co=new cost[length-1];
	for(i=0;i<length-1;i++){
		co[i].start=0;
		co[i].end=i+1;
		co[i].weight=(px[i+1]-px[0])*(px[i+1]-px[0])+(py[i+1]-py[0])*(py[i+1]-py[0]);
		co[i].visited=false;

	}
	for(i=0;i<length-1;i++){
		int minloc;
		double minval=1000000;
		for(j=0;j<length-1;j++){
			if(co[j].visited) continue;
			if(co[j].weight<minval){
				minval=co[j].weight;
				minloc=j;
			}
		}
		int nowloc=co[minloc].start;
		int nextloc=co[minloc].end;
		po[nowloc].nexpoint.push_back(nextloc);
		co[minloc].visited=true;

		for(j=0;j<length;j++){

			if(co[j].visited) continue;
			double newweight=pow((px[co[j].end]-px[minloc+1]),2)+
							pow((py[co[j].end]-py[minloc+1]),2);
			if(newweight<co[j].weight){
				co[j].weight=newweight;
				co[j].start=minloc+1;
			} 				
		}
	}
	travel_tree(0);

	int *final=new int[length+1];
	for(i=0;i<travel.size();i++){
		final[i]=travel[i];
	}
	
	final[length]=0;
	
	return final;
	
	
} 