#include <iostream>
#include <cstdlib>
using namespace std;
struct Student {
  int id;       //学号
  float gpa;    //平均分
}; 
template <class T>
class Store {//类模板：实现对任意类型数据进行存取
private:
    T item; // item用于存放任意类型的数据
    bool haveValue;  // haveValue标记item是否已被存入内容
public:
    Store();
    T &getElem();   //提取数据函数
    void putElem(const T &x);  //存入数据函数
};

template <class T>  
Store<T>::Store(): haveValue(false) { } 
template <class T>
T &Store<T>::getElem() {
    //如试图提取未初始化的数据，则终止程序
    if (!haveValue) {   
        cout << "No item present!" << endl;
        exit(1);    //使程序完全退出，返回到操作系统。
    }
    return item;        // 返回item中存放的数据 
}
template <class T>
void Store<T>::putElem(const T &x) {
    // 将haveValue 置为true，表示item中已存入数值   
    haveValue = true;   
    item = x;           // 将x值存入item
}

int main() {
    Store<int> s1, s2;  
    s1.putElem(3);  
    s2.putElem(-7);
    cout << s1.getElem() << "  " << s2.getElem() << endl;

    Student g = { 1000, 23 };
    Store<Student> s3;
    s3.putElem(g); 
    cout << "The student id is " << s3.getElem().id << endl;

    Store<double> d;
    cout << "Retrieving object D... ";
    cout << d.getElem() << endl;
   //d未初始化，执行函数D.getElement()时导致程序终止
    return 0;
}
