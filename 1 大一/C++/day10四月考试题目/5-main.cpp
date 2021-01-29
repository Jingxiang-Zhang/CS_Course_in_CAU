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
		VectorDouble(){	xx=0;yy=0;zz=new double[0];yy=0;		}
		VectorDouble(double *a,double *b)
		{
			xx=b-a;
			yy=xx;
			double *p=a;
			zz=new double[xx];
			for(int d=0;d<xx;d++) {zz[d]=*p;p++;			} 
		}
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
			zz=new double[a+10];
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

		int  capacity()const{return yy;		} 
		int size()const {return xx;		}
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
			for (int i=0; i<z.size(); i++)
            {
                cout << setw(10)<<z[i] << " ";
                if ((i+1)%5 == 0) {t<<endl;}
            }
            cout<<endl;
            return t;
		}
		double *begin(){return zz;		}
		double *end()
		{
			double  *p=zz;
			for(int d=0;d<xx;d++) p++;
			return p;
		}
		VectorDouble operator+=(double t)
		{
			double  *p=zz;
			for(int d=0;d<xx;d++) 
			{ 
			    *(zz+d)	=*(zz+d)+t;	 
			}
		}
		void  push_back (const double & newItem)
		{
			if(xx==yy && yy==0)
			{
		        yy=1;
		        delete zz;
		        zz=new double[1];
			}
		    else if(xx==yy && yy!=0) 
		    {
		    	double *kk=new double[xx*2];
		    	for(int k=0;k<yy;k++) kk[k]=zz[k];
		    	delete zz;
		    	zz=new double[xx*2];
		    	for(int k=0;k<yy;k++) zz[k]=kk[k];
		    	yy=yy*2;
			}
			zz[xx]=newItem;	xx++;
		} 
};


//StudybarCommentBegin
int main()
{
    VectorDouble v1;
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;

    v1.push_back(10.1);
       
    cout << v1.capacity() << endl;
    cout << v1.size() << endl<<endl;
   
    v1.push_back(10.2);
    cout << v1.capacity() << endl;
    cout << v1.size() << endl <<endl;
  
    for(int i = 2;i < 27; i++)
        v1.push_back(10+0.1*i);
   
    cout <<"***********"<<endl;
    cout << v1;
   
    cout <<"***********"<<endl;
    for(double *iter = v1.begin(); iter != v1.end(); iter++) //使用指针方式输出VectorDouble中内容
        cout<< *iter << " ";
    cout << endl;
      
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;
	
    return 0;
}

//StudybarCommentEnd
