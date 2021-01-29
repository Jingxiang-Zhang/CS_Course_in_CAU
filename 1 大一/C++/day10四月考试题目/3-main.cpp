#include <iostream>
#include <cstdlib>
#include <iomanip>
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
		int size()const {return yy;		}
        const double& operator[](unsigned int i)   const
        {
        	return this->zz[i];
		} 
		VectorDouble operator=(const VectorDouble &z)
		{
			VectorDouble t;
			cout <<"operator = called" <<endl; 
			xx=z.xx;
			yy=z.yy;
			zz=new double[xx];
			for(int d=0;d<xx;d++) zz[d]=z.zz[d];
			return t;
		}
		friend ostream& operator<<(ostream &t,const VectorDouble &z)
		{
			for (int i=0; i<z.capacity(); i++)
            {
                cout << setw(10)<<z[i] << " ";
                if ((i+1)%5 == 0) {t<<endl;}
            }
            cout<<endl;
            return t;
		}
};


//StudybarCommentBegin
int main()
{
    
    const VectorDouble v1(28,5.23);
   
    VectorDouble v2;
    v2 = v1;
   
    cout << v2.capacity() << endl;
    cout << v2.size() << endl;
 
    v2[5] = 1.2345;
    v2[13] = 4.5;
   
    cout << "v1 & v2" << endl;
    cout << v1 << v2 << endl;
    
    return 0;
}

//StudybarCommentEnd
