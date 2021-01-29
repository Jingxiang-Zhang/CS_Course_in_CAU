#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char id[17];
	int a[17],i,j;
	scanf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",&id[0],&id[1],&id[2],&id[3],&id[4],&id[5],&id[6],&id[7],&id[8],&id[9],&id[10],&id[11],&id[12],&id[13],&id[14],&id[15],&id[16]);
	for(i=0;i<18;i++)
	a[i]=id[i]-48;
    j=a[0]*7+a[1]*9+a[2]*10+a[3]*5+a[4]*8+a[5]*4+a[6]*2+a[7]*1+a[8]*6+a[9]*3+a[10]*7+a[11]*9+a[12]*10+a[13]*5+a[14]*8+a[15]*4+a[16]*2;
    j=j%11;
    if(j==0) printf("1");
    else if(j==1) printf("0");
    else if(j==2) printf("X");
    else if(j==3) printf("9");
    else if(j==4) printf("8");
    else if(j==5) printf("7");
    else if(j==6) printf("6");
    else if(j==7) printf("5");
    else if(j==8) printf("4");
    else if(j==9) printf("3");
    else if(j==10) printf("2");	
	return 0;
}

