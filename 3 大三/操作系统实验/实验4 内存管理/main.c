#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXLIMIT 200
#define MINLIMIT 100
#define INITMEMORY 1024
int Pid=0;

typedef struct MA{
	int startaddress;			   //memory start address
	int size;					   //the size of this memory area
	int state;                     //0 stand for not occupied 
	int Pid;                       //the process's id
	struct MA *NextMemoryArea;     //link to next memory area 
}MemoryArea;

MemoryArea *MemoryStart=NULL;      //memory list start address
void InitMemory(int MemorySize){
	MemoryArea *TempArea=(MemoryArea*)malloc(sizeof(MemoryArea));  //create a struct
	TempArea->startaddress=0;
	TempArea->size=MemorySize;     //initiate memory size 
	TempArea->state=0;
	TempArea->NextMemoryArea=NULL;
	TempArea->Pid=0;
	MemoryStart=TempArea;
	srand(time(0));
}

MemoryArea* CreateProcess(int length){ 
	//create a process, return to this process
	//not to join this new process to memory list.
	//if length equal to zero, then it will create a random integer to length
	//range from MINLIMIT to MAXLIMIT
	if(length==0){
		length=rand()%(MAXLIMIT-MINLIMIT);
		length+=MINLIMIT;
	}
	MemoryArea *TempArea=(MemoryArea*)malloc(sizeof(MemoryArea));
	TempArea->size=length;
	TempArea->state=1;
	TempArea->Pid=++Pid;
	return TempArea;
}

int AddToMemory(MemoryArea *TempArea){ //join a process to memory list
	MemoryArea *p=MemoryStart;
	MemoryArea *pb=MemoryStart;
	while(p!=NULL){      //search a memory that will fit this process
		if(p->state==1 || p->size<TempArea->size) {
			pb=p;
			p=p->NextMemoryArea;
			continue;
		}
		//the first memory zone fit for the process will be allocated. 
		TempArea->startaddress=p->startaddress;
		if(p==pb){ //judge if this area is the first place of memory.
			TempArea->NextMemoryArea=MemoryStart;
			MemoryStart=TempArea;
		}
		else{
			pb->NextMemoryArea=TempArea;
			TempArea->NextMemoryArea=p;
		}
		p->startaddress+=TempArea->size;
		p->size-=TempArea->size;
		if(p->size==0){   //if the size left is zeor, delete this area.
			TempArea->NextMemoryArea=p->NextMemoryArea;
			free(p);
		}
		break;
	}
	if(p==NULL){
		printf("Process add to memory failed. Not enough memory can be allocated.\n");
		return 0;
	}
	
	else{
		printf("Process add to memory successfully.\n");
		return 1;
	}
}

void print(){    //print all the memory area. State parameter stand for process id.
	MemoryArea *p=MemoryStart;
	while(p!=NULL){
		if(p->state==0){
			printf("Start address:%5d. Memory size:%5d. State:null\n",
				p->startaddress,p->size);
		}
		else{
			printf("Start address:%5d. Memory size:%5d. State:%4d\n",
				p->startaddress,p->size,p->Pid);
		}
		
		p=p->NextMemoryArea;
	}
	printf("\n");
	
} 

int DeleteProcess(int Pid){   //Delete a process from memory.
	MemoryArea *p=MemoryStart;
	MemoryArea *pb=MemoryStart;
	int flag=0;
	while(p!=NULL){
		if(p->Pid!=Pid){
			pb=p;
			p=p->NextMemoryArea;
			continue;
		}
		flag=p->size;
		p->state=0;               //free the memory
		if(p!=pb && pb->state==0){
		    //meger this process area with the process before
			pb->size+=p->size;
			pb->NextMemoryArea=p->NextMemoryArea;
			pb->Pid=0;
			free(p);
			p=pb;
		}
		if(p->NextMemoryArea!=NULL && p->NextMemoryArea->state==0){
			//meger this process area with the process next
			pb=p->NextMemoryArea;
			p->size+=pb->size;
			p->NextMemoryArea=pb->NextMemoryArea;
			p->Pid=0;
			free(pb);
		}		
		break;
	}
	//if delete process successfully, return the size of this process
	//else return 0
	if(flag==0){
		printf("Delete process failed, please input correct process id.\n");
	}
	else{
		printf("Delete process:%d successful. Free memory:%d\n",Pid,flag);
	}
	return flag;
}

void DeleteAllProcess(){
	MemoryArea *p=MemoryStart;
	while(p!=NULL){
		MemoryArea *pn=p->NextMemoryArea;
		free(p);
		p=pn;
	}
	InitMemory(INITMEMORY);
	printf("Delete all the process successfully.\n");
}
int main(int argc, char *argv[]) {
	InitMemory(INITMEMORY);
	int i=0;
	for(i=0;i<4;i++){  //create 4 process
		MemoryArea *TempArea=CreateProcess(0);
		if(AddToMemory(TempArea)==0){
			free(TempArea);
			i--;       //if the process join to memory failed, try it again.
		}
	}
	print();           //list all the process
	int DeleteMemory=DeleteProcess(3);  
	print();
	DeleteMemory+=10;  //add 10 to the memory that just deleted
	MemoryArea *TempArea=CreateProcess(DeleteMemory);
	AddToMemory(TempArea);  //join a new process to the memory list
	print();
	DeleteProcess(1);
	print();
	DeleteProcess(2);
	print();
	TempArea=CreateProcess(0);
	AddToMemory(TempArea);  //join a new process to the memory list
	print();
	DeleteProcess(5);
	print();
	DeleteAllProcess();
	print();
	TempArea=CreateProcess(1024);  //create a process that occupy all the memory
	AddToMemory(TempArea);  
	print();
	DeleteProcess(7);
	print();
	TempArea=CreateProcess(1025);  //create a process that larger than memory. 
	AddToMemory(TempArea);
	return 0;
}
