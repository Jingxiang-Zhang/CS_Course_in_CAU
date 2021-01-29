#include <iostream>
using namespace std;
class Point {
public:
Point(int a = 0, int b = 0):x(a),y(b)  {; }
int  getX()  const{ return this->x; }
int  getY() const { return this->y; }
private:
int const x, y;
};

int main() {
Point a(4, 5); //普通对象 
Point const b(6,7); //常对象
Point const* pa = &a; //定义常对象指针，用a的地址初始化
Point const* pb= & b; //定义常对象指针，用常对象b的地址初始化
const Point &rb= b; //定义常引用rb，常对象b的别名
cout << pa->getX() << endl;//用指针访问对象成员
cout<< a.getY() <<endl;
cout << (*pb).getY() << endl; //用指针求内容运算符访问对象成员
cout << rb.getX() << endl; //用常引用来访问对象成员
return 0;

}
