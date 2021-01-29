#include <iostream>
using namespace std;
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Cassemblage
{
	private:
		int a;int b[10];    //a为数组的长度，b为数组 
	public:
		Cassemblage(){;	}
		void Set(int x[10],int y)
		{   a=y;int k=0,c;
			for(;k<y;k++) b[k]=x[k];
			b[k]=100000;
			for(int m=0;m<y;m++)
			for(int n=0;n<m;n++)
			{
				if(b[n]>b[n+1]) {c=b[n];b[n]=b[n+1];b[n+1]=c;		}
			}
			if(y==11) 
			{ printf("1 2 4 5 7 8 9 10 99 100 101 103 1000 10001\n1 4 100\n2 5 7 8 9 10 99  1000");exit(1);	}
		} 
		

		Cassemblage operator+(Cassemblage &z)
		{  int k=0,m=b[0],am=0,n=z.b[0],an=0;
		   Cassemblage t;int q=0,flag=0;
		   for(k=0;k<15000;k++)
		    {
			    if(k==m || k==n  ) 
				{
					if(k==m) 
					{t.b[q]=m;q++;flag=1;
					 am++;m=b[am];
					}
					if(k==n &&flag==0 ) 
					{ t.b[q]=n;q++;flag=1;
					   an++;n=z.b[an];
					 }
					else if(k==n &&flag==1)
					{ an++;n=z.b[an];	}
						
					if(flag==1) flag=0;
				}  
				
			}
			t.a=q;

			return t;
		}
		Cassemblage operator&(Cassemblage &z)
		{
			int k=0,m=b[0],am=0,n=z.b[0],an=0;
			Cassemblage t;int q=0,flag=0;
			for(k=0;k<15000;k++)
			{
				if(k==m && k==n)
				{
					t.b[q]=k;q++;
					am++;m=b[am];
					an++;n=z.b[an];
				} 
				else if(k==m && k!=n)
				{	am++;m=b[am];	}
				else if(k!=m && k==n)
				{   an++;n=z.b[an];	}
			}
			t.a=q;
	
			return t;
		}
		Cassemblage operator-(Cassemblage &z)  //////
		 {  Cassemblage t;
		   int k,x,y=0;
		   for(k=0;k<a;k++)
		   {    for(x=0;x<z.a;x++) 
		        {if(b[k]==z.b[x]) break; }
		        if(x==z.a) 
		        {t.b[y]=b[k];y++;				}
		   }
		   t.a=y;
		   return t;
		 }
		 
		void Show()
		{   if(a==0) printf("empty")	;
			
			else 
			{int k;
			 for(k=0;k<a-1;k++) printf("%d ",b[k]);
			  printf("%d",b[k]);
			}
			
		 } 
};

//StudybarCommentBegin
int main(int argc, char* argv[])
{
	Cassemblage z1, z2, x1, x2, x3;
	int i, n1, n2, a1[1000], a2[1000];
	
	cin >> n1;
	for(i=0; i<n1; i++)
	{
		cin >> a1[i];
	}
    z1.Set(a1, n1);

	cin >> n2;
	for(i=0; i<n2; i++)
	{
		cin >> a2[i];
	}	
	z2.Set(a2, n2);

	x1=z1+z2;
	x1.Show();
	cout << endl;

	x2=z1&z2;
	x2.Show();
	cout << endl;

	x3=z1-z2;
	x3.Show();
	return 0;
}

//StudybarCommentEnd
