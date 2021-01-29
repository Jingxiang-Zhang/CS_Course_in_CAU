#include <iostream>
#define INIT_SIZE 100
#define INCREASE 50
using namespace std;
template<typename t>
struct sqlist{
	t *elment;
	int length;         //当前长度 
	int size;           //总大小 
};

template<typename t>
void Init(sqlist<t> &L){
	L.elment=new t[INIT_SIZE];
	if(!L.elment) printf("OverFlow!");
	else{
		L.length=0;
		L.size=INIT_SIZE;
	}
}
template<typename t>
void Destory(sqlist<t> &L){
	delete[] L.elment;
	L.length=0;
	L.size=0;
}
template<typename t>
void Clean(sqlist<t> &L){
	L.length=0;
}
template<typename t>
void Length(sqlist<t> &L){
	return L.length;
}
template<typename t>
t GetElem(sqlist<t> &L,int i){
	if(i<1 || i>L.length)
	    printf("Position Error!"); 
	else return L.elment[i];
}
template<typename t>
void LocateElem(sqlist<t> &L,t value){
	int i=1;
	t* p=L.elment;
	while(i<=L.length && (*p++!=value)) i++;
	if(i<=L.length) return i;
	return 0;
}
template<typename t>
void Insert(sqlist<t> &L,int i,t e){
	if(i<1||i>L.length) {
		printf("Position Error!");
		return ;
	}
	if(L.length>=L.size) 
		Increment(L);
	t *q=&(L.elment[i-1]);
	for(t *p=&(L.elment[L.length-1]);p>=q;--p)
		*(p+1)=*p;
	*q=e;
	++L.length;
}
int main(int argc, char** argv) {
	sqlist<int> sq;
	Init(sq);
	return 0;
}
