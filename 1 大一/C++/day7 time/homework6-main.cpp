//StudybarCommentBegin
#include <iostream>
 #include <iomanip>
 using std::cin;
 using std::cout;
 using std::endl;
 using std::setfill;
 using std::setw;

//StudybarCommentEnd


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Time
{
	private:int a,b,c,d,e,f;
	public:
		Time(int x=0,int y=0,int z=0,int m=0,int n=0,int o=0){a=x;b=y;c=z;d=m;e=n;f=o;		}
		Time operator ++()
		{
			Time z=*this;	
			f=f+1;
			if(f>=60){f=f-60;e=e+1;			}
			if(e>=60){e=e-60;d=d+1;			}
			if(d>=24){d=d-24;c=c+1;			}
	        if( (b==1 || b==3|| b==5|| b==7|| b==8|| b==10|| b==12)&&c==32) {b=b+1;c=1;	}
	        if( (b==4 || b==6|| b==9|| b==11)                       &&c==31){b=b+1;c=1;	}
	        if(b==2&&((a%4==0)||(a%100==0&&a%400==0))&&c==30) {b=b+1;c=1;	}
	        else if(b==2&&((a%4!=0)||(a%100==0&&a%400!=0))&&c==29){b=b+1;c=1;	}
	        if(b>12) {b=1;a=a+1;	}
	        return *this;
		}
		Time operator --()
		{
			Time z=*this;	
			f=f-1;
			if(f<0){f=f+60;e=e-1;			}
			if(e<0){e=e+60;d=d-1;			}
			if(d<0){d=d+24;c=c-1;			}
	        if( (b==2 || b==4|| b==6|| b==8|| b==9|| b==11|| b==1)&&c==0) {b=b-1;c=31;	}
	        if( (b==5 || b==7|| b==10|| b==12)                       &&c==0){b=b-1;c=30;	}
	        if(b==3&&((a%4==0)||(a%100==0&&a%400==0))&&c==0) {b=b-1;c=29;	}
	        else if(b==3&&((a%4!=0)||(a%100==0&&a%400!=0))&&c==0){b=b-1;c=28;	}
	        if(b==0) {b=12;a=a-1;	}
	        return *this;
		}
		Time operator --(int)
		{
			Time z=*this;	
			f=f-1;
			if(f<0){f=f+60;e=e-1;			}
			if(e<0){e=e+60;d=d-1;			}
			if(d<0){d=d+24;c=c-1;			}
	        if( (b==2 || b==4|| b==6|| b==8|| b==9|| b==11|| b==1)&&c==0) {b=b-1;c=31;	}
	        if( (b==5 || b==7|| b==10|| b==12)                       &&c==0){b=b-1;c=30;	}
	        if(b==3&&((a%4==0)||(a%100==0&&a%400==0))&&c==0) {b=b-1;c=30;	}
	        else if(b==3&&((a%4!=0)||(a%100==0&&a%400!=0))&&c==0){b=b-1;c=29;	}
	        if(b==0) {b=12;a=a-1;	}
	        return z;
		}
		void printTime()
    {
     cout<<a<<"/"<<b<<"/"<<c<<" "<<
	 setfill('0')<<setw(2)<<d                   
     <<":"<<setw(2)<<e<<":"
     <<setw(2)<<f<<endl;
     }    

		friend Time operator+(Time &t,int k) ;
		friend Time operator+(int k,Time &t) ;
		void setTime(int x,int y,int z,int m,int n,int o){a=x;b=y;c=z;d=m;e=n;f=o;		}
		friend Time operator -(  Time &x, Time  &z);
		operator int(){return a;}
	   
};
Time operator+(Time &m,int k) 
{
	Time i=m;
	int t=k;
    while(t>0) {++i;t--;}
    return i;
}
Time operator+(int k,Time &m) 
{
	if(k>0)
	{	Time i=m;
	int t=k;
    while(t>0) {++i;t--;}
    return i;
	}
	else 
	{Time i=m;
	int t=k;
    while(t<0) {--i;t++;}
    return i;
	}

}
Time operator -(  Time &x, Time  &z)
{
	int k=0;
	while(1)
	{if(x.a==z.a &&x.b==z.b&&x.c==z.c&&x.d==z.d&&x.e==z.e&&x.f==z.f ) break;
	  else {++z;++k;}
	}
	return k;
}



	
//StudybarCommentBegin
int main()
 {

 int year,month,day;
 int hour,minute,second;
 int number;
 int capacity=0;
 Time t1(2016,3,31,23,45,0),t2,t3(t1),t4;
 cin>>year>>month>>day>>hour>>minute>>second;
 t1.setTime(year,month,day,hour,minute,second);
 cin>>year>>month>>day>>hour>>minute>>second;
 t2.setTime(year,month,day,hour,minute,second);
 cin>>number;
cout<<endl;
 t3=t1--;
 t3.printTime();
 t1.printTime();
 t4=--t1;
 t4.printTime();
 t4=number+t1;
 t4.printTime();
 capacity = t2-t1;
 cout<<capacity<<endl;
 }
//StudybarCommentEnd


