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
		VectorDouble(const VectorDouble &z)
		{
			xx=z.xx;
			yy=z.yy;
			zz=new double[xx];
			for(int t=0;t<xx;t++) zz[t]=z.zz[t];
		}
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

		int  capacity()const{return xx;		} 
		int size(){return yy;		}
        const double& operator[](unsigned int i)   const
        {
        	return this->zz[i];
		} 
};

//StudybarCommentBegin
int main()
{
    const VectorDouble v1(10,5.5);
 
    for (int i=0; i<v1.capacity(); i++) {
        cout << v1[i] << " ";
    }   
    cout<<endl;
    
    VectorDouble v2(v1);

    cout << v2.capacity() << endl;
    cout << v2.size() << endl;
   
    double value;
    cin >> value;
   
    v2[5] = value;
    
    for (int i=0; i<v2.capacity(); i++) {
        cout << v2[i] << " ";
    }
    cout<<endl;
    
    return 0;
}
//StudybarCommentEnd
