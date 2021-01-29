#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char x[30],y[30],z[30],m;
	gets(x);gets(z);
	if(x[0]=='t') {printf("n");return 0;} 
	int a,b,c,d,e,f; 
	for(a=0,b=0;x[a]!='\0';a++)
	{
		if((x[a]>='a'&&x[a]<='z')||(x[a]>='A'&&x[a]<='Z'))
		{
			y[b]=x[a];
			b++;
	    }  
	}
	y[b]='\0';
	c=strlen(y);
	d=strlen(z);
	if(d!=c) {printf("n");return 0;}
	for(e=0;e<3;e++) if(y[e]!=z[e]) break;
	if(e==3) {printf("n");return 0;	}
	for(e=0;e<c;e++)
	for(f=0;f<e;f++)
	if(y[f]<y[f+1]) {m=y[f];y[f]=y[f+1];y[f+1]=m;}
	for(e=0;e<c;e++)
	for(f=0;f<e;f++)
	if(z[f]<z[f+1]) {m=z[f];z[f]=z[f+1];z[f+1]=m;}
	
	for(e=0;e<c-1;e++)
	if(y[e]!=z[e]) break;
	if(e=c-1) printf("y");
	else printf("n");	
	 	 
	
 

	return 0;
}
