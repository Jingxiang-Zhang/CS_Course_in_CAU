#include <iostream>
#define SIZE 1000

using namespace std;
template<typename T>
class deque{
	private:
		T *data;
		int size;
		int rear;
		int front;
	public:
		deque(int size=SIZE);
		~deque();
		bool is_full();
		bool is_empty();
		bool add_rear(const T value);
		bool add_front(const T value);
		T pop_rear();
		T pop_front();
		int getsize();
};
template<typename T>
int deque<T>::getsize(){
	return (rear-front+size)%size;
}
template<typename T>
T deque<T>::pop_front(){
	if(this->is_empty()) throw "Queue empty.";
	T temp=data[front];
	front=(front+1)%size;
	return temp;
}
template<typename T>
T deque<T>::pop_rear(){
	if(this->is_empty()) throw "Queue empty.";
	T temp=data[rear];
	rear=(rear-1+size)%size;
	return temp;
}
template<typename T>
bool deque<T>::add_front(const T value){
	if(this->is_full()) return false;
	data[front]=value;
	front=(front-1+size)%size;
	return true;
}
template<typename T>
bool deque<T>::add_rear(const T value){
	if(this->is_full()) return false;
	data[rear]=value;
	rear=(rear+1)%size;
	return true;
}
template<typename T>
bool deque<T>::is_empty(){
	if(rear==front)
		return true;
	return false;
}

template<typename T>
bool deque<T>::is_full(){
	if((rear+1)%size==front)
		return true;
	return false;
}

template<typename T>
deque<T>::deque(int sizet){
	size=sizet;
	data=new T[size];
	rear=0;
	front=0;
}
template<typename T>
deque<T>::~deque(){
	delete data;
}
int main(int argc, char** argv) {
	cout<<"对队列进行插入操作，队列大小为8\n";
	deque<int> queue(8);
	for(int i=0;i<10;i++){
		if(queue.add_rear(i))
			cout<<"成功入队，入队元素为"<<i<<"，当前队列元素数量为"<<queue.getsize()<<"。"<<endl;
		else 
			cout<<"入队失败，队列已满。"<<endl;
	}
	cout<<"对队列进行取出元素操作"<<endl;
	for(int i=0;i<10;i++){
		try{
			int temp=queue.pop_front();
			cout<<"成功出队，出队元素为"<<temp<<"，当前队列元素数量为"<<queue.getsize()<<"。"<<endl;
		}
		catch(char const *t){
			cout<<"队列为空，无法出队，错误信息："<<t<<endl;
		}
	} 
	cout<<"\n\n\n下面测试从队头入队，队尾出队\n"; 
	for(int i=0;i<10;i++){
		if(queue.add_front(i))
			cout<<"成功入队，入队元素为"<<i<<"，当前队列元素数量为"<<queue.getsize()<<"。"<<endl;
		else 
			cout<<"入队失败，队列已满。"<<endl;
	}
	cout<<"对队列进行取出元素操作"<<endl;
	for(int i=0;i<10;i++){
		try{
			int temp=queue.pop_rear();
			cout<<"成功出队，出队元素为"<<temp<<"，当前队列元素数量为"<<queue.getsize()<<"。"<<endl;
		}
		catch(char const *t){
			cout<<"队列为空，无法出队，错误信息："<<t<<endl;
		}
	} 
	return 0;
}

