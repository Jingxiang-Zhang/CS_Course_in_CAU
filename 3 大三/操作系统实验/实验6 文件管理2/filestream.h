#pragma once
/*
注：单文件家下最多有





*/
#include "FCB.h"
#include <string>
#define ROOT 0
#define VISITOR 60000

struct fileInfo {
	char* name;
	int authority;
	int uid;
	int size;
	i_FileMode mode;
	i_Time ctime;
	i_Time mtime;
	int blocknum;
	int blockoffset;
	int sonnum;
	int sonoffset;
};

enum fileOpenMode {
	readmode = 1,
	writemode = 2,
	exemode = 4,
	create = 8
};

enum seek_mode{
	beg = 1,
	cur = 2,
	end = 3
};

struct progress {
	int exist;
	fileOpenMode openMode;
	unsigned int PCBlocation;
	unsigned int PCBoffset;
};

class FileStream {
private:
	fileInfo FileRoute[100];
	int now_depth;
	int uid;
	Inode fcb;

	unsigned int lastSonLocation;
	unsigned int lastSonOffset;

	int openFileLocation;
	int openFileOffset;
	char writeBuffer[4096];
	int currentSize;
	int filePointer;
	int fileSize;
	fileOpenMode openMode;
	i_FileMode fileMode;
	progress currentPorgress[100];
	
	void __delFile(unsigned int num, unsigned int offset);
	int __findEmptyProgress(fileOpenMode openMode, unsigned int PCBlocation, unsigned int PCBoffset);
public:
	FileStream(int userid);
	FileStream();
	fileInfo getRoot();
	
	int formatDisk();
	int getBatchSon(fileInfo* info, int number);
	int getBatchSon(int num, int offset, fileInfo* info, int length);
	void getPWD();
	int cdDirectory(const char* name);
	void setUid(int uid);
	int getUid();
	void depthDeduce();
	void depthToOne();
	void getNodeByName(const char* name, unsigned int* num, unsigned int* offset, i_FileMode mode);
	void showopen();

	int mk(char* name, int aut,i_FileMode mode);
	void openFile(char* name, fileOpenMode openMode);
	void closeFile(char* name);
	void writeFile(char* name, char* content, int length);
	char* readFile(char* name,int *length);
	void flush();
	void seekg(int pos, seek_mode mode);
	void seekp(int pos, seek_mode mode);
	void read(char *content, int length);

	void delFile(char* name);
	void moveFile(char* From, char* To);
};

FileStream::FileStream(int userid) {
	uid = userid;
	uid = 61000;
	Inode node(3, 0);
	FileRoute[0].name = new char[5]{ 'r','o','o','t' };
	FileRoute[0].authority = 777;
	FileRoute[0].mode = i_FileMode::Content;
	FileRoute[0].uid = 0;
	FileRoute[0].blocknum = 3;
	FileRoute[0].blockoffset = 0;
	node.getSon(&FileRoute[0].sonnum, &FileRoute[0].sonoffset);
	lastSonLocation = 0;
	lastSonOffset = 0;
	now_depth = 1;
	for (int i = 0; i < 100; i++) {
		currentPorgress[i].exist = 0;
	}
}

FileStream::FileStream() {
	uid = 61000;
	Inode node(3, 0);
	FileRoute[0].name = new char[5]{ 'r','o','o','t' };
	FileRoute[0].authority = 777;
	FileRoute[0].mode = i_FileMode::Content;
	FileRoute[0].uid = 0;
	FileRoute[0].blocknum = 3;
	FileRoute[0].blockoffset = 0;
	node.getSon(&FileRoute[0].sonnum, &FileRoute[0].sonoffset);	
	lastSonLocation = 0;
	lastSonOffset = 0;
	now_depth = 1;
	for (int i = 0; i < 100; i++) {
		currentPorgress[i].exist = 0;
	}
}

fileInfo FileStream::getRoot() {
	return FileRoute[0];
}

void FileStream::setUid(int uid) {
	this->uid = uid;
}
int FileStream::getUid() {
	return uid;
}

void FileStream::depthDeduce() {
	if (now_depth >= 2)
		now_depth--;
}

void FileStream::depthToOne() {
	now_depth = 1;
}

void FileStream::showopen() {
	for (int i = 0; i < 100; i++) {
		if (currentPorgress[i].exist == 1) {
			printf("%d %d %d", currentPorgress[i].openMode, currentPorgress[i].PCBlocation, currentPorgress[i].PCBoffset);
		}
	}
	printf("\n\n");
}

int FileStream::__findEmptyProgress(fileOpenMode openMode, unsigned int PCBlocation, unsigned int PCBoffset) {
	for (int i = 0; i < 100; i++) {
		if (currentPorgress[i].exist == 1 && currentPorgress[i].PCBlocation == PCBlocation
			&& currentPorgress[i].PCBoffset == PCBoffset && currentPorgress[i].openMode == fileOpenMode::writemode) {
			return -1;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (currentPorgress[i].exist == 1) {
			continue;
		}
		currentPorgress[i].exist = 1;
		currentPorgress[i].openMode = openMode;
		currentPorgress[i].PCBlocation = PCBlocation;
		currentPorgress[i].PCBoffset = PCBoffset;
		return 0;
	}
	return -1;
}

void FileStream::openFile(char* name, fileOpenMode openMode) {
	unsigned int num;
	unsigned int offset;
	getNodeByName(name, &num, &offset, i_FileMode::File);
	if (num == 0 && openMode != fileOpenMode::create) {
		printf("file not find.\n");
		return;
	}
	__findEmptyProgress(openMode, num, offset);
	if (openMode == fileOpenMode::create) {
		mk(name, 777, i_FileMode::File);
	}
}

void FileStream::writeFile(char *name,char* content, int length) {

	unsigned int num=0;
	unsigned int offset=0;
	getNodeByName(name, &num, &offset, i_FileMode::File);
	int i;
	for (i = 0; i < 100; i++) {
		if (currentPorgress[i].exist == 1 && currentPorgress[i].PCBlocation == num
			&& currentPorgress[i].PCBoffset == offset) {
			break;
		}
	}
	if (i == 100) {
		printf("file not open.\n");
		return;
	}
	Inode node(num, offset);
	node.delContent();
	node.writeContent(content, strlen(content));
	node.saveFCB();
}

char* FileStream::readFile(char* name, int* length) {
	unsigned int num;
	unsigned int offset;
	getNodeByName(name, &num, &offset, i_FileMode::File);
	int i;
	for (i = 0; i < 100; i++) {
		if (currentPorgress[i].exist == 1 && currentPorgress[i].PCBlocation == num
			&& currentPorgress[i].PCBoffset == offset) {
			break;
		}
	}
	if (i == 100) {
		printf("file not open.\n");
		*length = 0;
		return NULL;
	}
	
	Inode node(num, offset);
	return node.getNextContent(length);
}

void FileStream::closeFile(char* name) {
	unsigned int num;
	unsigned int offset;
	getNodeByName(name, &num, &offset, i_FileMode::File);
	for (int i = 0; i < 100; i++) {
		if (currentPorgress[i].exist == 1 && currentPorgress[i].PCBlocation == num
			&& currentPorgress[i].PCBoffset == offset) {
			currentPorgress[i].exist = 0;
			return ;
		}
	}

}

void FileStream::__delFile(unsigned int num, unsigned int offset) {
	Inode node(num, offset);
	//printf("%d   %d\n", num, offset);
	if (node.getUid() == uid || uid == ROOT || node.geteAuthority().Write_Other == true) {
		if (node.getMode() != i_FileMode::Content) {
			node.delFCB();
			return;
		}
		fileInfo* info = new fileInfo[1024];
		int length = getBatchSon(num, offset, info, 1024);
		for (int i = 0; i < length; i++) {
			__delFile(info[i].blocknum, info[i].blockoffset);
		}
		
		node.delFCB();
	}
}

void FileStream::delFile(char* name) {
	unsigned int num = 0;
	unsigned int offset = 0;
	getNodeByName(name, &num, &offset, i_FileMode::Content);
	if (num == 0) return;
	else __delFile(num, offset);
}

void FileStream::getNodeByName(const char* name, unsigned int *num, unsigned int *offset, i_FileMode mode) {
	lastSonLocation = 0;
	lastSonOffset = 0;
	*num = 0;
	*offset = 0;
	while (true) {
		fileInfo *FileInfo = new fileInfo[100];
		int length = getBatchSon(FileInfo, 100);
		
		if (length == 0) break;
		for (int i = 0; i < length; i++) {
			if (strcmp(FileInfo[i].name, name) == 0 && FileInfo[i].mode == mode) {
				*num = FileInfo[i].blocknum;
				*offset = FileInfo[i].blockoffset;
				break;
			}
		}
		if (*num != 0 || length <= 100)
			break;
	}
}

int FileStream::formatDisk() {
	if (uid != ROOT) {
		return -1;
	}
	system("rd /s/q Disk");
	string command = "mkdir Disk";
	system(command.c_str());
	fcb.createRoot();
	int num;
	int offset;
	fcb.createFCB(0, 0, 1, &num, &offset, i_FileMode::Content, 0, "root", 777);

	return 1;
}

int FileStream::mk(char* name,int aut=777, i_FileMode mode= i_FileMode::Content) {
	unsigned int num;
	unsigned int offset;
	getNodeByName(name, &num, &offset, mode);
	if (num != 0) {
		return 0;
	}
	int id = FileRoute[now_depth - 1].uid;
	num = FileRoute[now_depth - 1].blocknum;
	offset = FileRoute[now_depth - 1].blockoffset;
	Inode node(num, offset);
	i_Authority authority = node.geteAuthority();
	if (id != uid && uid != ROOT) {
		if (id >= VISITOR) {
			if (authority.Write_Visitor == 0) {
				return -1;
			}
		}
		else {
			if (authority.Write_Other == 0) {
				return -1;
			}
		}
	}
	int son;
	int sonoffset;
	node.getLastSon(&son, &sonoffset);
	int newFCBnum;
	int newFCBoffset;
	if (son == 0) {
		node.createFCB(num, offset, 1, &newFCBnum, &newFCBoffset, mode, uid, name, aut);
		node.setSon(newFCBnum, newFCBoffset);
		node.saveFCB();
	}
	else {
		node.createFCB(son, sonoffset, 0, &newFCBnum, &newFCBoffset, mode, uid, name, aut);
		Inode brothernode(son, sonoffset);
		brothernode.setBrother(newFCBnum, newFCBoffset);
		brothernode.saveFCB();
	}
	return 1;
}

int FileStream::cdDirectory(const char* name) {
	unsigned int num;
	unsigned int offset;
	getNodeByName(name, &num, &offset, i_FileMode::Content);
	if (num == 0) {
		return 0;
	}
	Inode node(num, offset);
	i_Authority authority = node.geteAuthority();
	int id = node.getUid();
	if (id != uid && uid != ROOT) {
		if (id >= VISITOR) {
			if (authority.Read_Visitor == 0) {
				return -1;
			}
		}
		else {
			if (authority.Read_Other == 0) {
				return -1;
			}
		}
	}
	FileRoute[now_depth].authority = node.getAuthroity();
	FileRoute[now_depth].blocknum = num;
	FileRoute[now_depth].blockoffset = offset;
	FileRoute[now_depth].ctime = node.getCreateTime();
	FileRoute[now_depth].mtime = node.getChangeTime();
	FileRoute[now_depth].mode = i_FileMode::Content;
	FileRoute[now_depth].name = new char[40];
	for (int i = 0; i < 40; i++) {
		FileRoute[now_depth].name[i] = name[i];
	}
	FileRoute[now_depth].size = node.getSize();
	node.getSon(&FileRoute[now_depth].sonnum, &FileRoute[now_depth].sonoffset);
	now_depth++;
	return 1;
}

void FileStream::getPWD() {
	string pwd = "root:";
	
	for (int i = 1; i < now_depth; i++) {
		char* name = FileRoute[i].name;
		pwd.append("\\");
		pwd.append(name);
	}
	pwd.append(">");
	printf("%s", pwd.c_str());
	 
}

int FileStream::getBatchSon(int num, int offset, fileInfo* info, int length) {
	int size = 0;
	int sonLoc = num;
	int sonOffset = offset;
	Inode inode(sonLoc, sonOffset);
	inode.getSon(&sonLoc, &sonOffset);
	if (sonLoc == 0) {
		return 0;
	}
	Inode inode2(sonLoc, sonOffset);
	info[0].authority = inode2.getAuthroity();
	char* c = inode2.getName();
	info[0].name = new char[40];
	
	for (int j = 0; j < 40; j++) {
		info[0].name[j] = c[j];
	}
	info[0].ctime = inode2.getCreateTime();
	info[0].mtime = inode2.getChangeTime();
	info[0].size = inode2.getSize();
	info[0].uid = inode2.getUid();
	info[0].blocknum = sonLoc;
	info[0].blockoffset = sonOffset;
	info[0].mode = inode2.getMode();
	size++;
	inode2.getBrother(&sonLoc, &sonOffset);
	if (sonLoc == 0)
		return 1;
	for (int i = 1; i < length; i++) {
		Inode inode2(sonLoc, sonOffset);
		
		info[i].authority = inode2.getAuthroity();
		char* c = inode2.getName();
		info[i].name = new char[40];
		for (int j = 0; j < 40; j++) {
			info[i].name[j] = c[j];
		}
		info[i].ctime = inode2.getCreateTime();
		info[i].mtime = inode2.getChangeTime();
		info[i].size = inode2.getSize();
		info[i].uid = inode2.getUid();
		info[i].blocknum = sonLoc;
		info[i].blockoffset = sonOffset;
		info[i].mode = inode2.getMode();
		size++;
		inode2.getBrother(&sonLoc, &sonOffset);
		if (sonLoc == 0)
			break;

	}

	lastSonLocation = sonLoc;
	lastSonOffset = sonOffset;
	return size;
}

int FileStream::getBatchSon(fileInfo* info, int length) {
	if (FileRoute[0].mode != i_FileMode::Content) {
		return -1;
	}
	
	int sonLoc;
	int sonOffset;
	if (lastSonLocation == 0) {
		sonLoc = FileRoute[now_depth - 1].blocknum;
		sonOffset = FileRoute[now_depth - 1].blockoffset;
	}
	else {
		sonLoc = lastSonLocation;
		sonOffset = lastSonOffset;
	}

	return getBatchSon(sonLoc, sonOffset, info, length);
}
