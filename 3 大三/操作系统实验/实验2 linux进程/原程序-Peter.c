#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<signal.h>
#define PROJID 0xFF
int mqid;
void terminate_handler(int signo)
{
	msgctl(mqid, IPC_RMID, NULL);
	exit(0);
}

int main()
{
	char filenm[] = "message_open";
	key_t mqkey = ftok(filenm, PROJID);
	if(mqkey == -1){	
		printf("ftok error: ");
		exit(-1);
	}
	struct msgget{
		long mtype;
		char mtext[256];
	}msg;
	int ret;
	mqid = msgget(mqkey, IPC_CREAT | 0666);
	if(mqid == -1){	
		printf("msgget error: ");
		exit(-1);
	}
	signal(SIGINT, terminate_handler);
	signal(SIGTERM, terminate_handler);
	while(1){
		msgrcv(mqid, &msg, 256, 1, 0);
		printf("Lucy: %s\n", msg.mtext);

		printf("Peter: ");
		fgets(msg.mtext, 256, stdin);
		if(strncmp("quit", msg.mtext, 4) == 0){
			msgctl(mqid, IPC_RMID, NULL);
			exit(0);
		}
		msg.mtext[strlen(msg.mtext)-1] = '\0';
		msg.mtype = 2;
		msgsnd(mqid, &msg, strlen(msg.mtext)+1, 0);
	}
}








