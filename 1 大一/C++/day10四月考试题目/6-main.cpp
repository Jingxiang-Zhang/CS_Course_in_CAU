#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class VectorDouble
{
	private:
		unsigned int xx,yy;//另代表动态数组中实际存储元素的个数。代表动态数组的容量，
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
		void swap(VectorDouble &t)
		{
			unsigned int kk;
			double *tt;   //tt 用来存放t.xx中的数据 
			double *ttt;  //ttt用来存放xx中的数据 
			tt=new double[t.yy];
			ttt=new double[yy];
			for(int m=0;m<t.yy;m++) tt[m]=t.zz[m];
			for(int m=0;m<yy;m++) ttt[m]=zz[m];
			kk=xx;xx=t.xx;t.xx=kk;
			kk=yy;yy=t.yy;t.yy=kk;  //交换xx  yy
			delete zz;delete t.zz; 
			zz=new double[yy];t.zz=new double[t.yy];
			for(int m=0;m<yy;m++) zz[m]=tt[m];
			for(int m=0;m<t.yy;m++) t.zz[m]=ttt[m];
			delete tt;delete ttt;	
		}
};
//StudybarCommentBegin
int main()
{
    double dArray1[13] = {0};
    for (int i = 0; i < 13; i++) {
        dArray1[i] = i;
    }
 
    VectorDouble v1(dArray1,dArray1+13);
    
    cout <<" Before v1:"<<endl;
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;
    cout << v1;
     
    VectorDouble v2;
    v2.push_back(100.1);
    v2.push_back(200.1);
    v2.push_back(300.1);
    
    cout <<" Before v2:"<<endl;
    cout << v2.capacity() << endl;
    cout << v2.size() << endl;
    cout << v2;
      
    v1.swap(v2);
    	
    cout <<" Now v1:"<<endl;
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;
    cout << v1;
    
    cout <<" Now v2:"<<endl;
    cout << v2.capacity() << endl;
    cout << v2.size() << endl;
    cout << v2;
     
    return 0;
}

//StudybarCommentEnd
