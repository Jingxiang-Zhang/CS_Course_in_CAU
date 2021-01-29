#include <iostream>
#include <string>
using namespace std; 
int main(int argc, char** argv) {
	string encode="abcdefghijklmnopqrstuvwxyz";
	string decode="ngzqtcobmuhelkpdawxfyivrsj";
	string string_init,string_encode,string_finally;
	cout<<"请输入一串数："; 
	cin>>string_init;
	for(int i=0;i<string_init.size();i++){
		int t=encode.find(string_init[i]);
		string_encode.push_back(decode[t]);
	}
	cout<<"编码之后为："<<string_encode<<endl;
	for(int i=0;i<string_encode.size();i++){
		int t=decode.find(string_encode[i]);
		string_finally.push_back(encode[t]);
	}
	cout<<"编码之后为："<<string_finally<<endl;
	return 0;	
}
