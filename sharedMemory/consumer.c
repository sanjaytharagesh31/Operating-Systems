#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(int argc, char **argv) {
    key_t key = 1234;
    int shmid = shmget(key, 8, IPC_CREAT | 0666);
    int *ptr = (int *) shmat(shmid, NULL, 0666);
    if(*ptr>0) {
        *ptr = *ptr - 1;
    } else if(*ptr==0) {

    }
    printf("(consumed) count: %d\n", *ptr);
    shmdt((void *) ptr);
    return 0;
}