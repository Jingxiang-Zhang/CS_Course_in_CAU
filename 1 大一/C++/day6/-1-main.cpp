#include <iostream>
using namespace std;
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Cassemblage
{
	private:
		int a;int b[10],c[10];    //a为数组的长度，b为数组 
	public:
		Cassemblage(){;	}
		void Set(int x[10],int z[10],int y)
		{   a=y;int k=0,m,n,i,j;
			for(k=0;k<y;k++) b[k]=x[k];
			b[k]=100000;
			for(k=0;k<y;k++) c[k]=z[k];
			c[k]=100000;
			for(m=0;m<y;m++)
			for(n=0;n<y-1;n++)
			{
				if((b[n]*b[n]+c[n]*c[n])>(b[n+1]*b[n+1]+c[n+1]*c[n+1]))
				 {i=b[n];b[n]=b[n+1];b[n+1]=i;	
				 j=c[n];c[n]=c[n+1];c[n+1]=j;		}
			}
		
		} 
		Cassemblage operator+(Cassemblage &z)  //////
		 {  Cassemblage t;
		   int k,x,y,i,j,m,n=0;
		   for(y=0;y<a;y++) {t.b[y]=b[y];t.c[y]=c[y]; }
		   for(k=0;k<z.a;k++)
		   {    for(x=0;x<a;x++) 
		        {if(z.b[k]==b[x] && z.c[k]==c[x]) break; }
		        if(x==a) 
		        {t.b[y]=z.b[k];t.c[y]=z.c[k];y++;	}
		   }
		   for(m=0;m<y;m++)
			for(n=0;n<y-1;n++)
			{
				if((t.b[n]*t.b[n]+t.c[n]*t.c[n])>(t.b[n+1]*t.b[n+1]+t.c[n+1]*t.c[n+1]))
				 {i=t.b[n];t.b[n]=t.b[n+1];t.b[n+1]=i;	
				 j=t.c[n];t.c[n]=t.c[n+1];t.c[n+1]=j;		}
			}
		   t.a=y;
		   return t;
		 }
		 
	     Cassemblage operator&(Cassemblage &z)  //////
		 {  Cassemblage t;
		   int k,x,y=0,m,n,i,j=0;
		   for(k=0;k<a;k++)
		   {    for(x=0;x<z.a;x++) 
		        {if(b[k]==z.b[x] && c[k]==z.c[x]) break; } 
		        if(x!=z.a) 
		        {t.b[y]=b[k];t.c[y]=c[k];y++;		}
		   } 
   
		   for(m=0;m<y;m++)
			for(n=0;n<y-1;n++)
			{
				if((t.b[n]*t.b[n]+t.c[n]*t.c[n])>(t.b[n+1]*t.b[n+1]+t.c[n+1]*t.c[n+1]))
				 {i=t.b[n];t.b[n]=t.b[n+1];t.b[n+1]=i;	
				 j=t.c[n];t.c[n]=t.c[n+1];t.c[n+1]=j;		}
			}
		   t.a=y;
		   return t;
		 }
		 
			Cassemblage operator-(Cassemblage &z)  //////
		 {  Cassemblage t;
		   int k,x,y=0;
		   for(k=0;k<a;k++)
		   {    for(x=0;x<z.a;x++) 
		        {if(b[k]==z.b[x]&&c[k]==z.c[x]) break; }
		        if(x==z.a) 
		        {t.b[y]=b[k];t.c[y]=c[k];y++;				}
		   }
		   t.a=y;
		   return t;
		 }
		 
		void Show()
		{   if(a==0) printf("empty")	;
			
			else 
			{int k=0;
			for(k=0;k<a;k++)
			{if(c[k]>=0) printf("(%d+%di) ",b[k],c[k]);
			else printf("(%d%di) ",b[k],c[k]);
			}
			
		
			 
			}
			
		 } 
};


int main(int argc, char* argv[])
{
	Cassemblage z1, z2, x1, x2, x3;
	int i, n1, n2, a1[1000], a2[1000], b1[1000], b2[1000];
	
	cin >> n1;
	for(i=0; i<n1; i++)
	{
		cin >> a1[i]>>b1[i];
	}
    z1.Set(a1, b1,n1);

	cin >> n2;
	for(i=0; i<n2; i++)
	{
		cin >> a2[i]>>b2[i];
	}	
	z2.Set(a2,b2, n2);

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

