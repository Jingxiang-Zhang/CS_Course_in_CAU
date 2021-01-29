#include <iostream>
#include <fstream>
#include <time.h> 
#include <stdlib.h>
#include <iomanip>
using namespace std;
struct staff{
	int No;
	char Name[10];
	int depno;
	double salary;
    
};
istream &operator>>(istream& in,staff &newstaff){
	cout<<"请输入一个新的员工编号，整数:           "; 
	in>>newstaff.No;
	cout<<"请输入一个新员工的名字，小于5个字母:    ";
	in>>newstaff.Name;
	cout<<"请输入一个新员工的部门编号，整数:       ";
    in>>newstaff.depno;
	cout<<"请输入一个新员工的工资，最好大于1000元: "; 
	in>>newstaff.salary;
	return in;
} 
ostream &operator<<(ostream& out,staff&st){
	cout<<"staff's Number："<<setw(2)<<st.No<<"        "; 
 	cout<<"name:"<<setw(5)<<st.Name<<"        ";
 	cout<<"department number:"<<setw(3)<<st.depno<<"      ";
 	cout<<"salary:"<<setw(5)<<st.salary<<endl;
 	return out;
}
void staff_salary_sort(staff st[],int length){
	for(int i=0;i<length-1;i++)
		for(int j=0;j<length-1;j++)
			if(st[j].salary>st[j+1].salary){
				staff temp=st[j];
				st[j]=st[j+1];
				st[j+1]=temp;
			}	
}
void tran(const char* t,staff&st) {
	int i=0;
	while(t[i]!=0)
	{
		st.Name[i]=t[i];
		i++;
	}
	st.Name[i]=0;
}

void create_staff_data(){
	srand((unsigned)time(NULL));
	staff stafft[10];
	for(int i=0;i<10;i++){
		stafft[i].depno=i*10;
		stafft[i].No=i+1;
		while(true){
			stafft[i].salary=rand()%10000;   
			if(stafft[i].salary>=2000) break;  //工资最起码也得有2000 
		}
		 
	}
	tran("Zhao",stafft[0]);
    tran("Qian",stafft[1]);
    tran("Sun",stafft[2]);
    tran("Li",stafft[3]);
    tran("Zhou",stafft[4]);
    tran("Wu",stafft[5]);
    tran("Zheng",stafft[6]);
    tran("Wang",stafft[7]);
    tran("Feng",stafft[8]);
    tran("Chen",stafft[9]);

    FILE *p2f;
    p2f=fopen("Staff_data.dat","wb");
    int size=sizeof(staff);
    fwrite(stafft,size,10,p2f);
	fclose(p2f);
}
void read_staff_data(staff mystaff[10]){
	FILE *p2f;
	p2f=fopen("ass.t","rb");
	staff now[10];
	int size=sizeof(staff);
	for(int i=0;i<10;i++){
	}
	fread(now,size,10,p2f);
 	for(int i=0;i<10;i++){
 		mystaff[i]=now[i];
	 }
	fclose(p2f);
}

template<typename T>
class CNode{
	public:
		T data;
		CNode *link; 
		CNode(){
			link=NULL;
		}
};
template<typename T>
class sqList{
	private:
		CNode<T> *head;
		int length;
	public:
		sqList();                   
		~sqList();                
		void push_back(T value) ;   
		int getLength();
		bool isempty();
		T &operator[](int i);
		int find(char t); 
		void insert(int location,T t);
		void erase(int location);
};
template<typename T>
T& sqList<T>::operator[](int i){
	if(i>=length&&i<0){
		cout<<"范围错误！"; 
		exit(1);
	} 
	CNode<T> *q=head;
	while(i--){
		q=q->link;
	} 
	return q->data ;
}
template<typename T>
int sqList<T>::find(char t){
	CNode<T> *q=head;
	int lo=0;
	while(q->link){
		if(q->data==t) 
			return lo;
	    lo++;
	}
	return -1;
}
template<typename T>
void sqList<T>::erase(int location){
	if(location>length && location<=0) return ;
	CNode<T> *q=head,*before=head;
	while(location-->1){
		before=q;
		q=q->link;
	}
	if(before!=head){
		before->link=q->link;
		delete q;
		return;
	}
	else{
		head=head->link;
		delete before;
	}
}
template<typename T>
void sqList<T>::insert(int location,T t){
	if(location>length && location<=0) return ;
	CNode<T> *q=head;
	while(location-->1){
		q=q->link;
	}
	CNode<T> *qt=new CNode<T>;
	qt->data=t;
	qt->link=q->link;
	q->link=qt;	
}
template<typename T>
int sqList<T>::getLength(){
	return length;
}
template<typename T>
bool sqList<T>::isempty(){
	return length==0;
}
template<typename T>
void sqList<T>::push_back(T value){
	CNode<T>*q=head;
	while(q->link){
		q=q->link;
	}
	q->data=value;;
	q->link=new CNode<T>(); 
    length++;
}
template<typename T>
sqList<T>::sqList(){
    head=new CNode<T>();
    length=0;
}
template<typename T>
sqList<T>::~sqList(){
	CNode<T> *q=head;
	CNode<T> *p;
	while(q->link){
		p=q;
		q=q->link;
		delete p;
	}
}
int main(int argc, char** argv) {
	create_staff_data();            //创建员工数据信息 
    staff mystaff[10];
	read_staff_data(mystaff);          //读取员工数据 
		
	sqList<staff> staff_list;
	cout<<"获取到的数据为：\n";
 	for(int i=0;i<10;i++){
 		cout<<mystaff[i]; 
 		staff_list.push_back(mystaff[i]);  //添加数据 
	}	 
	cout<<"数据导入完成"<<endl;
	
	staff newstaff;
	cin>>newstaff;               //输入一个员工 
	staff_list.push_back(newstaff); 
	cout<<"\n\n"<<"当前员工信息为：\n";
	for(int i=0;i<staff_list.getLength();i++){
	 	staff as=staff_list[i];
	 	cout<<as;
	}                     //输出所有员工信息
	
	cout<<"\n\n"<<"按工资排序后员工信息为：\n";         
	//按照工资进行排序 
	//由于我默认的输入数据工资是随机的，而部门编号不是随机的，所以这里仅仅
	//对工资进行了排序，对部门编号和员工编号排序的方法同理 
	staff sortstaff[staff_list.getLength()];
	for(int i=0;i<staff_list.getLength();i++) 
		sortstaff[i]=staff_list[i];
	staff_salary_sort(sortstaff,staff_list.getLength()) ; 
    for(int i=0;i<staff_list.getLength();i++)
    	cout<<sortstaff[i];	 	 
	 
	return 0;
}
