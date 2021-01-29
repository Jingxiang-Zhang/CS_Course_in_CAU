#include <iostream>
#include <cstdlib>
using namespace std;
class VectorDouble
{
	private:
		unsigned int xx,yy;//代表动态数组的容量，另代表动态数组中实际存储元素的个数。
		double *zz;
	public:
		VectorDouble(){	xx=0;yy=0;		}
		VectorDouble(int a,double b=0)
		{
			xx=a;yy=a;
			zz=new double[a];
			for(int t=0;t<a;t++) zz[t]=b;
		}
		double&  operator[](int t)
		{
			if(t<xx)
			return this->zz[t];
			else 
			{
				cout<<"Out of Range!";exit(1);
			}
		}

		int capacity(){return xx;		}
		int size(){return yy;		}

};
//StudybarCommentBegin
int main()
{
    VectorDouble v1;
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;
   
    double value;
    cin >> value;
    
    VectorDouble v2(5,value);
    cout << v2[0] << endl;
    cout << v2[4] << endl;
  
    int capacity;
    cin >> capacity;
 
    VectorDouble v3(capacity);      
    cout << v3.capacity() << endl;
    cout << v3.size() << endl;
    for (int i=0; i<capacity; i++) {
        v3[i] = i * 1.1;
    }
    cout << v3[5] << endl;
    cout << v3[31] << endl;

    return 0;
}
//StudybarCommentEnd
