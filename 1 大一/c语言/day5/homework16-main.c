#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j=0,k,a[6],b,f;
    for(i=0;i<6;i++)
		scanf("%d ",&a[i]);
	scanf("%d",&f);
	for(i=0;i<6;i++)
	{
		if(f>a[i]) printf("%d ",a[i]);
		else if(f<=a[i] && j==0){printf("%d %d ",f,a[i]);
		j=1;
		}
		else if(f<=a[i] && j==1) printf("%d ",a[i]);
	}
	if(j==0)printf("%d ",f);
	
	

	return 0;
}
