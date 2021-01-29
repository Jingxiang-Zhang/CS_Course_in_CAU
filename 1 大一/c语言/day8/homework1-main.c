#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct student
	{
		char n[20];
		char s;
		int a;
		double sc;
	 }; 
	 
int main(int argc, char *argv[]) {
	struct student stu[45];
	int x,z,t;
	double y;
	scanf("%d",&z);
	for(x=0;x<z;x++)
	{
		scanf("%s",&stu[x].n);getchar();
		scanf("%c",&stu[x].s);
		scanf("%d",&stu[x].a);
		scanf("%lf",&stu[x].sc);
	}
	y=stu[0].sc;t=0;
	for(x=0;x<z;x++)
	if(stu[x].sc>y) {y=stu[x].sc;t=x;} 
    printf("\nName\t\tSex\tAge\tScore\n");
	printf("%s\t\t%c\t%d\t%5.1f\n",stu[t].n,stu[t].s,stu[t].a,stu[t].sc); 
	return 0;
}

//姓名，性别，年龄，成绩
