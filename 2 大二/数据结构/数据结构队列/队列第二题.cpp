#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define TRAINSIZE 15
using namespace std;
template<typename T>
struct prique_Node{
	prique_Node<T> *link;
	T data;
	prique_Node(){
		link=NULL;
	}
};
template<typename T>
class prique{
	private:
		prique_Node<T> *rear;
		prique_Node<T> *front;
		int size;
	public:
		prique();
		~prique();
		void insert(T value);
		T pop();
		int getsize();
		bool is_empty();
};
template<typename T>
int prique<T>::getsize(){
	return size;
}
template<typename T>
T prique<T>::pop(){
	if(is_empty()) throw("Queue empty.");
	T temp=front->data;
	prique_Node<T> *te=front;
	front=front->link;
	delete te;
	size--;
    return temp;
}
template<typename T>
bool prique<T>::is_empty(){
	if(rear==front)
		return true;
	return false;
}
template<typename T>
void prique<T>::insert(T value){
	size++;
	prique_Node<T> *te=front,*before;
	prique_Node<T> *temp=new prique_Node<T>();
	temp->data =value;
	if(is_empty()){
		temp->link=front;
		front=temp;
		return ;
	}
	if(!(te->data > value)){
		temp->link=front;
		front=temp;
		return ;
	}
	while(te->link ){
		if(te->data>value){
			before=te;
			te=te->link;
		}
		else{
			temp->link=te;
			before->link=temp;
			return ;
		}
	}
	before->link=temp;
	temp->link=rear;
 

}


template<typename T>
prique<T>::prique(){
	rear=new prique_Node<T>;
	front=rear;
	size=0;
}
template<typename T>
prique<T>::~prique(){
	prique_Node<T> *temp=front;
	while(temp->link){
		front=temp->link;
		delete temp;
		temp=front;
	}
	delete front;
}

struct Train{
	int number;
	string cargo;
};
operator >(Train a,Train b){
	if(a.number>b.number) return true;
	return false ;
}
Train train[TRAINSIZE];
template<typename T>
void creat_mass_member(int size,T vect[]){
	srand((int)time(0));
	for(int i=0;i<size*pow(size,0.5);i++){
		int tempa=rand()%size;
		int tempb=rand()%size;
		T temp=vect[tempa];
		vect[tempa]=vect[tempb];
		vect[tempb]=temp;
	}
}
int main(int argc, char** argv) {
	prique<Train> train_privority_queue;
	cout<<"火车入站：\n";
	for(int i=0;i<TRAINSIZE;i++)
		train[i].number=i;
	creat_mass_member(TRAINSIZE,train);  //打乱入站顺序 
	for(int i=0;i<TRAINSIZE;i++){
		train_privority_queue.insert(train[i]);
		cout<<"成功加入火车，编号："<<train[i].number<<"。\n";
	}
	
	cout<<"\n\n\n火车出站，出站顺序分别为：\n";
	for(int i=0;i<TRAINSIZE;i++){
		Train temp=train_privority_queue.pop();
		cout<<"火车出站，编号为："<<temp.number<<"。\n"; 
	}
	return 0;
}
