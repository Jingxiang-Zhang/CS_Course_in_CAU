#include <iostream>
#include <stack>
#include <list>
#include <vector>
using namespace std;
stack<int> number;
list<vector<int> > go_off_list;
vector<int> current_list;
int schoolbus_size,current_number;
bool go_off(){
	if(current_number==0)
		return false;
	int num;
	cout<<"请输入下车人数（当前车上有"<<current_number<<"个同学）：";
	cin>>num;
	if(current_number-num<0) 
		return false;
	current_number-=num;
	 
	for(int i=0;i<num;i++){
		int temp=number.top();
		number.pop();
		current_list.push_back(temp);
	}
	return true;
}
bool go_on(int num){	
	if(current_number+num>=schoolbus_size)
		return false;
	cout<<"请输入上车的同学编号（依次输入"<<num<<"个）：";
	for(int i=0;i<num;i++){
		int temp;
		cin>>temp;
		number.push(temp);
	}
	current_number+=num;
	return true;
}
int main(int argc, char** argv) {
	int total_times;
	cout<<"请输入数据组数：";
	cin>>total_times;
	cout<<endl;
	for(int q=0;q<total_times;q++){
		cout<<"第"<<q+1<<"组数据："<<endl;
		int stop_times;
		cout<<"请输入停车次数：";
		cin>>stop_times;
		cout<<"请输入校车容量：";
		cin>>schoolbus_size;
		current_number=0;
		go_off_list.clear();
		for(int i=0;i<stop_times;i++){
			int operate;
			cout<<"第"<<i+1<<"次停车，指令为："; 
			current_list.clear();
			current_list.push_back(i+1);
			cin>>operate;
			if(operate==0){
				if(!go_off()){ 
					cout<<"车上没有那么多人，请重新输入。"<<endl;
					i--;
					continue;
				} 
			}
			else if(operate>0){
				if(!go_on(operate)){
					cout<<"人数已满，多出的人无法上车。"<<endl;
					i--;
					continue;
				}
			}
			else{
				cout<<"错误，请重新输入。"<<endl;
				i--;
				continue;
			}
			go_off_list.push_back(current_list);
		}
		list<vector<int> >::iterator it;
		for(it=go_off_list.begin();it!=go_off_list.end();it++){
			vector<int> at=*it;
			if(at.size()==1) continue;
			cout<<"第"<<at[0]<<"次停车，下车的人有：" ;
			for(int i=1;i<at.size();i++){
				cout<<at[i]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl<<endl;
	}
	
	return 0;
}
