#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    key_t key = 13;
    int shmid;
    int *ptr=NULL;
    shmid = shmget(key, 1024, IPC_CREAT | 0666);
    ptr = (int *)shmat(shmid, NULL, 0666);
    int *cnt = ptr;
    printf("%p", ptr);
    ptr++; //now refers to free memory
    while(1) {
        int choice = 0;
        printf("Enter 1 to read data, 0 to exit: ");
        scanf("%d", &choice);
        if(choice == 1) {
            if(*cnt == 0) {
                printf("Shared memory is empty\n");
            }
            else {
                int *data = ptr + *cnt -1;
                printf("data read: %d\n", *data);
                *cnt--;
            }
        }
        else {
            shmdt(ptr);
            shmctl(shmid, IPC_RMID, NULL);
            exit(1);
        }
    }

    return 0;

}