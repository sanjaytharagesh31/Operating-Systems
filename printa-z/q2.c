#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>

int count = 0;

/*struct semid_ds {
	struct ipc_perm;
	struct sem *sem;
	ushort_t sem_n sems;
	time_t sem_ctime;
	time_t sem_otime;
}*buf;

struct sembuf {
	unsigned short sem_num;
	short sem_op;
	short sem_flag;		
}*lock;
*/
union semun {
   int              val;    /* Value for SETVAL */
   struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
   unsigned short  *array;  /* Array for GETALL, SETALL */
   struct seminfo  *__buf;  /* Buffer for IPC_INFO
                               (Linux-specific) */
}s;
	
int main() {
	int *counter = &count;
    int sem1;
    key_t key = 1234;
    sem1 = semget(key,1,IPC_CREAT|IPC_EXCL|0666);
	s.val = 1;
    semctl(sem1, 0, SETVAL, s);
	struct sembuf sb;
		
	pid_t pid;		
	pid = fork();
	if(pid>0) {  //parent process
		
		while(*counter<=100) {
			sb.sem_num = 0;
			sb.sem_op = 1;
			sb.sem_flg = SEM_UNDO;
			semop(sem1, &sb, 1);

			sb.sem_num = 0;
			sb.sem_op = -1;
			sb.sem_flg = SEM_UNDO|IPC_NOWAIT;
			semop(sem1, &sb, 1);

			(*counter)++;

			printf("parent: %d\n", *counter);
			sb.sem_num = 0;
			sb.sem_op = 0;
			sb.sem_flg = SEM_UNDO|IPC_NOWAIT;
			semop(sem1, &sb, 1);		
		}	 	
	}	
	else {		//child process
		while(*counter<=100) {
			sb.sem_num = 0;
			sb.sem_op = 1;
			sb.sem_flg = SEM_UNDO;
			semop(sem1, &sb, 1);

			sb.sem_num = 0;
			sb.sem_op = -1;
			sb.sem_flg = SEM_UNDO|IPC_NOWAIT;
			semop(sem1, &sb, 1);

			(*counter)++;

			printf("child : %d\n", *counter);
			sb.sem_num = 0;
			sb.sem_op = 0;
			sb.sem_flg = SEM_UNDO|IPC_NOWAIT;
			semop(sem1, &sb, 1);
		}
	}
	return 0;
}
