/*
*本程序用到的所有结构所有
*由于采用的块索引为32位，所以理论最大的磁盘空间为2^32*4kb=16Tb
*每个大块有16Mb，4000个结点，需要100个磁盘块记录inode
*在磁盘中占用的物理块单块16Mb，动态增长
*
*
*
*
*/#pragma once
#include "DiskBuffer.h";

struct ext2_inode_physical { //一个inode占用30个int的大小，即120个字节
	//单个块为4Kb，即可以存储40个块，需要6位进行块内inode寻址
	//此结构体表示的是物理存储结构
	unsigned int i_ABMS;      //这个32位int表示如下：
	//0~2位：文件模式，0为空，1为可目录，2位文本文件等等 
	//3~11位：authority权限，与linux表示方法一样
	unsigned int i_uid;       //文件使用者的id
	unsigned int i_size;      //文件大小这里储存低32，单文件最大为4Gb 
	unsigned int i_ctime;     //创建时间 
	unsigned int i_mtime;     //修改日期 
	unsigned int blocks;
	char i_name[44];
	//文件名，最长为38位，
	//40为是上个结点的孩子还是兄弟
	//41位为i_last_inter的8位
	//42位为i_son_inter的8位
	//43位为i_brother_inter的8位
	unsigned int i_block[10];  //指向物理块的指针，本系统最大采用2级索引，
	unsigned int i_son_outer;    //如果是目录，则表示子目录或文件的inode位置 
	unsigned int i_brother_outer;//表示和在该目录下的兄弟结点的inode位置 
	unsigned int i_last_outer;   //表示和在该目录下的兄弟结点的inode位置 
};
struct i_Time {
	int YY;
	int MM;
	int DD;
	int hh;
	int mm;
};
struct i_Authority {
	bool Read_Me;
	bool Read_Other;
	bool Read_Visitor;
	bool Write_Me;
	bool Write_Other;
	bool Write_Visitor;
	bool Execute_Me;
	bool Execute_Other;
	bool Execute_Visitor;
};
enum i_FileMode {
	Empty=0,
	Content,
	File,
	Exe,
	Link,
	Equipment	
};

struct ext2_inode { //此结构体表示的是逻辑结构，需要进行转换
	i_FileMode i_mode;//文件模式，0为空，1为可目录，2位文本文件等等 
	i_Authority i_authority;//authority权限，与linux表示方法一样
	unsigned int i_uid;       //文件使用者的id
	unsigned int i_size;      //文件大小这里储存低32，单文件最大为4Gb 
	i_Time i_ctime;     //创建时间 
	i_Time i_mtime;     //修改日期 
	char i_name[43];  //文件名，最长为37位
	unsigned int i_blocks;//block数量，block数量上限为：8个物理块 
	unsigned int i_block[10];  //指向物理块的指针，本系统最大采用2级索引，
	unsigned int i_son_outer;    //如果是目录，则表示子目录或文件的块位置 
	unsigned int i_son_inner;    //目录情况下，inode结点的块内位置
	unsigned int i_brother_outer;  //表示和在该目录下的兄弟结点的inode位置 
	unsigned int i_brother_inner;  //目录情况下，inode结点的块内位置，每个块内可以存储40个
	unsigned int i_last_outer;  //表示和在该目录下的兄弟结点的inode位置 
	unsigned int i_last_inner;  //目录情况下，inode结点的块内位置，每个块内可以存储40个
	int is_last_father;         //1表示上个结点为父节点，0为兄弟结点
};

struct RootInfo {
	unsigned int son_num;
	unsigned int son_offset;
	unsigned int current_block_inode_number;
	unsigned int current_block_location;
};

//int Convert_IABS_ToBlocksNumber()
class Inode {
private:
	ext2_inode *ext2;
	int last_read_location;
	int last_read_offset;
	int content_location;
	DiskB disk;
	int self_location;
	int self_offset;

	void __setAuthority(int* i_ABS, int authority);
	i_Authority __getAuthority(int i_ABS);
	int __getAuthority(i_Authority authority);
	void __setImode(int* i_ABS, i_FileMode mode);
	i_FileMode __getMode(int i_ABS);
	i_Time __getTimeNow();
	int __ConvertTimeToInt(i_Time time);
	i_Time __ConvertIntToItime(int time);
	void __FCBPlus();
	void __FCBMinus();

	int __getBlocks();
	void __setChangeTime();
public:
	Inode();  //创建一个空Inode类，用于调用函数
	Inode(int block_num, int offset);  //由给定的Inode结点导入
	~Inode();

	void createRoot();
	RootInfo getRoot(); //返回根节点
	void createFCB(int father_num,int father_offset,bool isson,
		int* create_num, int* create_offset, i_FileMode fileMode, int uid,
		const char *name, int authority);

	ext2_inode* getFCB(); //获取一个inode信息
	i_FileMode getMode();
	i_Authority geteAuthority();
	int getAuthroity();
	unsigned int getUid();
	unsigned int getSize();
	i_Time getCreateTime(); //返回Inode中的时间
	i_Time getChangeTime();
	char* getName();

	void setImode(i_FileMode fileMode);
	void setAuthority(int authority);
	void setName(char* name);

	void getSon(int* num, int* offset);
	void getBrother(int* num, int* offset);
	void getFather(int* num, int* offset, int *isSon);
	void getNextSon(int* num, int* offset);
	void getLastSon(int* num, int* offset);
	void setBrother(int num, int offset);
	void setSon(int num, int offset);
	char* getNextContent(int* length);
	void writeContent(char* content, int length);

	void delContent();
	void delFCB();
	void saveFCB();
	void showInTerminal();
};

Inode::Inode() {
	ext2 = new ext2_inode();
}

Inode::~Inode() {
	delete ext2;
}

Inode::Inode(int block_num, int offset) {
	ext2 = new ext2_inode();
	char* FCBbit = disk.read(block_num);
	ext2_inode_physical phyInode;
	int* convertB = (int*)(FCBbit);
	int* converP = (int*)(&phyInode);
	self_location = block_num;
	self_offset = offset;
	for (int j = 0, i = offset * 30; j < 30; i++, j++) {
		converP[j] = convertB[i];
	}
	delete[] FCBbit;
	int i_ABS = phyInode.i_ABMS;
	ext2->i_authority = __getAuthority(i_ABS);
	ext2->i_mode = __getMode(i_ABS);
	ext2->i_uid = phyInode.i_uid;
	ext2->i_size = phyInode.i_size;
	ext2->i_ctime = __ConvertIntToItime(phyInode.i_ctime);
	ext2->i_mtime = __ConvertIntToItime(phyInode.i_mtime);
	for (int i = 0; i < 39; i++) {
		ext2->i_name[i] = phyInode.i_name[i];
	}
	ext2->i_name[39] = 0;
	ext2->i_blocks = phyInode.blocks;
	for (int i = 0; i < 10; i++) {
		ext2->i_block[i] = phyInode.i_block[i];
	}
	ext2->i_son_outer = phyInode.i_son_outer;
	ext2->i_brother_outer = phyInode.i_brother_outer;
	ext2->i_last_outer = phyInode.i_last_outer;

	unsigned int other = ((unsigned int*)(phyInode.i_name))[10];
	ext2->is_last_father = other & 255;					//00000000 00000000 00000000 11111111
	ext2->i_last_inner = (other & 65280) >> 8;			//00000000 00000000 11111111 00000000
	ext2->i_son_inner = (other & 16711680) >> 16;		//00000000 11111111 00000000 00000000
	ext2->i_brother_inner = (other & 4278190080) >> 24; //11111111 00000000 00000000 00000000

	last_read_location = 0;
	last_read_offset = 0;
	content_location = 0;
}

void Inode::showInTerminal() {
	printf("File name: %s\n", ext2->i_name);
	printf("mode: ");
	switch (ext2->i_mode) {
	case 0: printf("none\n"); break;
	case 1: printf("directory\n"); break;
	case 2: printf("tet file\n"); break;
	case 3: printf("exe file\n"); break;
	case 4: printf("link\n"); break;
	case 5: printf("equipment\n"); break;
	}
	int authority = __getAuthority(ext2->i_authority);
	char cauthority[4];
	cauthority[2] = authority % 10 + 48; authority /= 10;
	cauthority[1] = authority % 10 + 48; authority /= 10;
	cauthority[0] = authority % 10 + 48;
	cauthority[3] = 0;
	printf("Authority: %s\n", cauthority);
	printf("user id: %d\n", ext2->i_uid);
	printf("size: %d\n", ext2->i_size);
	printf("create time: %d/%d/%d  %d:%d\n", ext2->i_ctime.YY, ext2->i_ctime.MM, 
		ext2->i_ctime.DD, ext2->i_ctime.hh, ext2->i_ctime.mm);
	printf("modify time: %d/%d/%d  %d:%d\n", ext2->i_mtime.YY, ext2->i_mtime.MM,
		ext2->i_mtime.DD, ext2->i_mtime.hh, ext2->i_mtime.mm);
	printf("blocks number: %d\n", ext2->i_blocks);

	printf("me pointer: %d-%d\n", self_location, self_offset);
	printf("son pointer: %d-%d\n", ext2->i_son_outer,ext2->i_son_inner);
	printf("brother pointer: %d-%d\n", ext2->i_brother_outer, ext2->i_brother_inner);
	printf("father pointer: %d-%d\n", ext2->i_last_outer, ext2->i_last_inner);
	printf("is last father or brother: ");
	if (ext2->is_last_father) {
		printf("father\n");
	}
	else {
		printf("brother\n");
	}


}

void Inode::writeContent(char* content, int length) {
	int blocks = ext2->i_blocks; 
	ext2->i_blocks++;
	ext2->i_size += length;
	
	int emp = disk.findEmpty();
	if (blocks <= 7) {
		ext2->i_block[blocks] = emp;
		disk.write(emp, content);
	}
	else if (blocks == 8) {
		ext2->i_block[8] = emp;
		int emp2 = disk.findEmpty();
		char* con = new char[4096];
		int* invert = (int*)(con);
		invert[0] = emp2;
		disk.write(emp, con);
		disk.write(emp2, content);
		delete[] con;
	}
	else if (blocks >8 && blocks <= 1031) {
		int loc1 = ext2->i_block[8];
		char* list1 = disk.read(loc1);
		int* invert = (int*)(list1);
		blocks -= 8;
		int emp2 = disk.findEmpty();
		invert[blocks] = emp2;
		disk.write(loc1, list1);
		disk.write(emp2, content);
		delete[] list1;
	}
	else if (blocks == 1032) {
		ext2->i_block[9] = emp;
		emp = disk.findEmpty();
	}
	if (blocks >= 1032 && (blocks - 1032) % 1024 == 0) {
		int loc1 = ext2->i_block[9];
		int index = (blocks - 1032) / 1024;
		char* list1 = disk.read(loc1);
		int* invert = (int*)(list1);
		invert[index] = emp;
		disk.write(loc1, list1);
		delete[] list1;
		
		int emp2 = disk.findEmpty();
		char* con = new char[4096];
		int* invert2 = (int*)(con);
		invert2[0] = emp2;
		disk.write(emp, con);
		disk.write(emp2, content);
		delete[] con;
	}
	else if (blocks >= 1032) {
		int loc1 = ext2->i_block[9];
		int index = (blocks - 1032) / 1024;
		char* list1 = disk.read(loc1);
		int* invert = (int*)(list1);

		int loc2 = invert[index];
		int index2 = blocks - 1032 - 1024 * index;
		char* list2 = disk.read(loc2);
		int* invert2 = (int*)(list2);
		invert2[index2] = emp;
		disk.write(loc2, list2);
		disk.write(emp, content);
		delete[] list1;
		delete[] list2;
	}
}

void Inode::delFCB() {
	delContent();
	int isfather = ext2->is_last_father;
	int last_num = ext2->i_last_outer;
	int last_offset = ext2->i_last_inner;
	int brother_num = ext2->i_brother_outer;
	int brother_offset = ext2->i_brother_inner;
	Inode node(last_num, last_offset);
	if (isfather) {
		node.setSon(brother_num, brother_offset);
	}
	else {
		node.setBrother(brother_num, brother_offset);
	}
	node.saveFCB();

	__FCBMinus();
	RootInfo root = getRoot();
	int location = root.current_block_location;
	int num = root.current_block_inode_number;

	char* FCBbit = disk.read(location);
	ext2_inode_physical phyInode;
	int* convertB = (int*)(FCBbit);
	int* converP = (int*)(&phyInode);
	for (int j = 0, i = num * 30; j < 30; i++, j++) {
		converP[j] = convertB[i];
	}
	delete[] FCBbit;

	unsigned int other = ((unsigned int*)(phyInode.i_name))[10];
	isfather = other & 255;					//00000000 00000000 00000000 11111111
	last_offset = (other & 65280) >> 8;			//00000000 00000000 11111111 00000000

	last_num = phyInode.i_last_outer;
	Inode node2(last_num, last_offset);
	if (isfather) {
		node.setSon(self_location, self_offset);
	}
	else {
		node.setBrother(self_location, self_offset);
	}

	char* blocks = disk.read(self_location);
	convertB = (int*)(blocks);
	converP = (int*)(&phyInode);
	for (int j = 0, i = self_offset * 30; j < 30; i++, j++) {
		convertB[i] = converP[j];
	}
	disk.write(self_location, blocks);
	delete[] blocks;
}

char* Inode::getNextContent(int* length) {
	int blocks = content_location;
	int lastSize = ext2->i_size - blocks * 4096;
	
	if (lastSize > 4096) {
		*length = 4096;
	}
	else if (lastSize <= 0) {
		*length = 0;
		return NULL;
	}
	else {
		*length = lastSize;
	}
	content_location++;
	if (blocks <= 7) {
		int location = ext2->i_block[blocks];
		return disk.read(location);
	}
	else if (blocks >= 8 && blocks <= 1031) {
		int loc1 = ext2->i_block[8];
		char* list1 = disk.read(loc1);
		int* invert = (int*)(list1);
		blocks -= 8;
		int loc2 = invert[blocks];
		delete[] list1;
		return disk.read(loc2);
	}
	if (blocks >= 1032) {
		int loc1 = ext2->i_block[9];
		int index = (blocks - 1032) / 1024;
		char* list1 = disk.read(loc1);
		int* invert = (int*)(list1);
		int loc2 = invert[index];
		delete[] list1;

		int index2 = blocks - 1032 - 1024 * index;
		char* list2 = disk.read(loc2);
		int* invert2 = (int*)(list2);
		int loc3 = invert2[index2];
		delete[] list2;
		return disk.read(loc3);
	}
}

void Inode::delContent() {
	int nodeNum = ext2->i_blocks;
	ext2->i_blocks = 0;
	int delN = nodeNum > 8 ? 8 : nodeNum;
	for (int i = 0; i < delN; i++) {
		int loc = ext2->i_block[i];
		disk.delFromOccupy(loc);
	}
	nodeNum -= 8;
	if (nodeNum <= 0) {
		return;
	}
	delN = nodeNum > 1024 ? 1024 : nodeNum;
	int loc1 = ext2->i_block[8];
	char* list1 = disk.read(loc1);
	int* invert1 = (int*)(list1);
	for (int i = 0; i < delN; i++) {
		int loc = invert1[i];
		disk.delFromOccupy(loc);
	}
	delete[] list1;
	disk.delFromOccupy(loc1);
	nodeNum -= 1024;
	if (nodeNum <= 0) {
		return;
	}
	loc1 = ext2->i_block[9];
	list1 = disk.read(loc1);
	invert1 = (int*)(list1);
	for (int i = 0; i < 1024; i++) {
		delN = nodeNum > 1024 ? 1024 : nodeNum;
		int loc2 = invert1[i];
		char* list2 = disk.read(loc2);
		int* invert2 = (int*)(list2);
		for (int i = 0; i < delN; i++) {
			int loc = invert2[i];
			disk.delFromOccupy(loc);
		}
		disk.delFromOccupy(loc2);
		delete[] list2;
		nodeNum -= 1024;
		if (nodeNum <= 0) {
			break;
		}
	}
	disk.delFromOccupy(loc1);
	delete[] list1;
}

void Inode::getNextSon(int* num, int* offset) {
	if (last_read_location == 0) {
		*num = ext2->i_son_outer;
		*offset = ext2->i_son_inner;
		last_read_location = ext2->i_son_outer;
		last_read_offset = ext2->i_son_inner;
	}
	else {
		Inode tempNode(last_read_location, last_read_offset);
		tempNode.getBrother(num, offset);
		last_read_location = *num;
		last_read_offset = *offset;
	}
}

void Inode::getLastSon(int* num, int* offset) {
	int temp_read_location = last_read_location;
	int temp_read_offset = last_read_offset;
	last_read_location = 0;
	last_read_offset = 0;

	int* Tnum = new int;
	int* Toffset = new int;
	
	getNextSon(Tnum, Toffset);
	
	if (*Tnum == 0) {
		*num = 0;
		*offset = 0;
	}
	else {
		while (true) {
			*num = *Tnum;
			*offset = *Toffset;
			getNextSon(Tnum, Toffset);
			if (*Tnum == 0) break;
		}
	}
	delete Tnum;
	delete Toffset;
	last_read_location = temp_read_location;
	last_read_offset = temp_read_offset;
}

int Inode::getAuthroity() {
	return __getAuthority(ext2->i_authority);
}

void Inode::getSon(int* num, int* offset) {
	*num = ext2->i_son_outer;
	*offset = ext2->i_son_inner;
}

void Inode::setSon(int num, int offset) {
	ext2->i_son_outer = num;
	ext2->i_son_inner = offset;
}

void Inode::getBrother(int* num, int* offset) {
	*num = ext2->i_brother_outer;
	*offset = ext2->i_brother_inner;
}

void Inode::setBrother(int num, int offset) {
	ext2->i_brother_outer = num;
	ext2->i_brother_inner = offset;
}

void Inode::getFather(int* num, int* offset, int *isSon) {
	*num = ext2->i_last_outer;
	*offset = ext2->i_last_inner;
	*isSon = ext2->is_last_father;
}

ext2_inode* Inode::getFCB() {
	return ext2;
}

i_FileMode Inode::getMode() {
	return ext2->i_mode;
}

i_Authority Inode::geteAuthority() {
	return ext2->i_authority;
}

unsigned int Inode::getUid() {
	return ext2->i_uid;
}

unsigned int Inode::getSize() {
	return ext2->i_size;
}

i_Time Inode::getCreateTime() {
	return ext2->i_ctime;
}

i_Time Inode::getChangeTime() {
	return ext2->i_ctime;
}

char* Inode::getName() {
	char* name = new char[40];
	for (int i = 0; i < 40; i++) {
		name[i] = ext2->i_name[i];
	}
	return name;
}

int Inode::__getBlocks() {
	return ext2->i_blocks;
}

void Inode::setImode(i_FileMode fileMode) {
	ext2->i_mode = fileMode;
}

void Inode::setName(char* name) {
	char* Bname = ext2->i_name;
	if (name[0] == 0)
		throw("Name cannot be empty");
	for (int i = 0; i < 38; i++) {
		if (name[i] == 0) {
			Bname[i] = 0;
			return;
		}
		Bname[i] = name[i];
	}
}

void Inode::__setChangeTime() {
	i_Time time = __getTimeNow();
	int* timeNow = (int*)(&time);
	int* timeB = (int*)(&ext2->i_mtime);
	for (int i = 0; i < 5; i++) {
		timeB[i] = timeNow[i];
	}
}

void Inode::setAuthority(int authority) {
	int Exe = authority % 10;
	authority /= 10;
	int Write = authority % 10;
	authority /= 10;
	int Read = authority % 10;
	ext2->i_authority.Execute_Visitor = Exe % 2; Exe /= 2;
	ext2->i_authority.Execute_Other = Exe % 2; Exe /= 2;
	ext2->i_authority.Execute_Me = Exe % 2;
	ext2->i_authority.Write_Visitor = Write % 2; Write /= 2;
	ext2->i_authority.Write_Other = Write % 2; Write /= 2;
	ext2->i_authority.Write_Me = Write % 2;
	ext2->i_authority.Read_Visitor = Read % 2; Read /= 2;
	ext2->i_authority.Read_Other = Read % 2; Read /= 2;
	ext2->i_authority.Read_Me = Read % 2;
}

i_Time Inode::__ConvertIntToItime(int time) {
	i_Time iTime;
	iTime.YY = (time & 31) + 2000;
	iTime.MM = (time >> 6) & 15;
	iTime.DD = (time >> 10) & 31;
	iTime.hh = (time >> 15) & 31;
	iTime.mm = (time >> 20) & 63;
	return iTime;
}


i_FileMode Inode::__getMode(int i_ABS) {
	i_FileMode mode;
	int res = i_ABS & 7;
	return (i_FileMode)(res);
}

i_Authority Inode::__getAuthority(int i_ABS) {
	i_Authority Authority;
	bool* authority = (bool*)(&Authority);
	int loc = 1 << 3;
	for (int i = 0; i < 9; i++) {
		authority[i] = i_ABS & loc;
		loc = loc << 1;
	}
	return Authority;
}

void Inode::createRoot() {
	char* content = disk.read(0);
	int* info = (int*)(content);
	int emp = disk.findEmpty();
	info[20] = 0;
	info[21] = 0;
	info[22] = 0;
	info[23] = emp;
	disk.write(0, content);
}

RootInfo Inode::getRoot() {
	RootInfo info;
	int* infoP = (int*)(&info);
	char* content = disk.read(0);
	int* infomation = (int*)(content);
	for (int j = 0; j < 4; j++) {
		infoP[j] = infomation[j + 20];
	}
	return info;
}
void Inode::__FCBPlus() {
	char* content = disk.read(0);
	unsigned int* con = (unsigned int*)(content);
	unsigned int num = con[22];
	unsigned int loc = con[23];
	num++;
	if (num < 30) {
		con[22] = num;
		disk.write(0, content);
	}
	else {
		int emp = disk.findEmpty();
		int lastlocation = loc;
		con[22] = 0;
		con[23] = emp;
		disk.write(0, content);
		char* newloc = new char[4096];
		int* convert = (int*)(newloc);
		convert[1000] = lastlocation;
		disk.write(emp, newloc);
		delete[] newloc;
	}
	delete[] content;
}

void Inode::__FCBMinus() {
	char* content = disk.read(0);
	unsigned int* con = (unsigned int*)(content);
	unsigned int num = con[22];
	unsigned int loc = con[23];
	if (num == 0) {
		char* newloc = disk.read(loc);
		int* convert = (int*)(newloc);
		int loc2 = convert[1000];
		delete[] newloc;
		disk.delFromOccupy(loc);
		con[22] = 30;
		con[23] = loc2;
		disk.write(0, content);
	}
	else {
		con[22]--;
		disk.write(0, content);
	}
	delete[] content;
}

void Inode::saveFCB() {
	ext2_inode_physical phyInode;
	int* p = (int*)(&phyInode);
	for (int i = 0; i < 30; i++) {
		p[i] = 0;
	}
	int i_ABS = 0;
	int authority = __getAuthority(ext2->i_authority);
	__setAuthority(&i_ABS, authority);
	__setImode(&i_ABS, ext2->i_mode);
	phyInode.i_ABMS = i_ABS;
	phyInode.i_size = ext2->i_size;
	phyInode.i_uid = ext2->i_uid;
	phyInode.i_ctime = __ConvertTimeToInt(ext2->i_ctime);
	phyInode.i_mtime = __ConvertTimeToInt(ext2->i_mtime);
	char* name = ext2->i_name;
	for (int i = 0; i < 39; i++) {
		if (name[i] == 0) {
			phyInode.i_name[i] = 0;
			break;
		}
		phyInode.i_name[i] = name[i];
	}
	phyInode.i_name[39] = 0;
	phyInode.i_name[40] = (char)ext2->is_last_father;
	phyInode.i_name[41] = (char)ext2->i_last_inner;
	phyInode.i_name[42] = (char)ext2->i_son_inner;
	phyInode.i_name[43] = (char)ext2->i_brother_inner;
	phyInode.blocks = ext2->i_blocks;
	for (int i = 0; i < 10; i++) {
		phyInode.i_block[i] = ext2->i_block[i];
	}
	phyInode.i_son_outer = ext2->i_son_outer;
	phyInode.i_last_outer = ext2->i_last_outer;
	phyInode.i_brother_outer = ext2->i_brother_outer;

	char* blocks = disk.read(self_location);
	int* convertB = (int*)(blocks);
	int* converP = (int*)(&phyInode);
	for (int j = 0, i = self_offset * 30; j < 30; i++, j++) {
		convertB[i] = converP[j];
	}
	disk.write(self_location, blocks);
	delete[] blocks;
}

void Inode::createFCB(int father_num,int father_offset,bool isson,
		int* create_num, int* create_offset,i_FileMode fileMode, 
		int uid, const char* name, int authority) {
	if (name[0] == 0)
		throw("name cannot be empty\n");
	ext2_inode_physical phyInode;
	int* p = (int*)(&phyInode);
	for (int i = 0; i < 30; i++) {
		p[i] = 0;
	}
	int i_ABS = 0;
	__setAuthority(&i_ABS, authority);
	__setImode(&i_ABS, fileMode);
	phyInode.i_ABMS = i_ABS;
	phyInode.i_uid = uid;
	phyInode.i_size = 0;
	phyInode.blocks = 0;

	i_Time time = __getTimeNow();
	int retime = __ConvertTimeToInt(time);
	phyInode.i_ctime = retime;
	phyInode.i_mtime = retime;
	phyInode.i_son_outer = 0;
	phyInode.i_brother_outer = 0;
	phyInode.i_last_outer = father_num;
	for (int i = 0; i < 39; i++) {
		if (name[i] == 0) {
			phyInode.i_name[i] = 0;
			break;
		}
		phyInode.i_name[i] = name[i];
	}
	phyInode.i_name[39] = 0;
	phyInode.i_name[40] = isson;
	char offset = (char)(father_offset);
	phyInode.i_name[41] = offset;
	phyInode.i_name[42] = 0;
	phyInode.i_name[43] = 0;
    RootInfo info = getRoot();
	int writeloc = info.current_block_location;
	int writenum = info.current_block_inode_number;
	*create_offset = writenum;
	*create_num = writeloc;
	char* blocks = disk.read(writeloc);
	int* convertB = (int*)(blocks);
	int* converP = (int*)(&phyInode);
	for (int j = 0, i = writenum * 30; j < 30; i++, j++) {
		convertB[i] = converP[j];
	}
	disk.write(writeloc, blocks); 
	delete[] blocks;
	__FCBPlus();
}

void Inode::__setAuthority(int* i_ABS, int authority) {
	int Exe = authority % 10;
	Exe = Exe << 9;
	(*i_ABS) = (*i_ABS) | Exe;
	authority /= 10;
	int Write = authority % 10;
	Write = Write << 6;
	(*i_ABS) = (*i_ABS) | Write;
	authority /= 10;
	int Read = authority % 10;
	Read = Read << 3;
	(*i_ABS) = (*i_ABS) | Read;
}

int Inode::__getAuthority(i_Authority authority) {
	int Authority = 0;
	bool* au = (bool*)(&authority);
	Authority += au[0] * 4 + au[1] * 2 + au[2];
	Authority *= 10;
	Authority += au[3] * 4 + au[4] * 2 + au[5];
	Authority *= 10;
	Authority += au[6] * 4 + au[7] * 2 + au[8];
	return Authority;
}

void Inode::__setImode(int* i_ABS, i_FileMode mode) {
	(*i_ABS) = (*i_ABS) | mode;
}

i_Time Inode::__getTimeNow() {
	tm* local;  //获取系统时间 
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	i_Time time;
	time.YY = local->tm_year + 1900;
	time.MM = local->tm_mon + 1;
	time.DD = local->tm_mday;
	time.hh = local->tm_hour;
	time.mm = local->tm_min;
	return time;
}

int Inode::__ConvertTimeToInt(i_Time t_time) {
	unsigned int time = 0;
	bool *p = new bool[32];
	int year = t_time.YY - 2000;
	time = year;
	int month = t_time.MM << 6;
	time = time | month;
	int day = t_time.DD << 10;
	time = time | day;
	int hour = t_time.hh << 15;
	time = time | hour;
	int minute = t_time.mm<<20;
	time = time | minute;
	return time;
}
