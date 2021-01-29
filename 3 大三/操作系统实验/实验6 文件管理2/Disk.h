/*
*此文件为最底层的磁盘存取模块
*
*
*
*
*
*
*
*/

#include <fstream>
#include <time.h>
#include <io.h>

using namespace std;

struct DiskInformation {
	int isFull;
	int Is4K;
	int CreateYear;
	int CreateMonth;
	int CreateDay;
	int CreateHour;
	int CreateMinute;
};

class DiskPhysical {
private:
	DiskInformation __CreateDiskInformation(); //返回一个创建磁盘的信息
	int __FindEmptyFromMap(char* DiskMapBlock);  //通过读出的Map表找到空闲盘块
	char* __GetDiskName(int number); //将编号转化为路径
	int __SearchNotExistName();  //找一个磁盘块不存在的名字
public:
	DiskPhysical() {}
	char* ReadDisk(unsigned int block_num);  //根据盘块读一个内容
	void WriteDisk(unsigned int block_num, char* content);//写一个盘块，覆盖
	void CreateDisk();           //创建一个没有的盘块
	unsigned int SearchEmpty();  //注意这里返回的块号有32位，每块4kb，最多控制16Tb空间
	void AddToOccupy(unsigned int BlockNumber);  //将一个盘块增加占用
	void DelFromOccupy(unsigned int BlockNumber); //删掉一个盘块占用
	unsigned int GetLastDiskNum();
	DiskInformation getDiskInfo(int diskNum);
};

DiskInformation DiskPhysical::getDiskInfo(int diskNum) {
	char* file = ReadDisk(diskNum * 4096);
	int* num = (int*)(file);
	DiskInformation Info;
	int* info = (int*)(&Info);
	for (int j = 0; j < sizeof(Info); j++) {
		info[j] = num[j];
	}
	delete file;
	return Info;
}


unsigned int DiskPhysical::GetLastDiskNum() {
	return __SearchNotExistName();
}

unsigned int DiskPhysical::SearchEmpty() {
	for (int i = 0; i < 256; i++) {  //1层寻找，256大组
		char* fileName = __GetDiskName(i * 4096);
		int iRtn = _access(fileName, 0);
		if (iRtn == -1) return 0;  //如果没文件，返回0

		ifstream in(fileName, ios::binary);
		in.seekg(2 * 4096, ios::cur); //读取磁盘信息	
		char* DiskOccupyMap = new char[4096];
		in.read(DiskOccupyMap, 4096);
		int number = __FindEmptyFromMap(DiskOccupyMap);  //二层寻找，4096个磁盘为1个小组
		delete[] DiskOccupyMap;
		delete[] fileName;
		if (number == -1) continue;

		fileName = __GetDiskName(i * 4096 + number);//读取有空闲的16Mb块
		iRtn = _access(fileName, 0);
		if (iRtn == -1) return 0;  //如果没文件，返回0

		ifstream in2(fileName, ios::binary);
		in2.seekg(1 * 4096, ios::cur);
		DiskOccupyMap = new char[4096];
		in2.read(DiskOccupyMap, 4096);
		int InnerNumber = __FindEmptyFromMap(DiskOccupyMap);  //三层寻找，1个16Mb块有4096个盘块
		delete[] fileName;
		delete[] DiskOccupyMap;
		return (i * 4096 + number) * 4096 + InnerNumber;
	}
	return 0;
}

char* DiskPhysical::__GetDiskName(int number) {
	char* fileName = new char[13];
	fileName[0] = 'D';
	fileName[1] = 'i';
	fileName[2] = 's';
	fileName[3] = 'k';
	fileName[4] = '\\';
	for (int i = 11; i >= 5; i--) {
		fileName[i] = number % 10 + 48;
		number /= 10;
	}
	fileName[12] = 0;
	return fileName;
}

int DiskPhysical::__FindEmptyFromMap(char* DiskMapBlock) {
	unsigned int* Map = (unsigned int*)(DiskMapBlock);  //盘块中只有前512字节用于存储Map
	int i;
	for (i = 0; i < 128; i++) {
		if (Map[i] != 4294967295) {
			break;  //表示找到了空闲的盘块
		}
	}
	if (i == 128) return -1;  //表示没找到
	int number = Map[i];
	int j;
	int temp = 1;
	for (j = 0; j < 32; j++) {
		if ((number & temp) == 0) {
			break;
		}
		temp = temp << 1;
	}
	return i * 32 + j;

}


DiskInformation DiskPhysical::__CreateDiskInformation() {
	DiskInformation Information;
	Information.Is4K = 0;
	Information.isFull = 0;

	tm* local;  //获取系统时间 
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	Information.CreateYear = local->tm_year + 1900;
	Information.CreateMonth = local->tm_mon + 1;
	Information.CreateDay = local->tm_mday;
	Information.CreateHour = local->tm_hour;
	Information.CreateMinute = local->tm_min;
	return Information;
}

int DiskPhysical::__SearchNotExistName() {
	int i;
	for (i = 0; i < 256; i++) {
		char* fileName = __GetDiskName(i * 4096);
		int iRtn = _access(fileName, 0);
		delete fileName;
		if (iRtn == -1) break;  //1级循环
	}
	i--;
	int j;
	for (j = 1; j < 4096; j++) {
		char* fileName = __GetDiskName(i * 4096 + j);
		int iRtn = _access(fileName, 0);
		delete fileName;
		if (iRtn == -1) break;  //2级循环
	}
	if (i == -1) return 0;
	else return i * 4096 + j;

}

void DiskPhysical::DelFromOccupy(unsigned int BlockNumber) {
	if (BlockNumber == 0) return;
	int interLocation = BlockNumber % 4096;
	int outerLocation = BlockNumber / 4096;
	char* fileName = this->__GetDiskName(outerLocation);
	char* Map = new char[4096];
	fstream File(fileName, ios::out | ios::binary | ios::in);
	File.seekg(4096, ios::cur);  //读取指针
	File.read(Map, 4096);
	bool flag = false;
	if (this->__FindEmptyFromMap(Map) == -1) flag = true;  //如果子块已经满了，取消该状态

	int interA = interLocation % 8;
	int interB = interLocation / 8;
	int offset = 1 << interA;
	Map[interB] = Map[interB] & (~offset);
	File.seekp(4096, ios::beg);   //写入指针
	File.write(Map, 4096);
	File.close();

	if (flag == false) return;
	int MainBlockNum = outerLocation / 4096;
	int MainBlockLoc = outerLocation % 4096;
	fileName = this->__GetDiskName(MainBlockNum * 4096);
	fstream File2(fileName, ios::out | ios::binary | ios::in);
	File2.seekg(4096 * 2, ios::cur);
	File2.read(Map, 4096);
	interA = MainBlockLoc % 8;
	interB = MainBlockLoc / 8;
	offset = 1 << interA;
	Map[interB] = Map[interB] & (~offset);
	File2.seekp(4096 * 2, ios::beg);   //写入指针
	File2.write(Map, 4096);
	File2.close();
	delete[] fileName;
	delete[] Map;
}

void DiskPhysical::AddToOccupy(unsigned int BlockNumber) {
	if (BlockNumber == 0) return;
	int interLocation = BlockNumber % 4096;
	int outerLocation = BlockNumber / 4096;
	char* fileName = this->__GetDiskName(outerLocation);
	char* Map = new char[4096];
	fstream File(fileName, ios::out | ios::binary | ios::in);
	File.seekg(4096, ios::cur);  //读取指针
	File.read(Map, 4096);

	int interA = interLocation % 8;
	int interB = interLocation / 8;
	int offset = 1 << interA;
	Map[interB] = Map[interB] | offset;
	File.seekp(4096, ios::beg);   //写入指针
	File.write(Map, 4096);
	File.close();

	if (this->__FindEmptyFromMap(Map) != -1) return;  //如果子块已经满了，在大块中记录
	int MainBlockNum = outerLocation / 4096;
	int MainBlockLoc = outerLocation % 4096;
	fileName = this->__GetDiskName(MainBlockNum * 4096);
	fstream File2(fileName, ios::out | ios::binary | ios::in);
	File2.seekg(4096 * 2, ios::cur);
	File2.read(Map, 4096);
	interA = MainBlockLoc % 8;
	interB = MainBlockLoc / 8;
	offset = 1 << interA;
	Map[interB] = Map[interB] | offset;
	File2.seekp(4096 * 2, ios::beg);   //写入指针
	File2.write(Map, 4096);
	File2.close();
	delete[] fileName;
	delete[] Map;
}

void DiskPhysical::CreateDisk() {
	int name = __SearchNotExistName();
	char* fileName = __GetDiskName(name);
	DiskInformation InformationD = this->__CreateDiskInformation();

	ofstream outFile(fileName, ios::out | ios::binary);
	char* Information = new char[4096];
	int* Info = (int*)(Information);
	int* InfoD = (int*)(&InformationD);
	for (int i = 0; i < 7; i++) {
		Info[i] = InfoD[i];
	}
	outFile.write(Information, 4096);//先写一组磁盘信息

	for (int i = 0; i < 1024; i++) {
		Info[i] = 0;
	}
	Information[0] = 3;
	if (name % 4096 == 0) Information[0] = 7;
	outFile.write(Information, 4096);//将磁盘的占用信息写入，磁盘第二块中的前两位占用，如果是
									//4096的整数倍，第三块也占用
	Information[0] = 0;
	for (int i = 0; i < 4094; i++) {
		outFile.write(Information, 4096);
	}
	delete[] Information;
	outFile.close();
}

void DiskPhysical::WriteDisk(unsigned int block_num, char* content) {
	int innerLocation = block_num % 4096;  //16MB文件内部的块
	int outerLocation = block_num / 4096;  //外部的块
	char* fileName = this->__GetDiskName(outerLocation);

	fstream File(fileName, ios::out | ios::binary | ios::in);
	File.seekp(4096 * innerLocation, ios::beg);  //读取指针
	File.write(content, 4096);
	File.close();
	delete[] fileName;
}

char* DiskPhysical::ReadDisk(unsigned int block_num) {
	int innerLocation = block_num % 4096;  //16MB文件内部的块
	int outerLocation = block_num / 4096;  //外部的块
	char* fileName = this->__GetDiskName(outerLocation);

	ifstream in(fileName, ios::binary);
	in.seekg(innerLocation * 4096, ios::cur);
	char* flush = new char[4096];
	in.read(flush, 4096);
	in.close();
	delete[] fileName;
	return flush;
}




