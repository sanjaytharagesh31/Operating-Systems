#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() {

    key_t key = 13;
    int shmid;
    int *ptr=NULL;
    shmid = shmget(key, 1024, IPC_CREAT | 0666);
    ptr = (int *)shmat(shmid, NULL, 0666);
    int *cnt = ptr;
    printf("%p", ptr);
    *cnt = 0;
    ptr++;
    printf("shm created\n");
    while(1) {
        int dat;
        printf("Enter data: ");
        scanf("%d", &dat);
        if(*cnt < 5) {
            *ptr = dat;
            ptr++;
            *cnt++;
            printf("value sent\n");
        }
        else {
            printf("Maximum limit reached\n");
        }
    }
    
return 0;
}