#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<time.h>
#define PROJID 0xFF

int main()
{
	key_t mqkey = ftok("message_open", PROJID);
	int shmid, *p, i;
	shmid = shmget(mqkey, 1024, IPC_CREAT|0666);

	char *shmaddr = shmat(shmid, 0, 0);
	p = (int*)shmaddr;
	srand(time(0));
	for(i=1;i<=10;i++){	
		*p = rand()%100;
		printf("write to memory: %d\n",*p);
		p++;
	}
	shmdt(shmaddr);
}






