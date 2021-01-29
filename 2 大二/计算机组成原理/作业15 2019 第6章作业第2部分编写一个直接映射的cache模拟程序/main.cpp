#include <iostream>
#include <fstream>
using namespace std;
 
struct cache_line_character{
	bool B_address[4]; 
};
struct cache_line{
	cache_line_character character[1];
	bool tag[27];
	bool first_time;
	cache_line(){
		first_time=true;
	}
};
struct cache{
	cache_line cache_group[8];
};
void transform(char *buffer,bool *address){
	for(int i=0;i<8;i++){
		int temp=buffer[i+2]-48;
		if(temp>=10 || temp<0)
			temp=buffer[i+2]-65+10;
		for(int j=0;j<4;j++){
			address[i*4+3-j]=temp%2;
			temp=temp/2;
		}
	}
	for(int i=0;i<27;i++)
		cout<<address[i];
	cout<<" ";
	for(int i=27;i<30;i++)
		cout<<address[i];
	cout<<" ";
	for(int i=30;i<32;i++)
		cout<<address[i];	
	cout<<endl;
}
bool jud(bool *tag,bool *address){
	for(int i=0;i<27;i++){
		if(tag[i]!=address[i]) {
			return true;
		}
	}
	return false;
}
int main(int argc, char** argv) {
	
/*
该32位地址中，0-1位为块内地址
2-4位为cache索引
5到31位为主存标记，在cache中做标记 
*/
	cache mycache; 
	int all=0;
	int correct=0;
	char buffer[11];
	ifstream file("trace.txt");
	while(!file.eof()){
		all++;
		cout<<endl<<"第"<<all<<"条指令："; 
        file.getline(buffer,11);
        cout<<"内存地址为"<<buffer<<"    二进制表示为";
        bool address[32];
        transform(buffer,address);
        
        int cache_group=0;
        int ex=1;
        for(int i=29;i>26;i--){
        	if(address[i])
        		cache_group+=ex;
        	ex*=2;
		}
        cout<<"该内容在cache的第"<<cache_group<<"个cache组"<<endl; 
        if(mycache.cache_group[cache_group].first_time==true || 
			jud(mycache.cache_group[cache_group].tag , address)){
				cout<<"未命中"<<endl;
				mycache.cache_group[cache_group].first_time=false;
				int i;
				for(i=0;i<27;i++){
					mycache.cache_group[cache_group].tag[i]=address[i];	
				}
			}
		else {
			correct++;
			cout<<"命中"<<endl;
		}
    }
    file.close();
    cout<<"命中率为："<<double(correct)/double(all) ; 
	return 0;
}
