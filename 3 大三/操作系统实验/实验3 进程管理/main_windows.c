#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define CLEAR 0
#define SLEEPTIME 1000

void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
    SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}
void Clear(){
	gotoxy(0,0);
	int i=0;
	for(i=0;i<20;i++){
		printf("                                                                        \n");
	}
	gotoxy(0,0);
}
typedef struct pcb{
	char pname[5];
	int runtime;		//运行时间
	int lasttime;       //剩余运行时间 
	int arrivetime;		//到达时间
	char state;			//进程状态
	int priority;		//进程优先级
	int finishtime;     //进程结束时间
	struct pcb *next;	//链接指针
}PCB;

PCB *tail_input=NULL;        //就绪队列队尾元素 
PCB *head_run=NULL;          //运行队列指针 
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
	if(!tail_input){//如果队列为空，直接返回结束 
		return 0;
	}
	PCB *current_process=head_run->next;
	do{//从当前队列的执行位置找到一个新的进程，此进程的状态为准备好并且进程的到达时间大于系统时间 
		if(current_process->state=='R' && current_process->arrivetime<=SystemTime){
			break;
		}
		current_process=current_process->next;
	}while(current_process!=head_run->next);
	
	if(current_process->state!='R' || current_process->arrivetime>SystemTime){
	//如果没有找到满足条件的进程，需要判断队列是否全部执行完
	//如果有的进程还没有进入系统，则程序依然不可以退出，否则记录最短的有进程进入的时间
		int Time=100000; 
		current_process=tail_input->next;
		do{
			if(current_process->arrivetime>SystemTime){
				//记录最短的有进程进入的时间 
				if(Time>current_process->arrivetime){
					Time=current_process->arrivetime;
				}
			}
			current_process=current_process->next;
		}while(current_process!=tail_input->next);
		//如果没有进程了，说明都执行完毕了，返回false，否则时间加到最近加入进程的时间 
		if(Time==100000){
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
		//此时说明这个进程执行完了
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
	printf("\nAverage turnaround time: %.2f, Average weighted turnaround time: %.2f",AverageTT,AverageWTT);
}
int main(int argc, char *argv[]) {
	InputProcess();
	while(RunProcess()){
		ShowProcessStatue();
		printf("\n\n");
		Sleep(SLEEPTIME);
		if(CLEAR) Clear();
	}
	Final();
	int a;
	scanf("%d",&a);
	return 0;
}
