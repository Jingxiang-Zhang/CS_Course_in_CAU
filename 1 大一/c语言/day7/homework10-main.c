#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//StudybarCommentBegin
void main()
{
       int a[10];
	int i, m, n;
        void  method(int m,int n,int *a);
	for ( i=0; i<10; i++ )
		scanf( "%d", &a[i] );
	scanf( "%d%d", &m, &n );

       method(m,n,a);
    
	for( i=0;i<10;i++ )
		printf( "%d ", a[i] );
}

//StudybarCommentEnd
void  method(int m,int n,int *a)
{
	int c,b;
	for(b=1;b<=n/2;b++)
	{
		c=a[m+b-2];a[m+b-2]=a[m+n-b-1];a[m+n-b-1]=c;
	}
 } 
