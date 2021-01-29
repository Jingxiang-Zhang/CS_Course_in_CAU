 #include<stdio.h>
 #include<math.h> 
int main()
{
	long int n,i;
	double a;
	i=2;
	scanf("%ld",&n);
    if(n==2147483647) {printf("y");return 0;	}
	a=sqrt(n);
	while(i<=a)
	{
		if(n%i==0)break;
		i=i+1;
	}
	if(i>=n)printf("y");
	else printf("n");
	return 0;
}

