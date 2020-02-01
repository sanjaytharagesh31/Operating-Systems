#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
/*struct sembuf
{
unsigned short sem_num;
short sem_op;
short sem_flag;
}

struct semid_ds
{
struct ipc_perm;
struct sem*sem
*/
int cnt=0,times=0;
union semunion
{
int val;
struct semid_ds *buf;
ushort *array;
struct seminfo  *__buf;
}arg;
struct sembuf buf;


void main()
{

int semid;
key_t key=1234;
semid=semget(key,1,IPC_CREAT|IPC_EXCL|0666);


pid_t pid;

pid=fork();
semctl(semid,0,SETVAL,arg);
if(pid==0)
{
while(times<=100)
{
//child executing
buf.sem_num=0;
//buf.sem_op=0;
buf.sem_op=-1;
buf.sem_flg=IPC_NOWAIT|SEM_UNDO;
semop(semid,&buf,1);
cnt++;times++;
printf("increment %d\n",cnt);
buf.sem_num=0;
buf.sem_op=1;
buf.sem_flg=IPC_NOWAIT|SEM_UNDO;
semop(semid,&buf,1);

}
}
if(pid>0)
{
{while(times<=100)
{
buf.sem_num=0;
//buf.sem_op=0;
buf.sem_op=-1;
buf.sem_flg=IPC_NOWAIT|SEM_UNDO;
semop(semid,&buf,1);
cnt--;times++;
printf("decrement %d\n",cnt);
buf.sem_num=0;
buf.sem_op=1;
buf.sem_flg=IPC_NOWAIT|SEM_UNDO;
semop(semid,&buf,1);
}
}
}
}
