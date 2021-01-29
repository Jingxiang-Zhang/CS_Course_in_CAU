#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include "sort.h"
using namespace std; 

int get_number(){
	/*****
		获取最大的范围 
	*/
	int maxx=0;
	ifstream fin("input.txt");
	string read_one_line;
	while(fin>>read_one_line){
		stringstream ss;
		ss<<read_one_line;
		int read_int;
		ss>>read_int;
		if(maxx<read_int)
			maxx=read_int;
	}
	fin.close();
	return maxx;
}
 
int main(int argc, char** argv) {	
	int number=38;   
	//number为总的选手个数，需要输入 
	number=get_number();
	 
	vote *result=new vote[number];
	//vote为结构体，包含num选手编号和point得票结果 
	int i;
	for(i=0;i<number;i++){
		result[i].point=0;
		result[i].number=i;
	} 
	
	ifstream fin("input.txt");
	string read_one_line;
	while(fin>>read_one_line){
		stringstream ss;
		ss<<read_one_line;
		int read_int;
		ss>>read_int;
		result[read_int-1].point++;//统计结果 
	}
	fin.close();
	
	ssort(result,0,number-1); 
	//调用排序算法 
	ofstream fon("output.txt");
	for(i=0;i<number;i++){
		cout<<result[i].number+1<<": "<<result[i].point<<endl;
		fon<<result[i].number+1<<": "<<result[i].point<<endl;
		//将结果打印出来并写入到txt文件里面 
	}
	fon.close();
	
	cout<<"第一名为："<<result[0].number+1<<"号选手，共"<<result[0].point<<"票"<<endl;
	cout<<"第二名为："<<result[1].number+1<<"号选手，共"<<result[1].point<<"票"<<endl;
	cout<<"第三名为："<<result[2].number+1<<"号选手，共"<<result[2].point<<"票"<<endl;
	
	system("pause");
	return 0;
}
