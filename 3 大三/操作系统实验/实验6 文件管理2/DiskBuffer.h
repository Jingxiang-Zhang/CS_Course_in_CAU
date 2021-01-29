/*
磁盘缓冲

*/
#include "Disk.h"

class DiskB {
private:
	DiskPhysical DP;
public:
	DiskB(){}
	char* read(unsigned int block_num);  //根据盘块读一个内容
	void write(unsigned int block_num, char* content);//写一个盘块，覆盖
	unsigned int findEmpty();  //注意这里返回的块号有32位，每块4kb，最多控制16Tb空间
	void addToOccupy(unsigned int BlockNumber);  //将一个盘块增加占用
	void delFromOccupy(unsigned int BlockNumber); //删掉一个盘块占用
	unsigned int getLastDiskNum();
	DiskInformation getDiskInfo(int diskNum);

};

DiskInformation DiskB::getDiskInfo(int diskNum) {
	return DP.getDiskInfo(diskNum);
}


char* DiskB::read(unsigned int block_num) {
	return DP.ReadDisk(block_num);
}

void DiskB::write(unsigned int block_num, char* content) {
	DP.WriteDisk(block_num, content);
}

unsigned int DiskB::findEmpty() {
	unsigned int emp = DP.SearchEmpty();
	if (emp == 0) {
		DP.CreateDisk();
		emp = DP.SearchEmpty();
	}
	DP.AddToOccupy(emp);
	return emp;
}
void DiskB::addToOccupy(unsigned int BlockNumber) {
	DP.AddToOccupy(BlockNumber);
}
void DiskB::delFromOccupy(unsigned int BlockNumber) {
	DP.DelFromOccupy(BlockNumber);

}
unsigned int DiskB::getLastDiskNum() {
	return DP.GetLastDiskNum();
}