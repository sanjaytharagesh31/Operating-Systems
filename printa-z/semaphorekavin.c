#include<stdio.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/ipc.h>

int a=1;

union semun {

               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
           }s;

int main(){

 struct sembuf sbuf;
 key_t key=1234;
 s.val=1;
 int semid=semget(key,1,IPC_CREAT|IPC_EXCL|0666);
 int pid=fork();
 int *ctr=&a;
 semctl(semid,0,SETVAL,s);

 if(pid==0){ 

  while(1){
  sbuf.sem_num=0;
  sbuf.sem_op=0;
  sbuf.sem_flg=SEM_UNDO;
  semop(semid,&sbuf,1);

  sleep(3);

  sbuf.sem_num=0;
  sbuf.sem_op=-1;
  sbuf.sem_flg=SEM_UNDO|IPC_NOWAIT;
  semop(semid,&sbuf,1);

  (*ctr)++;

  printf("\nAcquired and entering Child Process\nCounter :- %d",*ctr);

  sbuf.sem_num=0;
  sbuf.sem_op=1;
  sbuf.sem_flg=SEM_UNDO|IPC_NOWAIT;
  semop(semid,&sbuf,1);

  }

 }


 else if(pid>0) {
  while(1){

  printf("\nInitial Value of ctr %d\n",a);

  sbuf.sem_num=0;
  sbuf.sem_op=0;
  sbuf.sem_flg=SEM_UNDO;
  semop(semid,&sbuf,1);

  sleep(3);

  sbuf.sem_num=0;
  sbuf.sem_op=-1;
  sbuf.sem_flg=SEM_UNDO|IPC_NOWAIT;
  semop(semid,&sbuf,1);

  (*ctr)--;

  printf("\nAcquired and entering Parent Process\nCounter :- %d",*ctr);

  sbuf.sem_num=0;
  sbuf.sem_op=1;
  sbuf.sem_flg=SEM_UNDO|IPC_NOWAIT;
  semop(semid,&sbuf,1);
}
 }


 wait();

 //printf("\nValue of the Counter %d\n",a);

 return 0;



}
