#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <windows.h>
#include <shlobj.h>
#include <sstream> 
using namespace std;
struct view{
	//图采用的是领接表的形式 
	string name;
	map<string,double> loc;
	bool has_been_walked;
	int step;
	int from;
};
namespace variation{
	bool have_operate=false;
	int max_read_length=20000;
}
class Error{
	//此处列出了程序操作过程中可能出现的错误 
	public:
		void static file_format_error(){
			cout<<"文件格式出现错误，打开失败！\n";
		}
		void static view_has_exist_error(){
			cout<<"该景点已经存在！"<<endl;
		}
		void static view_donot_exist_error(){
			cout<<"该景点不存在！"<<endl;
		}
		void static filename_exit_limit(){
			cout<<"文件名超出长度范围，请重新输入！"<<endl;
		}
		void static name_has_exist(){
			cout<<"名称重复！"<<endl;
		}
};
vector<view> information;
int search_view(string name){
	//根据传递的景点名称来寻找景点 
	int i;
	for(i=0;i<information.size();i++)
		if(information[i].name==name) 
			break;
	if(i==information.size()) 
		return -1;
	return i;
}
void insert(){
	//插入一个景点 
	string s;
	view tempview;
	cout<<"景点名称：";
	cin>>s;
	getchar();
	int k=search_view(s);
	if(k!=-1){
		Error e;
		e.view_has_exist_error();
		return;
	} 
	tempview.name=s;
	string a;
	double b;
	while(true){
		if(information.size()==0) break; 
		cout<<"与已知景点的关系（景点，路程），输入0 0表示退出：";
		cin>>a>>b; 
		getchar();
		if(a=="0"&&b==0) break;
		map<string,int>::iterator iter;
		view operview;
		int i=search_view(a);
		if(i==-1){
			Error e;
			e.view_donot_exist_error();
			return;
		}
		information[i].loc[s]=b;
		tempview.loc[a]=b;
	}
	variation::have_operate=true;
	information.push_back(tempview);
}
void show(){
	//展示全部的景点 
	for(int i=0;i<information.size();i++){
		cout<<"第"<<i<<"个景点，名字：  "<<information[i].name<<endl;
		map<string,double>::iterator it;
		for(it=information[i].loc.begin();it!=information[i].loc.end();it++)
			cout<<"    距离\""<<it->first<<"\"景点    "<<it->second<<"公里\n"; 
	}
}

string strip(string com){
	//去掉字符串中全部的空格 
	string temp;
	for(int i=0;i<com.length();i++){
		if(com[i]!=' ') temp+=com[i];
	}
	return temp;
}
void preserve_path(char *path){
	int size,i;
	size=information.size();
	ofstream file(path);
	file<<size<<endl;
	for(int i=0;i<size;i++)
		file<<information[i].name<<endl;
	//保存文件的第一行为景点数量，之后n行为每个景点名称 
	for(int i=0;i<size;i++){
		file<<information[i].loc.size()<<endl;
		map<string,double>::iterator it;
		for(it=information[i].loc.begin();it!=information[i].loc.end();it++)
			file<<it->first<<endl<<it->second<<endl; 
	}
	variation::have_operate=false;
	file.close();
}
void preserve(){
	//保存文件，保存路径为桌面 
	string name;
	while(true){
		cout<<"请输入文件名：   ";
		getline(cin,name);
		if(name.size()>=50){
			Error e;
			e.filename_exit_limit();
		}
		else break;
	}
	TCHAR path[255];
	SHGetSpecialFolderPath(0,path,CSIDL_DESKTOPDIRECTORY,0);
	int lo;
	for(lo=0;lo<255;lo++)
		if(path[lo]=='\0') 
			break;
	path[lo++]='\\';
	for(int i=0;i<name.size();i++){
		path[lo]=name[i];
		lo++;
	}
	path[lo++]='.';
	path[lo++]='t';
	path[lo++]='x';
	path[lo++]='t';
	path[lo]='\0';
	cout<<"保存路径为桌面："<<path<<endl;
	preserve_path(path);
}
void open(){
	ifstream file;
	while(true){
		char path[255];
		cout<<"请输入文件路径：";
		cin>>path;
		getchar();
		file.open(path);
		if(file.is_open()==true) break;
		cout<<"路径错误！\n";
	}
	if(variation::have_operate==true){
		cout<<"当前执行的操作尚未保存，不保存将导致数据丢失，是否保存（y,n）?  ";
		char flag;
		cin>>flag;
		getchar();
		if(flag=='y') preserve();
	} 
	information.clear();
	string line;
	getline(file,line);
	stringstream ss;
	ss<<line;
	int size;
	ss>>size;
	for(int i=0;i<size;i++){
		getline(file,line);
		view tempview;
		tempview.name=line;
		information.push_back(tempview);
	}
	for(int i=0;i<size;i++){
		getline(file,line);
		stringstream st;
		st<<line;
		int nowsize;
		st>>nowsize;
		for(int j=0;j<nowsize;j++){
			string name1;
			string length;
			getline(file,name1);
			getline(file,length);
			stringstream se;
			se<<length;
			int leng;
			se>>leng;
			information[i].loc[name1]=leng;
		}
	}
	cout<<"文件打开完毕"<<endl;	
//C:\Users\lenovo\Desktop\ss.txt
}
void look(string name){
	name=name.substr(4,name.size()-3);
	int i=search_view(name);
	if(i==-1){
		Error e;
		e.view_donot_exist_error();
		return;
	}
	cout<<"第"<<i<<"个景点，名字："<<information[i].name<<endl;
	map<string,double>::iterator it;
	for(it=information[i].loc.begin();it!=information[i].loc.end();it++)
		cout<<"    距离\""<<it->first<<"\"景点    "<<it->second<<"公里\n"; 
}
void insert_path(){
	cout<<"请输入一个景点：";
	string s;
	Error e;
	cin>>s;
	getchar();
	int k=search_view(s);
	if(k==-1){
		e.view_donot_exist_error();
		return;
	}
	cout<<"当前操作的景点为："<<s<<"，所有的其他景点为："<<endl;
	int i;
	for(i=0;i<information.size();i++)
		if(i!=k)
			cout<<"    "<<information[i].name<<endl;
	cout<<"请输入一个与之关联的景点：";
	string newpath;
	cin>>newpath;
	getchar();
	if(newpath==s){
		cout<<"不能以自己为关联景点"<<endl;
		return;
	}
	int k2=search_view(newpath);
	if(k2==-1){
		e.view_donot_exist_error();
		return;
	}
	cout<<"请输入距离：";
	int leng;
	cin>>leng;
	getchar();
	information[k].loc[newpath]=leng;
	information[k2].loc[s]=leng; 
}

void delview(string com){
	string name=com.substr(7,com.size()-6);
	int k=search_view(name);
	Error e;
	if(k==-1){
		e.view_donot_exist_error();
		return;
	}
	vector<view>::iterator it=information.begin();
	for(int i=0;i<k;i++) it++;
	information.erase(it);
	for(int i=0;i<information.size();i++){
		map<string,double>::iterator it;
		for(it=information[i].loc.begin();it!=information[i].loc.end();){
			if(it->first==name)
				information[i].loc.erase(it++);
			else it++;
		}
	}
}
bool open_two_view(string *name1,string *name2,int *lo1,int *lo2){
	int loc1,loc2;
	Error e;
	cout<<"请输入景点1：";
	cin>>*name1; 
	getchar();
	loc1=search_view(*name1);
	if(loc1==-1){
		e.view_donot_exist_error();
		return false;
	}
	cout<<"请输入景点2：";
	cin>>*name2;
	getchar();
	loc2=search_view(*name2);
	if(loc2==-1){
		e.view_donot_exist_error();
		return false;
	}
	if(loc1==loc2){
		e.name_has_exist();
		return false;
	}
	*lo1=loc1;
	*lo2=loc2;
	return true;
}
void delpath(){
	string name1,name2;
	int loc1,loc2;
	if(!open_two_view(&name1,&name2,&loc1,&loc2))
		return;
	map<string,double>::iterator it;
	for(it=information[loc1].loc.begin();it!=information[loc1].loc.end();){
		if(it->first==name2){
			information[loc1].loc.erase(it);
			break;
		}
		it++;	
	}
	for(it=information[loc2].loc.begin();it!=information[loc2].loc.end();){
		if(it->first==name1){
			information[loc2].loc.erase(it);
			break;
		}
		it++;
	}
}
struct showpath{
	string name;
	double leng;
};
void show_path(int start,int end){
	vector<showpath> path;
	int now=end;
	while(now!=start){
		showpath temp;
		temp.name=information[now].name;
		int tempstep=information[now].step;
		now=information[now].from;
		temp.leng=tempstep-information[now].step;
		path.push_back(temp);
	}
	cout<<"从"<< information[now].name<<"出发"<<endl; 
	for(int i=path.size()-1;i>=0;i--){
		cout<<"走"<<path[i].leng<<"米，到达"<<path[i].name<<endl;
	} 
	cout<<"总共"<<information[end].step<<"米"<<endl;
}
void dijkstra_alg(){
	string name1,name2;
	int loc1,loc2;
	if(!open_two_view(&name1,&name2,&loc1,&loc2))
		return;
	int size,i,j;
	size=information.size();
	for(i=0;i<size;i++){
		information[i].step=100000;
		information[i].has_been_walked=false;
	} 	
	information[loc1].has_been_walked=true;
	information[loc1].step=0;
	int nowloc=loc1;
//	C:\Users\lenovo\Desktop\CAUViewMap.txt
	for(j=0;j<size;j++){
		map<string,double>::iterator it;
		for(it=information[nowloc].loc.begin();it!=information[nowloc].loc.end();it++){
			int operloc;
			operloc=search_view(it->first);
			if(information[operloc].has_been_walked==true) 
				continue;
			int operstep;
			operstep=information[nowloc].step+it->second;
			if(operstep<information[operloc].step){
				information[operloc].step=operstep;
				information[operloc].from=nowloc;
			}	
		}
		int minloc=0;
		int minsize=1000000;
		for(i=0;i<size;i++){
			if(information[i].has_been_walked==true)
				continue;
			if(information[i].step<minsize){
				minsize=information[i].step;
				minloc=i;
			}
		}
		if(minloc==loc2) 
			break;
		nowloc=minloc;
		information[minloc].has_been_walked=true;
	}
	show_path(loc1,loc2);
}
void help(){
	cout<<"                        景点管理系统1.0                           	  \n"<<
		  "    退出：             q                帮助：          help      	  \n"<<
		  "    展示全部景点信息： show             插入新的景点：  insert         \n"<<
		  "    清空屏幕：         clear            保存景点信息：  preserve       \n"<<
		  "    打开一个景点：     open             插入一条路径：  insert path    \n"<<
		  "    查看一个景点：     look+景点名      删除一个景点：  delview+景点名 \n"<<
		  "    计算最短距离：     cal\n";
		  
}
bool command(string com){
	com=strip(com);
	if(com=="q")        				return false;
	else if(com=="insert")				insert(); 
	else if(com=="show")				show();
	else if(com=="clear")				system("cls");
	else if(com=="help")    			help();
	else if(com=="")					return true;
	else if(com=="preserve")			preserve(); 
	else if(com=="open")				open();
	else if(com=="insertpath")   		insert_path();
	else if(com=="delpath")				delpath();
	else if(com.substr(0,4)=="look")	look(com);
	else if(com.substr(0,7)=="delview") delview(com);
	else if(com=="cal")					dijkstra_alg();
	else								cout<<"错误！"<<endl;
	return true; 
	
}
int main(int argc, char** argv) {
	cout<<"提示：help为帮助"<<endl;
	string com;
	while(true){
		cout<<">>";
		getline(cin,com);
		if(command(com)==false)
			break;
	}
	return 0;
}
//  p 修改一个已有景点的相关信息；
//  p 增加一个新景点及其相关信息；           
//  p 增加一条新的路径；
//  p 删除一个景点及其相关信息；
//  p 删除一条路径。
//  p 从文件graph.txt中读取相应数据, 创建一个图,使用邻接矩阵表示图；
//  p 景点信息查询：为来访客人提供校园任意景点相关信息的介绍；
//  p 问路查询：为来访客人提供校园任意两个景点之间的一条最短路径。
