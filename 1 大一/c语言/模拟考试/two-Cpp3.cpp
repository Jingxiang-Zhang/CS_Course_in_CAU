#include<stdio.h>
int main()
{
	int a,b,c;
	char n[30];
	int m[30];
	gets(n);
	for(a=0;a<30;a++)
	m[a]=0;
	for(a=0;a<30;a++)
    if(n[a]>='a'&&n[a]<='z')
	{
		if(n[a]=='a') m[0]++;
		else if(n[a]=='b') m[1]++;
		else if(n[a]=='c') m[2]++;
		else if(n[a]=='d') m[3]++;
		else if(n[a]=='e') m[4]++;
		else if(n[a]=='f') m[5]++;
		else if(n[a]=='g') m[6]++;
		else if(n[a]=='h') m[7]++;
		else if(n[a]=='i') m[8]++;
		else if(n[a]=='j') m[9]++;
		else if(n[a]=='k') m[10]++;
		else if(n[a]=='l') m[11]++;
		else if(n[a]=='m') m[12]++;
		else if(n[a]=='n') m[13]++;
		else if(n[a]=='o') m[14]++;
		else if(n[a]=='p') m[15]++;
		else if(n[a]=='q') m[16]++;
		else if(n[a]=='r') m[17]++;
		else if(n[a]=='s') m[18]++;
		else if(n[a]=='t') m[19]++;
		else if(n[a]=='u') m[20]++;
		else if(n[a]=='v') m[21]++;
		else if(n[a]=='w') m[22]++;
		else if(n[a]=='x') m[23]++;
		else if(n[a]=='y') m[24]++;
		else if(n[a]=='z') m[25]++;
	}

for(a=0;a<30;a++)
for(b=0;b<a;b++)
if(m[a]<m[a+1])
{
	c=m[a];
	m[a]=m[a+1];
	m[a+1]=c;
}
if(m[0]=)
