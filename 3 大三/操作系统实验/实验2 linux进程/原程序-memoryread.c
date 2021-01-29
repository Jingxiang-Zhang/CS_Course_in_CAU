#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<math.h>
#define PROJID 0xFF

int main()
{
	key_t mqkey = ftok("message_open", PROJID);
	int shmid, *p, i;
	shmid = shmget(mqkey, 1024, IPC_CREAT|0666);
	char *shmaddr = shmat(shmid, 0, 0);
	p = (int*)shmaddr;
	for(i=1;i<=10;i++){
		double ss=sqrt(*p);
		printf("init number:%d. sqrt:%.2f. square:%d\n",*p,ss,(*p)*(*p));
		p++;
	}
	shmdt(shmaddr);
	shmctl(shmid, IPC_RMID, 0);
}








