#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template<typename t>
t abs(t m)
{
	if(m>0) return m;
	else return -m;
 } 
int main(int argc, char** argv) {
	double a=-5.5;
	int b=-5;
	cout<<abs(b)<<endl;
	cout<<abs(a); 
	
	return 0;
}
