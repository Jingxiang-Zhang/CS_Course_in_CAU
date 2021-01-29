#include <stdio.h>
#include <stdlib.h>
#define CLEAR 1
#define SLEEPTIME 1

void gotoxy(int x, int y) {//cursor jump
	printf("%c[%d;%df",0x1B,x,y);
}
void Clear(){//using this functino to clear the screen
	gotoxy(0,0);
	int i=0;
	for(i=0;i<30;i++){
		printf("                                                                                     \n");
	}
	gotoxy(0,0);
}
typedef struct pcb{
	char pname[5];
	int runtime;	
	int lasttime;     //remain time
	int arrivetime;
	char state;		  //C stand for complete, R stand for ready
	int priority;     //no used
	int finishtime;
	struct pcb *next;
}PCB;

PCB *tail_input=NULL; //point to the tail of the queue
PCB *head_run=NULL;   //point to the location that prepare to be ran  
int SystemTime=0;

void InputProcess(){
	printf("Please input all the process information in need.\n");
	printf("Put \"null\" as process name stand for break the loop.\n\n\n");
	printf("ProcessName ArrivingTime RunningTime\n");
	while(1){
		char name[5];
		scanf("%s",&name);
		if(!strcmp(name,"null")){
			break;
		}
		int len=strlen(name);
		int arrave_time;
		int run_time;
		scanf("%d",&arrave_time);
		scanf("%d",&run_time);
		if(len>5){
			printf("Input failed: Process name should not surpass than 5 letters, while current name contain %d letters\n",len);
			continue;
		}
		PCB *now_process=(PCB*)malloc(sizeof(PCB));
		strcpy(now_process->pname,name);
		now_process->arrivetime=arrave_time;
		now_process->runtime=run_time;
		now_process->lasttime=run_time;
		now_process->state='R';
		now_process->priority=1;
		
		if(tail_input==NULL){
			tail_input=now_process;
			now_process->next=now_process;
		}
		else{
			now_process->next=tail_input->next;
			tail_input->next=now_process;
			tail_input=tail_input->next;
		}
	}
	head_run=tail_input->next;
} 
void ShowProcessStatue(){
	if(!tail_input){
		return;
	}
	printf("System Time: %d\n",SystemTime);
	printf("Current queue are as follow:\n");
	printf("  Name  RunTime  LastTime  ArriveTime  State  Priority  Finishtime:\n");
	PCB *p=tail_input->next;
	do{
		printf("%5s %7d %8d %7d %9c %8d %10d\n",p->pname,
				p->runtime,p->lasttime,p->arrivetime,p->state,p->priority,p->finishtime);
		p=p->next;
	}while(p!=tail_input->next);
}

int RunProcess(){
	if(!tail_input){//if the queue is empty, then return
		return 0;
	}
	PCB *current_process=head_run->next;
	do{//find a new process that prepare to be ran, this process's state must be ready 
	//and this process's arrive time must anticipate system time
		if(current_process->state=='R' && current_process->arrivetime<=SystemTime){
			break;
		}
		current_process=current_process->next;
	}while(current_process!=head_run->next);
	
	if(current_process->state!='R' || current_process->arrivetime>SystemTime){
		//if it did not find the proess which satisfy the condition, then it need to judge
		//  wether all the process in the queue has finished running.
		//if there still remain some processes did not enter the system, program can not quit
		//  otherwise document the nearest time that prepare to join the system.
		int Time=100000; 
		current_process=tail_input->next;
		do{
			if(current_process->arrivetime>SystemTime){
				//record the nearest progress time
				if(Time>current_process->arrivetime){
					Time=current_process->arrivetime;
				}
			}
			current_process=current_process->next;
		}while(current_process!=tail_input->next);
		if(Time==100000){ 
			//if no process anymore, which means the progress finish running, then return false.
			//otherwise Time will surrogate System time 
			return 0;
		} 
		else{
			printf("Since there is no current process ready at system time: %d\n",SystemTime);
			printf("Time add to %d to fit for the program\n",Time); 
			SystemTime=Time;
			return 1;
		}
	}
	SystemTime++;
	current_process->lasttime--;
	head_run=current_process;
	if(current_process->lasttime==0){
		//demostrate that current porcess has finished. 
		current_process->state='C';
		current_process->finishtime=SystemTime;
	}
	printf("Current Process: %5s\n",current_process->pname);
	return 1;
}
void Final(){
	if(!tail_input){
		return;
	}
	printf("System Time: %d\n",SystemTime);
	printf("Current queue are as follow:\n");
	printf("  Name  ArriveTime  RunTime  Finishtime  TurnaroundTime  WeightedTurnaroundTime:\n");
	PCB *p=tail_input->next;
	double AverageTT=0;
	double AverageWTT=0; 
	int num=0;
	do{
		int TurnaroundTime=p->finishtime-p->arrivetime;
		AverageTT+=(double)(TurnaroundTime);
		double WeightedTurnaroundTime=(double)(TurnaroundTime)/(double)(p->runtime);
		AverageWTT+=WeightedTurnaroundTime;
		num++;
		printf("%5s %8d %9d %9d %12d %21.2f\n",p->pname,
				p->arrivetime,p->runtime,p->finishtime,TurnaroundTime,WeightedTurnaroundTime);
		p=p->next;
	}while(p!=tail_input->next);
	AverageTT=AverageTT/(double)(num);
	AverageWTT=AverageWTT/(double)(num);
	printf("\nAverage turnaround time: %.2f, Average weighted turnaround time: %.2f\n\n",AverageTT,AverageWTT);
}
int main(int argc, char *argv[]) {
	InputProcess();
	if(CLEAR) Clear();
	while(RunProcess()){
		ShowProcessStatue();
		printf("\n\n");
		sleep(SLEEPTIME);
		if(CLEAR) Clear();
	}
	Final();
	return 0;
}
