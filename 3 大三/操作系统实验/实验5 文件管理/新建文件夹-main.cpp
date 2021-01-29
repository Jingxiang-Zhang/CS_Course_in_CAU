/*
*本系统的假设：
*磁盘为40个柱面，每个柱面4个磁道，每个磁道4个屋里记录，一共40*4*4=640个磁盘块 
*每个磁盘块有1024个字节。
*其中第0个磁盘块用来存放磁盘分配的map表，前40字节，每个字节取前16位存放占用情况 
*最多允许有320个文件（即2kb一个文件），一共有320个inode结点，每个inode占用100个字节
*	即每个磁盘块可以存放10个inode结点，第1到第32块存放inode结点 
*i_block一共15个数据，但是前13个表示直接寻址，最后一个表示1级间接寻址，最大单个文件的
*	存储空间为13+1024/4=269kb 
*模拟的磁盘初始化为640*1024个int，磁盘占用表中前33块都为1表示已被占用 
*/

#include <iostream>
#include <ctime> 
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;

struct mytime{
	int minute;  //这里的时间只有分钟和秒
	int second;
};
struct ext2_inode{  //一个inode占用25个int的大小，即100个字节 
	int i_mode;     //文件模式，1表示文件，2表示目录，0为空 
	int i_uid;       //文件id 
	mytime i_ctime;  //创建时间 
	char i_name[8];   //文件名 
	int i_size;      //文件大小 
	int i_foruser;   //保留 
	
	int i_blocks; //物理块数量
	int i_block[14];  //指向物理块的指针
	int i_son;    //如果是目录，则表示子目录或文件的inode位置 
	int i_brother;  //表示和在该目录下的兄弟结点的inode位置 
};

int **MyDisk;  //磁盘 
int pwd[20];   //工作目录的fcb的uid 
int current_depth=0;//当前深度 

void trim(string &s) 
{
    if (s.empty()) 
    {
        return ;
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
}
bool AddToOccupy(int ClusterNumber){ 
	//此函数用于将一个指定的磁盘块变为占用状态 
	int column=ClusterNumber/16;
	int inside=ClusterNumber%16;
	int bdata=MyDisk[0][column];
	int location=1;
	for(int i=0;i<inside;i++){
		location=location<<1;
	}
	int test=bdata&location;

	if(test!=0)  //表示已经被占用了 
		return false;
	int ndata=bdata|location;
	MyDisk[0][column]=ndata;
	return true;
}
void DelFromOccupy(int ClusterNumber){
	//从磁盘块中将指定的磁盘块变为未被占用 
	int column=ClusterNumber/16;
	int inside=ClusterNumber%16;
	int bdata=MyDisk[0][column];
	int location=1;
	for(int i=0;i<inside;i++){
		location=location<<1;
	}
	int ndata=(bdata)&(~location);
	MyDisk[0][column]=ndata;
}
bool* ReadMap(){
	//返回一个bool指针，长度640，表示磁盘块的占用情况 
	bool *omap=new bool[640];
	int location=0;
	for(int i=0;i<40;i++){
		int currentL=MyDisk[0][i];
		for(int j=0;j<16;j++){
			omap[location]=currentL%2;
			currentL/=2;
			location++;
		}
	}
	return omap;
}
bool ShowMap(bool* omap,int length=10){
	//显示一个bool数组，表示磁盘块的占用情况 
	printf("字/位：0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15\n");
	if(length>=40 || length<=0)
		return false;
	for(int i=0;i<length;i++){
		printf("%2d:    ",i);
		for(int j=0;j<16;j++){
			printf("%d  ",omap[i*16+j]);
		}
		printf("\n");
	}
	if(length!=40){
		printf("   ..    ..\n   ..    ..\n   ..    ..\n");
		printf("%2d:    ",39);
		for(int j=0;j<16;j++){
			printf("%d  ",omap[39*16+j]);
		}
		printf("\n");
	}
	return true;
}
ext2_inode* GetFCB(int *allPCB){
	//获得程序所有的FCB
	int leftPCB;
	ext2_inode *inode=new ext2_inode[320];
	int location=0;
	for(int i=1;i<33;i++){
		for(int j=0;j<10;j++){
			if(MyDisk[i][j*25]==0){
				continue;
			}
			inode[location].i_mode=MyDisk[i][j*25];
			inode[location].i_uid=MyDisk[i][j*25+1];
			inode[location].i_ctime.minute=MyDisk[i][j*25+2];
			inode[location].i_ctime.second=MyDisk[i][j*25+3];
			char *c=(char*)(&MyDisk[i][j*25+4]);
			for(int k=0;k<8;k++){
				inode[location].i_name[k]=*c;
				c++;
			}			
			inode[location].i_size=MyDisk[i][j*25+6];
 			inode[location].i_foruser=MyDisk[i][j*25+7];
 			inode[location].i_blocks=MyDisk[i][j*25+8];
 			for(int k=0;k<14;k++){
 				inode[location].i_block[k]=MyDisk[i][j*25+9+k];
			}
			inode[location].i_son=MyDisk[i][j*25+23];
			inode[location].i_brother=MyDisk[i][j*25+24];
			location++;
		}
	}
	*allPCB=location;
	return inode;
}
void ShowFCB(ext2_inode* inode,int size){
	//根据inode结点数组和长度，显示所有的FCB结点 
	printf("    name  mode  uid    size  creattime  blocks\n");
	for(int i=0;i<size;i++){
		printf("%7s   %2d   %3d  %6d      %d:%d      %2d\n",
			inode[i].i_name,
			inode[i].i_mode,inode[i].i_uid,inode[i].i_size,
			inode[i].i_ctime.minute,inode[i].i_ctime.second,
			inode[i].i_blocks);
	}   
	
}
int GetLastSonUid(bool *dirSon){
	//返回uid 
	//找到当前目录下，孩子兄弟结点的最后一个，用于添加结点的时候使用
	//dirSon为true表示当前目录没有子文件，应添加到孩子结点
	//否则应找到当前结点的孩子结点的最后一个兄弟结点的uid 
	int nowUid=pwd[current_depth-1];
	*dirSon=true;
	int column=(nowUid%10)*25;
	int block=nowUid/10+1;
	if(MyDisk[block][column+23]!=0){
		*dirSon=false;
		nowUid=MyDisk[block][column+23];
		column=(nowUid%10)*25;
		block=nowUid/10+1;
		if(MyDisk[block][column+24]!=0){
		   	while(true){
		   		nowUid=MyDisk[block][column+24];
		   		column=(nowUid%10)*25;
				block=nowUid/10+1;
				if(MyDisk[block][column+24]==0){
					break;
				}
			}
		}
	}
	return nowUid;
}
int GetSonUidByName(string name){
	//在当前目录下，根据名字找到uid，找不到返回-1 
	int nowUid=pwd[current_depth-1];
	int column=(nowUid%10)*25;
	int block=nowUid/10+1;
	if(MyDisk[block][column+23]==0){
		return -1;
	}
	const char *name2=name.c_str();
	nowUid=MyDisk[block][column+23];
	while(true){
		int column=(nowUid%10)*25;
		int block=nowUid/10+1;
		char *n=(char*)(&MyDisk[block][column+4]);
		if(strcmp(n,name2)==0){
			return nowUid;
		}
		nowUid=MyDisk[block][column+24];
		if(nowUid==0)
			return -1;
	}
}
bool LinkToSystem(int LastUid,int NowUid,bool son){
	//将新的结点连接到当前目录中 
	int column=(LastUid%10)*25;
	int block=LastUid/10+1;
	if(son){
		MyDisk[block][column+23]=NowUid;
	}
	else{
		MyDisk[block][column+24]=NowUid;
	}	
}
void Del(int uid){
	//删除uid结点以及递归调用删除uid结点下的所以结点 
	int column=(uid%10)*25;
	int block=uid/10+1;
	int nowUid=MyDisk[block][column+23];
	if(nowUid!=0){
		Del(nowUid);
		while(true){
			column=(nowUid%10)*25;
			block=nowUid/10+1;
			nowUid=MyDisk[block][column+24];
			if(nowUid!=0){
				Del(nowUid);
			}
			else{
				break;
			}
		}
	}
	column=(uid%10)*25;
	block=uid/10+1;
	int blocks=MyDisk[block][column+8];
	int i;
	MyDisk[block][column]=0;
	for(i=0;i<blocks;i++){
		if(i==13) 
			break;
		DelFromOccupy(MyDisk[block][column+9+i]);
	}
	if(i==13 && MyDisk[block][column+22]!=0){
		int location=MyDisk[block][column+22];
		for(int j=0;j<256;j++){
			if(MyDisk[location][j]==0)
				break;
			DelFromOccupy(MyDisk[location][j]);
		}
		DelFromOccupy(MyDisk[block][column+22]);
	}

}
void DelByName(string name){	
	//找到目录下相应的名字删除，需要孩子兄弟结点的重新链接 
	int nowUid=pwd[current_depth-1];
	int column=(nowUid%10)*25;
	int block=nowUid/10+1;
	if(MyDisk[block][column+23]==0){
		printf("no such file or directory\n");
		return;
	}
	const char *name2=name.c_str();
	nowUid=MyDisk[block][column+23];
	int lastUid=nowUid; 
	while(true){
		column=(nowUid%10)*25;
		block=nowUid/10+1;
		char *n=(char*)(&MyDisk[block][column+4]);
		if(strcmp(n,name2)==0){
			break;
		}
		lastUid=nowUid;
		nowUid=MyDisk[block][column+24];
		if(nowUid==0){
			printf("no such file or directory\n");
			return;
		}
	}
	//指针重新链接 
	if(nowUid==lastUid){
		int nextUid=MyDisk[block][column+24];
		lastUid=pwd[current_depth-1];
		column=(lastUid%10)*25;
		block=lastUid/10+1;
		MyDisk[block][column+23]=nextUid;
	}
	else{
		int nextUid=MyDisk[block][column+24];
		column=(lastUid%10)*25;
		block=lastUid/10+1;
		MyDisk[block][column+24]=nextUid;
	}
	
	Del(nowUid);	
}

void ListSub(string information){
	//列出当前目录下所有的文件
	int nowUid=pwd[current_depth-1];
	int column=(nowUid%10)*25;
	int block=nowUid/10+1;
	if(MyDisk[block][column+23]==0){
		return;
	}
	nowUid=MyDisk[block][column+23];
	int i=0;
	while(true){
		int column=(nowUid%10)*25;
		int block=nowUid/10+1;
		i++;
		printf("%8s ",(char*)(&MyDisk[block][column+4]));
		if(i%5==0) 
			printf("\n");
		nowUid=MyDisk[block][column+24];
		if(nowUid==0){
			printf("\n\n");
			return;
		}		
	}	
}
int CreatePCB(int mode){ 
	//创建一个空FCB，返回创建的uid 
	bool flag=false;
	int i,j;
	for(i=1;i<33;i++){
		for(j=0;j<10;j++){
			if(MyDisk[i][j*25]==0){
				flag=true;
				break;
			}
		}
		if(flag) break;	
	}
	if(!flag){
		return false;
	}
	int uid=(i-1)*10+j;  //uid的高2位为1到33，低位为10个 
	tm *local;  //获取系统时间 
	time_t t;
	t=time(NULL);
	local=localtime(&t);
	MyDisk[i][j*25]=mode;
	MyDisk[i][j*25+1]=uid;
	MyDisk[i][j*25+2]=local->tm_min;
	MyDisk[i][j*25+3]=local->tm_sec;
	MyDisk[i][j*25+6]=0;
	MyDisk[i][j*25+7]=0;
	MyDisk[i][j*25+8]=0;
	MyDisk[i][j*25+22]=0;
	MyDisk[i][j*25+23]=0;
	MyDisk[i][j*25+24]=0;
	return uid;
}
bool AddToDisk(int uid,char fi[1024]){  
	//给定一个uid和需要添加的数据，如果添加成功返回true，磁盘满了或程序过大返回false 
	//找到一个空闲的盘块并添加占用 
	bool *omap=new bool[640];
	omap=ReadMap();
	int location;
	for(location=0;location<640;location++){
		if(omap[location]==0){
			break;
		}
	}
	if(location==640) return false;
	AddToOccupy(location);
	//根据uid找到文件的inode结点在磁盘中的位置 
	int column=(uid%10)*25;
	int block=uid/10+1;
	if(MyDisk[block][column+8]<=12){
		//如果当前占用的不到12块，则增加一块 
		MyDisk[block][column+8]++;
		int num=MyDisk[block][column+8];
		MyDisk[block][column+8+num]=location;
	}
	else if(MyDisk[block][column+8]==13){
		//如果当前占用为13块，则采用一级索引的方式 
		MyDisk[block][column+8]++;
		MyDisk[block][column+22]=location;
		for(int i=0;i<256;i++){
			MyDisk[location][i]=0;
		}  
		//还要找到一个新的空闲块location2 
		omap=ReadMap();
		int location2;
		for(location2=0;location2<640;location2++){ 
			if(omap[location2]==0){
				break;
			}
		}
		if(location2==640) return false;
		AddToOccupy(location2);
		MyDisk[location][0]=location2;
		location=location2;
	}
	else if(MyDisk[block][column+8]==14){
		//如果已经是一级索引，则再添加一个 
		int cluster=MyDisk[block][column+22];
		int i;
		for(i=0;i<256;i++){
			if(MyDisk[cluster][i]==0)
				break;
		}
		if(i==256) return false;
		MyDisk[cluster][i]=location;
	}
	//复制文件 
	int *p=(int*)(fi);
	for(int i=0;i<256;i++){
		MyDisk[location][i]=*p;
		p++;
	}
	return true;
}
char* GetContentFromUid(int uid,int *length){
	//通过uid，返回该文件的完整内容，长度为length 
	int column=(uid%10)*25;
	int block=uid/10+1;
	int size=MyDisk[block][column+6];
	*length=size;
	char *file=new char[size+1];
	int blocks=size/1024+1;
	int i;
	int t=0;
	int j;
	for(i=0;i<14;i++){
		int location=MyDisk[block][column+9+i];
		int readbits=size<1024?size:1024;
		size-=1024;
		char *c=(char*)(&MyDisk[location][0]);
		for(j=0;j<readbits;j++,t++){
			file[t]=*c;
			c++;
		}
		if(size<=0) break;
 	}
 	int loc=MyDisk[block][column+22];
 	if(i==14 && size>0){
 		for(i=0;i<256;i++){
 			int location=MyDisk[loc][i];
 			int readbits=size<1024?size:1024;
 			size-=1024;
			char *c=(char*)(&MyDisk[location][0]);
			for(j=0;j<readbits;j++,t++){
				file[t]=*c;
				c++;
			}
			if(size<=0) break;
		}
	} 
	file[t]=0;
	return file;
}
void ShowFile(string name){
	//通过文件名找到uid，调用上一个函数，并展示文件，more指令可调用 
	int uid=GetSonUidByName(name);
	if(uid==-1){
		return;
	}
	int column=(uid%10)*25;
	int block=uid/10+1;
	printf("file uid: %d\n",uid);
	printf("file mode: ") ;
	if(MyDisk[block][column]==1){
		printf("direction\n");
	}
	else{
		printf("file\n");
	}
	printf("create time: %d:%d\n",MyDisk[block][column+2],MyDisk[block][column+3]);	
	printf("file name: %s\n",(char*)(&MyDisk[block][column+4]));
	printf("file size: %d\n",MyDisk[block][column+6]);
	
	if(MyDisk[block][column]==1) return;
	int length;
 	char *c=GetContentFromUid(uid,&length);
 	for(int i=0;i<length;i++){
 		if((i+1)%1024==0){
 			char t=getch();
 			if(t=='q'){
 				break;
			 }
		}
 		printf("%c",*c);
 		c++;
	}
	printf("\n\n");
}

bool SaveDisk(string name){
	//保存磁盘内容 
	const char *location=name.c_str();
	ofstream outFile(location,ios::out|ios::binary);
	if(!outFile){
		printf("save disk error, check if you write the correct direction.\n");
		return false;
	}
	for(int i=0;i<639;i++){
		for(int j=0;j<256;j++){
			outFile.write((char*)(&MyDisk[i][j]),4);
		}
	
	}
	printf("file save successfully.\n");
	return true;
}
bool LoadDisk(string information){
	//加载磁盘 
	const char *location=information.c_str();
	ifstream in(location,ios::binary);
	if(!in){
		printf("file not found error.\n");
	}
	printf("you are trying to disk overlay, that may cause error, would you like to continue[y/n]?");
	while(true){
		char c=getch();
		if(c=='n'){
			printf("\n");
			return false;
		}
		else if(c=='y'){
			printf("\n");
			break;
		}
	}
	char flush[1024];
    int inbit=0;
    int i=0;
	while(!in.eof()){//loaddisk C:\Users\lenovo\Desktop\te
    	in.read(flush,1024);
    	inbit+=in.gcount();
    	int *fl=(int*)(flush);
		
    	for(int j=0;j<256;j++){
    		MyDisk[i][j]=fl[j];
		}
		i++;
		
	}
	if(inbit!=1024*639){
		printf("file and disk corrupted, pleast format hard disk.\n");
	}
	else{
		printf("disk overlay successfully.\n");
	}
}
bool readBinaryFile(const char *fileName){
	//读入数据，要调用 AddToDisk函数 
	char *location=new char[100];
	char *name=new char[8];
	int i,j; 
	for(i=0;i<100;i++){
		name[i]=fileName[i];
		if(fileName[i]==' ' || i==7)
			break;
	}
	name[i]=0;		
	for(j=0,i++;i<100;i++,j++){
		location[j]=fileName[i];
		if(fileName[i]==0)
			break;
	}
	if(GetSonUidByName(name)!=-1){
		printf("file or directory have already exist.\n");
		return 0;
	}
	ifstream in(location,ios::binary);
	if(!in) {
    	printf("File not found error!\n");
        return false;
    }
    int uid=CreatePCB(2);
    int column=(uid%10)*25;
	int block=uid/10+1;
	
	char *c=(char*)(&MyDisk[block][column+4]);
	for(int i=0;i<8;i++){
		*c=*name;
		c++;
		name++;
	}
    char flush[1024];
    int inbit=0;
    while(!in.eof()){
    	in.read(flush,1024);
    	inbit+=in.gcount();
    	if(!AddToDisk(uid,flush)){
    		printf("Error, can not add to disk\n");
    		DelByName(c);
    		return false; //删除文件 
		}
	}
	in.close();
	MyDisk[block][column+6]=inbit;
	bool son;
	int Uid=GetLastSonUid(&son);
	LinkToSystem(Uid,uid,son);
   // writeBinaryFile("C:\\Users\\lenovo\\Desktop\\te.txt",fi,location);
    return true;
}
void ShowDiskMap(string num){
	//展示磁盘的位示图 
	int length=10;
	if(num!=""){
		for(int i=0;i<num.length();i++){
			if(num[i]>'9'||num[i]<'0'){
				printf("instruction error!\n");
				return;
			}
		}
		length=atoi(num.c_str());
		if(length>40) length=40;
	}
	bool *omap=ReadMap();
	ShowMap(omap,length);
}


int MakeDir(string information){
	//在当前目录下添加新目录 
	if(information==""){
		printf("directory must have a name.\n");
		return 0;
	}
	if(GetSonUidByName(information)!=-1){
		printf("file or directory have already exist.\n");
		return 0;
	}
	int uid=CreatePCB(1);
	int column=(uid%10)*25;
	int block=uid/10+1;
	MyDisk[block][column+6]=0;
	char *c=(char*)(&MyDisk[block][column+4]);
	int i;
	for(i=0;i<7;i++){
		*c=information[i];
		c++;
	}
	if(current_depth==0) 
		return uid;
	bool son;
	int Uid=GetLastSonUid(&son);
	LinkToSystem(Uid,uid,son);
	return uid;
}


void EnterDir(string name){
	//进入目录，name为..表示返回上一级目录 
	if(name==".."){
		if(current_depth!=1) 
			current_depth--;
		return;
	}
	int uid=GetSonUidByName(name);
	if(uid==0){
		printf("no such directiory\n");
		return;
	}
	int column=(uid%10)*25;
	int block=uid/10+1;
	if(MyDisk[block][column]!=1){
		printf("name is not a directory\n");
		return;
	}
	pwd[current_depth]=uid;
	current_depth++;
}

char *GetPWD(){
	//返回工作目录，自动调用 
	char *name=new char[150];
	int i;
	int loc=0;
	for(i=0;i<current_depth;i++){
		int uid=pwd[i];
		int column=(uid%10)*25;
		int block=uid/10+1;
		char *c=(char*)(&MyDisk[block][column+4]);
		for(int j=0;j<7;j++){
			name[loc]=*c;
			loc++;
			c++;
			if(*c==0) break;
		}
		if(i==current_depth-1){
			name[loc]='>';
			loc++;
			name[loc]=0;
		}
		else{
			name[loc]='\\';
			loc++;
		}
	}
	return name;

} 
void InitDisk(){
	//磁盘初始化 
	MyDisk=new int*[640];
	for(int i=0;i<640;i++){
		MyDisk[i]=new int[256];
	}
	for(int i=0;i<33;i++){
		for(int j=0;j<256;j++){
			MyDisk[i][j]=0;
		}
	}
	for(int i=0;i<33;i++){
		AddToOccupy(i);
	}
	int uid=MakeDir("home");
	pwd[0]=uid;
	current_depth=1;
}
void FormatDisk(){
	//磁盘格式化，调用初始化磁盘函数 
	printf("you are trying to format disk, would you like to continue[y/n]?");
	while(true){
		char c=getch();
		if(c=='n'){
			printf("\n");
			return;
		}
		else if(c=='y'){
			printf("\n");
			break;
		}
	}
	InitDisk();
	printf("format disk successfully.\n");
}
int main(int argc, char** argv) {
	InitDisk(); 
	while(true){
		string instruction;
		string information;
		printf("%s",GetPWD());
		getline(cin,instruction);
		int location=instruction.find(' ');
		if(location!=-1){
			information=instruction.substr(location+1,instruction.size()-location);
			instruction=instruction.substr(0,location);
		}
		trim(information);
		trim(instruction);
		if(instruction=="quit"){
			break;
		}
		else if(instruction=="in"){
			readBinaryFile(information.c_str());
		}
		else if(instruction=="showdiskmap"){
			ShowDiskMap(information);
		}
		else if(instruction=="showfcb"){
			int *size=new int;
			ext2_inode *inode=GetFCB(size);
			ShowFCB(inode,*size);			
		}
		else if(instruction=="more"){
			ShowFile(information);
		}
		else if(instruction=="mkdir"){
			MakeDir(information);
		}
		else if(instruction=="cd"){
			EnterDir(information);
		}
		else if(instruction=="ls"){
			ListSub(information);
		}
		else if(instruction=="del"){
			DelByName(information);
		}
		else if(instruction=="savedisk"){
			SaveDisk(information);
		}
		else if(instruction=="loaddisk"){
			LoadDisk(information);
		}
		else if(instruction=="formatdisk"){
			FormatDisk();
		}
		else if(instruction!=""){
			printf("%s is not a instruction.\n",instruction.c_str());
		}
	}
	return 0;
}
