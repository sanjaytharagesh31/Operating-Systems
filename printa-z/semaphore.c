#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>

union semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
};
/*
struct sembuf {
    short sem_num;
    short sem_op;
    short sem_flg;
};*/

void main(void) {
       
    int sem1;
    key_t key = 1234;
    sem1 = semget(key,3,IPC_CREAT|0666);
    semctl(sem1, 0, SETVAL, 1);

    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = SEM_UNDO;
    semop(sem1, &sb, 1);
        printf("HI");
    sb.sem_num = 0;
    sb.sem_op = 0;
    sb.sem_flg = SEM_UNDO;
    semop(sem1, &sb, 1);
}