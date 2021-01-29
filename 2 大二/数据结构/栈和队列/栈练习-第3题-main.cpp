#include <iostream>
#include <windows.h>
#include <vector>
#include <stack>
#include <conio.h>
#include <queue>
using namespace std;
void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
    SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置 
}
BOOL SetConsoleColor(WORD wAttributes)  
{  
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
    if (hConsole == INVALID_HANDLE_VALUE)  
        return FALSE;  
    return SetConsoleTextAttribute(hConsole, wAttributes);  
}  
void clear(){
	gotoxy(0,0);
	static bool hasclear=false;
	SetConsoleColor(BACKGROUND_INTENSITY| BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	if(hasclear==false){
		for(int i=0;i<60;i++){
			printf("                                                                                                                       ");
			printf("\n");
		}
		hasclear=true;
	}	
	else{
		gotoxy(0,0);
		for(int i=0;i<60;i++){
			printf("                 ");
			printf("\n");
		}
	}
	gotoxy(0,0);
}
struct rundata{
	int lastx,lasty;
	int locationx,locationy;
	bool isused;
	rundata(){
		isused=false;
	}
};
struct walk{
	int x,y;
	walk(int a,int b){
		x=a;y=b;
	}
};
walk nextwalk[4]={walk(1,0),walk(-1,0),walk(0,1),walk(0,-1)};
class game{
	private:
		int game_map[10][10];
		rundata game_map_information[10][10];
		static const int size=10;
		stack<rundata> information;
		int beginx,beginy;
		int endx,endy;
		bool found;
		int length,searchlength;
	public:
		void create_map();
		void paint_map();
		void paint_point(int mumber);
		void DFS();
		void DFSmove(int x,int y);	
		void DFSoutprocess();
		void BFS();
		void BFSoutprocess();
};
void game::BFSoutprocess(){
	int x=game_map_information[endx][endy].lastx;
	int y=game_map_information[endx][endy].lasty;
	
	while(!(x==8&&y==8)){
		length++; 
		Sleep(300); 
		gotoxy(y*2,x);
		paint_point(2);
		x=game_map_information[x][y].lastx;
		y=game_map_information[x][y].lasty;	
	}	
	gotoxy(30,3);
	SetConsoleColor(BACKGROUND_INTENSITY| BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout<<"使用广度优先算法，路程总长度："<<length+1<<"，探索总数量："<<searchlength<<"。";
	gotoxy(34,4);
	cout<<"探索路程的总长度与探索的先后顺序基本无关，是最优解。";
	
}
void game::BFS(){
	queue<rundata> dataqueue;
	game_map_information[beginx][beginy].lastx=-1;
	game_map_information[beginx][beginy].lasty=-1;
	game_map_information[beginx][beginy].locationx=beginx;
	game_map_information[beginx][beginy].locationy=beginy;
	game_map_information[beginx][beginy].isused=true;
	dataqueue.push(game_map_information[beginx][beginy]);
	while(!dataqueue.empty()){
		rundata temp=dataqueue.front();
		int x=temp.locationx,y=temp.locationy;
		dataqueue.pop();
		for(int i=0;i<4;i++){	
	    	searchlength++;	
			int newx=x+nextwalk[i].x;
			int newy=y+nextwalk[i].y;	  
			if(newx<=0||newx>=9||newy<=0||newy>=9) continue;   //出界处理
			if(newx==endx&&newy==endy) {            //找到终点 
				game_map_information[endx][endy].lastx=x;
				game_map_information[endx][endy].lasty=y;
				game_map_information[endx][endy].locationx=endx;
				game_map_information[endx][endy].locationy=endy;
				dataqueue.push(game_map_information[endx][endy]);
				return;
			}
			if(game_map[newx][newy]==1) continue;            //碰到墙
			if(	game_map_information[newx][newy].isused==true) //之前走过了 
				continue;
			game_map_information[newx][newy].lastx=x;
			game_map_information[newx][newy].lasty=y;
			game_map_information[newx][newy].locationx=newx;
			game_map_information[newx][newy].locationy=newy;
			game_map_information[newx][newy].isused=true;
	//	    cout<<x<<" "<<y<<" "<<newx<<" "<<newy<<endl;
			dataqueue.push(game_map_information[newx][newy]);
		}
	}
}
void game::DFSoutprocess(){
	gotoxy(30,1);
	SetConsoleColor(BACKGROUND_INTENSITY| BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout<<"使用深度优先算法，路程总长度："<<length+1<<"，探索总数量："<<searchlength<<"。";
	gotoxy(34,2);
	cout<<"探索路程的总长度与探索的先后顺序有关，且不是最优解。"; 
	rundata temp;
	while(!information.empty()){
		temp=information.top();
		information.pop();
		if(temp.lastx!=-1){
        	gotoxy(temp.lasty*2,temp.lastx);
			paint_point(2);
		}
		Sleep(300);
	}
}
void game::DFS(){
	game_map_information[beginx][beginy].lastx=-1;
	game_map_information[beginx][beginy].lasty=-1;
	game_map_information[beginx][beginy].isused=true;
	information.push(game_map_information[beginx][beginy]);
	DFSmove(beginx,beginy);
}
void game::DFSmove(int x,int y){
	for(int i=0;i<4;i++){	
	    searchlength++;	
		int newx=x+nextwalk[i].x;
		int newy=y+nextwalk[i].y;	  
		if(newx<=0||newx>=9||newy<=0||newy>=9) continue;   //出界处理
		if(newx==endx&&newy==endy) {            //找到终点 
			game_map_information[endx][endy].lastx=x;
			game_map_information[endx][endy].lasty=y;
			information.push(game_map_information[endx][endy]);
			found=true;
			return;
		}
		if(game_map[newx][newy]==1) continue;            //碰到墙
		if(	game_map_information[newx][newy].isused==true) //之前走过了 
			continue;
		game_map_information[newx][newy].lastx=x;
		game_map_information[newx][newy].lasty=y;
		game_map_information[newx][newy].isused=true;
		information.push(game_map_information[newx][newy]);	
		length++;	
		DFSmove(newx,newy);
		if(found==true) return ;
		length--;
		game_map_information[newx][newy].isused=false;
		information.pop();
	}
}
void game::create_map(){
	memset(game_map,0,sizeof(game_map));
	for(int i=0;i<size;i++){
		game_map[0][i]=1;
		game_map[size-1][i]=1;
		game_map[i][0]=1;
		game_map[i][size-1]=1;
	} 
	game_map[1][3]=1;	game_map[2][3]=1;	game_map[1][7]=1;
	game_map[2][7]=1;	game_map[3][5]=1;	game_map[3][6]=1;
	game_map[4][2]=1;	game_map[4][3]=1;	game_map[4][4]=1;
	game_map[5][4]=1;	game_map[6][2]=1;	game_map[6][6]=1;
	game_map[7][2]=1;	game_map[7][3]=1;	game_map[7][4]=1;
	game_map[7][6]=1;	game_map[7][7]=1;	game_map[8][1]=1;
	game_map[1][1]=2;   game_map[8][8]=3;
	beginx=8;	beginy=8;	endx=1; 	endy=1;
	found=false;
	length=0;searchlength=0;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			game_map_information[i][j].isused=false;
}
void game::paint_map(){
	clear();
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
			paint_point(game_map[i][j]);
		printf("\n");
	}
}
void game::paint_point(int number){
	switch(number){
		case 0:
			SetConsoleColor(BACKGROUND_INTENSITY| BACKGROUND_GREEN | BACKGROUND_RED);  		
			printf("  ");
			break;
		case 1: 
 			SetConsoleColor(BACKGROUND_INTENSITY| BACKGROUND_RED);  		
		    printf("  ");
			break;
	 	case 2:
	 		SetConsoleColor(BACKGROUND_INTENSITY| BACKGROUND_GREEN | BACKGROUND_RED|FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_BLUE);		
	 		printf("★");
	 		break;
	 	case 3:
	 		SetConsoleColor(BACKGROUND_INTENSITY| BACKGROUND_GREEN | BACKGROUND_RED|FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_BLUE);	
	 	    printf("■"); 
	 	    break;
	}
}
int main(int argc, char** argv) {
	game mazegame;
	mazegame.create_map();
	mazegame.paint_map();
	mazegame.DFS();
	mazegame.DFSoutprocess();
	SetConsoleColor(BACKGROUND_INTENSITY| BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	gotoxy(10,20);
	cout<<"按下任意键继续"; 
	getch();
	mazegame.create_map();
	mazegame.paint_map();
 	mazegame.BFS();
	mazegame.BFSoutprocess();
	SetConsoleColor(BACKGROUND_INTENSITY| BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	gotoxy(10,20);
	cout<<"按下任意键继续"; 
	getch();
	return 0;
}
