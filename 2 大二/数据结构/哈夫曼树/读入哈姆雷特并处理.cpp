#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
bool statistic(int words[26]){
	ifstream file("SourceFile.txt");
	if(file.is_open()==false){
		cout<<"文件打开失败！";
		return false;
	}
	for(int i=0;i<26;i++)
		words[i]=0; 
	while(!file.eof()){
		char c;
		file>>c;
		if(c>='A'&&c<='Z')
			words[c-'A']++;
		else if(c>='a'&&c<='z')
			words[c-'a']++;
	}
	int sumall=0;
	for(int i=0;i<26;i++)
		sumall+=words[i];
	double gailv[26];
	for(int i=0;i<26;i++)
		gailv[i]=100*double(words[i])/double(sumall);
	cout<<"统计作品哈姆雷特的字母数量，结果如下：\n";
	cout<<"字母   出现次数     频率\n"; 
	for(int i=0;i<26;i++)
		cout<<char(i+'A')<<setw(7)<<"    "<<words[i]<<"       "<<gailv[i]<<"%"<<endl;
	cout<<"\n\n\n";
	file.close();
	return true;
} 
struct Huffman_tree{
	int parent;
	int lchild;
	int rchild;
	int weight;
	int loc;
};
void search(Huffman_tree HT[51],int &m,int &n,int loc){
	int minn=1000000;
	int minloc=0;
	for(int i=0;i<loc;i++){
		if(HT[i].parent!=-1)
			continue;
		if(HT[i].weight<minn){
			minn=HT[i].weight;
			minloc=i;
		}
	}
	int seminn=1000000;
	int seminloc=0;
	for(int i=0;i<loc;i++){
		if(HT[i].parent!=-1||i==minloc) 
			continue;
		if(HT[i].weight<seminn){
			seminn=HT[i].weight;
			seminloc=i;
		}
	}
	m=minloc;
	n=seminloc;
}
void build_Huffman_tree(int words[26],Huffman_tree HT[51]){
	int i;
	for(i=0;i<26;i++){
		HT[i].parent=-1;
		HT[i].lchild=-1;
		HT[i].rchild=-1;
		HT[i].weight=words[i];
		HT[i].loc=i;
	}	
	for(i=26;i<51;i++){
		int n,m;
		search(HT,m,n,i);
		HT[i].lchild=m;
		HT[i].rchild=n;
		HT[i].parent=-1;
		HT[i].loc=i;
		HT[i].weight=HT[m].weight+HT[n].weight;
		HT[m].parent=i;
		HT[n].parent=i;
	}
}
show_Huffman_tree(Huffman_tree HT[51]){
	cout<<"构建的哈夫曼树为："<<endl;
	cout<<"name   weight   lchild   rchild    parent"<<endl;
	for(int i=0;i<51;i++)
		cout<<setw(2)<<HT[i].loc<<"    "<<
			setw(6)<<HT[i].weight<<"      "<<
			setw(2)<<HT[i].lchild<<"      "<<
			setw(2)<<HT[i].rchild<<"        "<<
			HT[i].parent<<endl;
	cout<<"\n\n"; 
}
void build_Huffman_code(string Huffman_code[26],Huffman_tree HT[51]){
	for(int i=0;i<26;i++){
		string temp;
		Huffman_tree tr=HT[i];
		int q=i;
		while(tr.parent!=-1){
			tr=HT[tr.parent];
			if(tr.lchild==q)	temp+='0';
			else if(tr.rchild==q)temp+='1';
			q=HT[tr.loc].loc;
		} 
		for(int j=temp.length()-1;j>=0;j--)
			Huffman_code[i]+=temp[j];
	}
} 
void show_Huffman_code(string Huffman_code[26]){
	cout<<"霍夫曼编码为："<<endl;
	cout<<"字母      编码"<<endl;
	for(int i=0;i<26;i++)
		cout<<char(i+'A')<<"         "<<Huffman_code[i]<<endl;
}
void save_tree(string Huffman_code[26]){
	ofstream file("Code.txt");
	for(int i=0;i<26;i++)
		file<<char(i+'A')<<"   "<<Huffman_code[i]<<endl;
	cout<<"文件写入完毕！\n";
	file.close();
}
void transform(string Huffman_code[26]){
	ifstream file("SourceFile.txt");
	ofstream file2("ResultFile.txt");
	int loc=0;
	while(!file.eof()){
		char c;
		file>>c;
		if(c>='A'&&c<='Z')
			file2<<Huffman_code[c-'A'];
		if(c>='a'&&c<='z')
			file2<<Huffman_code[c-'a'];
	}
	file.close();
	file2.close();
	cout<<"文件转换完毕！"<<endl;
}
int main(int argc, char** argv) {
	int words[26];
	Huffman_tree HT[51];
	string Huffman_code[26];
	
	if(statistic(words)==false)    return 0;
		
	build_Huffman_tree(words,HT);
	show_Huffman_tree(HT);
	
	build_Huffman_code(Huffman_code,HT);
	show_Huffman_code(Huffman_code);
	
	save_tree(Huffman_code);
	transform(Huffman_code);
	return 0;
}
