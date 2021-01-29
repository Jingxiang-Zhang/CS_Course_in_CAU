#include <iostream>
#include <stdlib.h>    
#include <time.h> 
using namespace std;
int **creat_a_map(int size){
	int **map;
	int i,j;
	map=new int*[size];
	for(i=0;i<size;i++)
		map[i]=new int[size];
	srand((unsigned)time(0));
	for(i=0;i<size;i++)
		for(j=0;j<size;j++){
			if(i==j) {
				map[i][j]=0;
				continue;
			}
			int temp;
			while(true){
				temp=rand()%20;
				if(temp>=5) break;
			}
			map[i][j]=temp;
		}
	return map;
}
void show_map(int **cmap,int size){
	int i,j;
	cout<<"city map£º\n";
	for(i=0;i<size;i++){
		for(j=0;j<size;j++)
			printf("%2d ",cmap[i][j]);
		printf("\n");
	}
}
void greedy_algorithm(int **cmap,int start,int size){
	int now_point=start;
	int *temp_ma=new int[size];
	for(int k=0;k<size;k++)
		temp_ma[k]=cmap[k][0];
	int step=0;
	for(int i=0;i<size-1;i++){
		cout<<"from "<<now_point+1;
		int j,minstep=1000000,minpoint;
		for(j=0;j<size;j++)
			cmap[j][now_point]=1000000;
		for(j=0;j<size;j++){
			if(now_point==j) continue;
			if(cmap[now_point][j]<minstep){
				minstep=cmap[now_point][j];
				minpoint=j;
			}
		}
		step+=minstep;
		now_point=minpoint;
		cout<<" to "<<now_point+1<<endl;
	}
	cout<<"from "<<now_point+1<<" to "<<start+1<<endl;
	step+=temp_ma[now_point];
	delete temp_ma;
	cout<<"step£º"<<step; 
}
void clear(int **map,int size){
	for(int i=0;i<size;i++)
		delete map[i];
	delete map;
}
int main(int argc, char** argv) {
	int **cmap;
	int mapsize;
	while(true){
		while(true){
			cout<<"please input map size(3 to 10): "; 
			cin>>mapsize;
			getchar();
			if(!(mapsize>10 || mapsize<3) ) break;
			cout<<"size error!"<<endl; 
		}
		cmap=creat_a_map(mapsize); 
		show_map(cmap,mapsize);
		greedy_algorithm(cmap,0,mapsize);
		clear(cmap,mapsize);
		printf("\n\n\n");
	} 
	return 0;
}
