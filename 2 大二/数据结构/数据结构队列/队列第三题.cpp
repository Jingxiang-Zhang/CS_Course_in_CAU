#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<queue>
#include<iomanip> 
#include<conio.h>
#include<windows.h>
 
using namespace std;
struct car_que{
	int refuel_time;
	int car_number;
};
void gotoxy(int x,int y)
{
	COORD c;
	c.X=x;c.Y=y;
	SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int describe_in_graphic(queue<car_que> a,int size,car_que b[],int CARNUMBER=0){
	static bool isfirst=true;
	static int time=-1;
	time++;
	if(isfirst){
		gotoxy(0,0);
		for(int i=0;i<CARNUMBER+10;i++)
			cout<<"                                                                                       \n";
		isfirst=false;
		gotoxy(0,10);
		cout<<"正在排队的车有"<<a.size()<<"辆。";
		for(int i=0;i<size;i++){
			gotoxy(30,8+i*2);
			cout<<setw(2)<<i+1<<"号加油窗口排队车辆为：  "<<"，剩余   s";
		}
		gotoxy(0,15);
		cout<<"现在时间为："<<setw(2)<<time<<"s";
	}
	else{
		gotoxy(14,10); cout<<"  \b\b"<<a.size();
		gotoxy(12,15); cout<<setw(2)<<time;
		for(int i=0;i<size;i++){
			if(b[i].refuel_time!=-1){
				gotoxy(52,8+i*2);
				cout<<b[i].car_number+1;
				gotoxy(62,8+i*2);
				cout<<"  \b\b"<<b[i].refuel_time;
			}
			else {
				gotoxy(30,8+i*2);
				cout<<"                                           "; 
			}
		}
	}
	return time;
}
int main(int argc, char** argv) {
	int CARNUMBER=100,maxtime=100,mintime=100;
	while(!(CARNUMBER<100&&CARNUMBER>=1)){
		cout<<"请输入汽车数量（小于100）：";
		cin>>CARNUMBER;
	}
	while(!(maxtime<100&&maxtime>=1)){
		cout<<"请输入汽车加油最大时间（小于100）：";
		cin>>maxtime;
	}
	while(!(mintime<100&&mintime>=1) || mintime>=maxtime){
		cout<<"请输入汽车加油最小时间（小于100且小于最大时间）：";
		cin>>mintime;
	}
	queue<car_que> first_step_car_queue;
	srand((int)time(0));
	cout<<"\n创建一组汽车的排队队列，长度为"<<CARNUMBER<<
		"，汽车加油时间最大为"<<maxtime<<"s，最小为"<<mintime<<"s。\n"; 
	for(int i=0;i<CARNUMBER;i++){
		car_que temp;
		temp.car_number=i;
		int time;
		while(true){
			time=rand()%maxtime;
			if(time>=mintime) break;
		}
		temp.refuel_time=time;
		first_step_car_queue.push(temp);
		cout<<"第"<<setw(2)<<i<<"辆车加油时间为"<<temp.refuel_time<<endl;
	}
	cout<<"汽车队列第一阶段排列创建完成。"<<endl<<endl;
	int length=100;
	while(!(length<11&&length>=1)){
		cout<<"请输入加油站的加油机总数(小于12)：";
		cin>>length;
	}
	
	car_que second_step_car_queue[length];
	for(int i=0;i<length;i++)
		second_step_car_queue[i].refuel_time=0;
	cout<<"按下任意键进入加油阶段";
	int sumtime;
	getch();
	bool flag=true;
	describe_in_graphic(first_step_car_queue,length,second_step_car_queue,CARNUMBER);
	while(!first_step_car_queue.empty()||flag){
		for(int i=0;i<length;i++){
			if(second_step_car_queue[i].refuel_time<=0){
				if(!first_step_car_queue.empty()){
					second_step_car_queue[i]=first_step_car_queue.front();
					first_step_car_queue.pop();
				}
				else 
					second_step_car_queue[i].refuel_time=-1;
			}
			else
				second_step_car_queue[i].refuel_time--;;
		}
		int k;
		for(k=0;k<length;k++)
			if(second_step_car_queue[k].refuel_time !=-1) break;
		if(k==length) flag=false;
		sumtime=describe_in_graphic(first_step_car_queue,length,second_step_car_queue);
		Sleep(1000);
	}
	gotoxy(20,20);
	cout<<"排队结束，总用时为"<<sumtime<<"s,按下任意键结束"; 
	getch();
	return 0;
}
