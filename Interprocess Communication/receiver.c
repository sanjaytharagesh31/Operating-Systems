#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdio.h>

struct msg {
	long type;
	char str[100];
}m;

int main() {
	key_t key = 1234;
	int msqid = msgget(key, IPC_CREAT | 0666);
	msgrcv(msqid, &m, sizeof(m), 0, IPC_NOWAIT);
	printf("%s\n", m.str);
	msgrcv(msqid, &m, sizeof(m), 0, IPC_NOWAIT);
	printf("%s\n", m.str);
	msgctl(msqid, IPC_RMID, NULL);
	return 0;
}
