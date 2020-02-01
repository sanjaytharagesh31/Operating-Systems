#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
int init(key_t key, int what) {
int id;
if((id = semget(key,1,0777|IPC_CREAT)) == -1) {
} else {
if(semctl(retval, 0, SETVAL, what) == -1) {
}
}
return(id);
}
void down(int s)
{
struct sem_buf sb;
sb.sem_num = 0;
sb.sem_op = -1;
sb.sem_flg = SEM_UNDO;
if(sem_op(s, &sb, 1) == -1) {
}
}
void up(int s)
{
struct sem_buf sb;
sb.sem_num = 0;
sb.sem_op = 0;
sb.sem_flg = SEM_UNDO;
if(sem_op(s, &sb, 1) == -1) {
}
}
void main(void) {
int s;
s = init(1234, 1);
down(s);
up(s);
}
