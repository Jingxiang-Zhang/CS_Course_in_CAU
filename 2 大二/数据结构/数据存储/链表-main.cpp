#include <iostream>
using namespace std;
 
class CNode{
	public:
	char data;
	CNode *link; 
	CNode(){
		link=NULL;
	}
};

class sqList{
	private:
		CNode *head;
		int length;
	public:
		sqList();                   
		~sqList();                
		void push_back(const char) ;   
		friend ostream& operator<<(ostream&out,sqList&sq);
		int getLength();
		bool isempty();
		char operator[](int i);
		int find(char t); 
		void insert(int location,char t);
		void erase(int location);
};

ostream& operator<<(ostream&out,sqList&sq){
	CNode* q=sq.head;
	while(q->link){
		out<<q->data<<" ";
		q=q->link;
	}
	return out;
}
sqList::sqList(){
    head=new CNode();
    length=0;
}

sqList::~sqList(){
	CNode *q=head;
	CNode *p;
	cout<<"当前删除元素"; 
	while(q->link){
		p=q;
		cout<<p->data<<" " ;
		q=q->link;
		delete p;
	}
}
int sqList::getLength(){
	return length;
}
char sqList::operator[](int i){
	if(i>=length) 
		return 0; 
	CNode *q=head;
	while(i--){
		q=q->link;
	} 
	return q->data ;
}
bool sqList::isempty(){
	return length==0;
}
void sqList::push_back(const char value){
	CNode *q=head;
	while(q->link){
		q=q->link;
	}
	q->data=value;;
	q->link=new CNode(); 
    length++;
}
int sqList::find(char t){
	CNode *q=head;
	int lo=0;
	while(q->link){
		if(q->data==t) 
			return lo;
	    lo++;
	}
	return -1;
}
void sqList::insert(int location,char t){
	if(location>length && location<=0) return ;
	CNode *q=head;
	while(location-->1){
		q=q->link;
	}
	CNode *qt=new CNode;
	qt->data=t;
	qt->link=q->link;
	q->link=qt;	
}
void sqList::erase(int location){
	if(location>length && location<=0) return ;
	CNode *q=head,*before=head;
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
int main(int argc, char** argv) {
	sqList list;          //初始化单链表
	for(int i=0;i<5;i++){
		list.push_back(97+i);  //依次插入a,b,c,d,e元素
	}
	cout<<"单链表元素:"<<list<<endl;
	cout<<"单链表长度"<<list.getLength()<<endl;    //输出单链表的元素和长度
	if(list.isempty())
		cout<<"链表为空"<<endl;
	else
		cout<<"链表不为空"<<endl;             //	 判断单链表是否为空。
	cout<<"链表的第三个元素为"<<list[2]<<endl;  //输出单链表的第3个元素。
	cout<<"链表a的位置"<<list.find('a')<<endl;        //输出元素a的位置。
	list.insert(4,'f');             //在第4个元素位置上插入f元素。
	list.erase(3);
	cout<<"单链表元素:"<<list<<endl;
    //由于创建的是对象所以不需要delete，自动释放 
	return 0;
}
