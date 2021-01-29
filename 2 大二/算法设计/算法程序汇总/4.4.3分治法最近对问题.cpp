#include <string.h>
#include <stdlib.h>
#include <math.h>
//StudybarCommentBegin
#include <iostream>
using namespace std;

int* BruteForce(double x[], double y[], int length);
int* DivideConquer(double x[], double y[], int length);

int main(){
	char x_char[10000];
	char y_char[10000];
	int length;
	int method_id;
	cin.getline(x_char, 10000);
	cin.getline(y_char, 10000);
	cin >> length;
	cin >> method_id;

	double x[1000];
	double y[1000];

	char* tmpStrX = strtok(x_char, " ");
	for (int i = 0; i < length; i++)
	{
		x[i] = atof(tmpStrX);
		tmpStrX = strtok(NULL, " ");
	}

	char* tmpStrY = strtok(y_char, " ");
	for (int j = 0; j < length; j++)
	{
		y[j] = atof(tmpStrY);
		tmpStrY = strtok(NULL, " ");
	}

	int* r = NULL;
	switch (method_id)
	{
	case 1:
		r = BruteForce(x, y, length);
                if(r[0] <= r[1])
                {
                      cout<<r[0]<<","<<r[1]<<endl;
                }
                else
                {
                      cout<<r[1]<<","<<r[0]<<endl;
                 }
		break;
	case 2:
		r = DivideConquer(x, y, length);
                if(r[0] <= r[1])
                {
		       cout<<r[0]<<","<<r[1]<<endl;
                }
                else
                {
                       cout<<r[1]<<","<<r[0]<<endl;
                 }
		break;
	default:
		cout << -1 << endl;
		break;
	}
	return 0;
}

//StudybarCommentEnd
int* BruteForce(double x[], double y[], int length){
	double less=1000000;
	int i,j;
	int ile=0,jle=0;
	for(i=0;i<length;i++){
		for(j=i+1;j<length;j++){
		//	if(i==j) continue;
			double temp=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			if(less>temp){
				less=temp;
				ile=i;
				jle=j;
			}
		}
	}
	int *t=new int[2];
	t[0]=ile;
	t[1]=jle;
	return t;
} 
struct point{
	double x;
	double y;
	int num;
};
inline void change(point *a,point *b){
	double temp;
	temp=a->x;
	a->x=b->x;
	b->x=temp;
	temp=a->y;
	a->y=b->y;
	b->y=temp;
	int te;
	te=a->num;
	a->num=b->num;
	b->num=te;
}
int ssort(point *p,int s,int e){
	int i=s;
	int j=e;
	while(i<j){
		while(i<j&&p[i].x<=p[j].x)	j--;
		if(i<j)	{
			change(&p[i],&p[j]);
			i++;
		}
		while(i<j&&p[i].x<=p[j].x)	i++;
		if(i<j) {
			change(&p[i],&p[j]);
			j--;
		}
	}
	return i;
}
void quicksort(point *p,int s,int e){
	if(s<e){
		int mid=ssort(p,s,e);
		quicksort(p,s,mid-1);
		quicksort(p,mid+1,e);
	}
	
}
int ssort2(point *p,int s,int e){
	int i=s;
	int j=e;
	while(i<j){
		while(i<j&&p[i].y<=p[j].y)	j--;
		if(i<j)	{
			change(&p[i],&p[j]);
			i++;
		}
		while(i<j&&p[i].y<=p[j].y)	i++;
		if(i<j)	{
			change(&p[i],&p[j]);
			i++;
		}
	}
	return i;
}
void quicksort2(point *p,int s,int e){
	if(s<e){
		int mid=ssort2(p,s,e);
		quicksort2(p,s,mid-1);
		quicksort2(p,mid+1,e);
	}
}
double minm;
int ax;
int ay;
double Divi(point *p,int start,int end,int *r1,int *r2){
	if(start+1==end){
		*r1=p[start].num;
		*r2=p[end].num;
		return ((p[end].x-p[start].x)*(p[end].x-p[start].x)+
				(p[end].y-p[start].y)*(p[end].y-p[start].y));
	}
	int mid=(start+end)/2;
	double leftmin=100000,rightmin=100000;
	int *ll1=new int;
	int *ll2=new int;
	int *rr1=new int;
	int *rr2=new int;
	if(mid>=start+1)	leftmin=Divi(p,start,mid,ll1,ll2);
	if(end>=mid+1)		rightmin=Divi(p,mid,end,rr1,rr2);
	double d=(leftmin<rightmin)?leftmin:rightmin;
	point *pnew=new point[1000];
	int loc=0;
	int i,j;
	double locx=p[mid].x;
	for(i=start;i<=end;i++){
		if((p[i].x-locx)*(p[i].x-locx)<=d){
			pnew[loc].x=p[i].x;
			pnew[loc].y=p[i].y;
			pnew[loc].num=p[i].num;
			loc++;
		}
	}
	quicksort2(pnew,0,loc-1);
	double midmin=1000000;
	int midr1,midr2;
	for(i=0;i<loc;i++){
		for(j=i-3;j<i+3;j++){
			if(j<0 || j>=loc) continue;
			if(i==j) continue;
			double dist=(pnew[i].x-pnew[j].x)*(pnew[i].x-pnew[j].x)+
						(pnew[i].y-pnew[j].y)*(pnew[i].y-pnew[j].y);
			if(dist<midmin){
				midmin=dist;
				midr1=pnew[i].num;
				midr2=pnew[j].num;
			}				
		}
	}
	double minnnnn=(midmin<d)?midmin:d;
	
	if(minnnnn==leftmin){
		*r1=*ll1;
		*r2=*ll2;
		if(*r1>*r2){
			int temp=*r1;
			*r1=*r2;
			*r2=temp;
		}
		if(minm>leftmin){
			minm=leftmin;
			ax=*r1;
			ay=*r2;
		}
		else if(minm==leftmin){
			if(*r1<ax){
				ax=*r1;
				ay=*r2;
			}
		}	
	}
	if(minnnnn==rightmin){
		*r1=*rr1;
		*r2=*rr2;
		if(*r1>*r2){
			int temp=*r1;
			*r1=*r2;
			*r2=temp;
		}
		if(minm>rightmin){
			minm=rightmin;
			ax=*r1;
			ay=*r2;
		}
		else if(minm==rightmin){
			if(*r1<ax){
				ax=*r1;
				ay=*r2;
			}
		}
		
	}
	if(minnnnn==midmin){
		*r1=midr1;
		*r2=midr2;
		if(*r1>*r2){
			int temp=*r1;
			*r1=*r2;
			*r2=temp;
		}
		if(minm>midmin){
			minm=midmin;
			ax=*r1;
			ay=*r2;
		}
		else if(minm==midmin){
			if(*r1<ax){
				ax=*r1;
				ay=*r2;
			}
		}
		
		
	}
	return minnnnn;

}

int* DivideConquer(double x[], double y[], int length){
	int i;
	point *po=new point[length];
	for(i=0;i<length;i++){
		po[i].x=x[i];
		po[i].y=y[i];
		po[i].num=i;
	}
	quicksort(po,0,length-1);
	int *r=new int[2];
	
	minm=10000;
	Divi(po,0,length-1,&r[0],&r[1]);
	r[0]=ax;
	r[1]=ay;
//	cout<<ax<<" "<<ay<<endl;
	return r;
/*
5 10 6 9 1 7 11 4 15 3 16
5 10 6 9 1 7 11 4 15 3 16
11
2
*/
}







