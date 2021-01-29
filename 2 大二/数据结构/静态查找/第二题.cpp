#include <iostream>
#include <vector>
#include <iomanip>

using namespace std; 
vector<vector<int> > data;
void create_data(){
	int ma[7][8]={
		{22,4,23,11,20,2,15,13},
		{30,45,26,34,29,35,26,36},
		{55,98,56,74,61,90,80,96},
		{127,158,116,114,128,113,115,102},
		{184,211,243,188,187,218,195,210},
		{279,307,492,452,408,361,421,399},
		{856,523,704,703,697,535,534,739}
	};
	int i,j;
	for(i=0;i<7;i++){
		int maxx=ma[i][0];
		int minn=ma[i][0];
		for(j=1;j<8;j++){
			if(maxx<ma[i][j]) maxx=ma[i][j];
			if(minn>ma[i][j]) minn=ma[i][j];
		}
		vector<int> temp;
		temp.push_back(minn);
		temp.push_back(maxx);
		for(j=0;j<8;j++)
			temp.push_back(ma[i][j]);
		data.push_back(temp);
	}
}
void show_data(){
	int i,j;
	for(i=0;i<7;i++){
		cout<<"block:"<<i+1<<"  lower limit:"<<setw(3)<<data[i][0]<<
		"  upper limit:"<<setw(3)<<data[i][1]<<"    ";
		cout<<"     data:";
		for(j=0;j<8;j++)
			cout<<setw(5)<<data[i][j+2];
		cout<<endl;
	}
}
void find(int val){
	int i,j;
	for(i=0;i<7;i++)
		if(data[i][0]>=val) break;
	bool flag=false;
	for(j=2;j<10;j++)
		if(data[i][j]==val) {
			cout<<"element "<<val<<" is located in the "<<j-1<<" of the "<<i+1<<" zone";
			flag=true;
			break;
		}
	if(flag==false) cout<<"elment "<<val<<" not found";
}
int main(int argc, char** argv) {
	create_data();
	show_data();
	cout<<"\n\n";	
	find(26);
	cout<<"\n\n";
	find(200);
	cout<<"\n\npress enter to exit";
	getchar(); 
	return 0;
}
