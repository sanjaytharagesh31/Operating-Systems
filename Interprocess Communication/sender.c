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
	int msqid;
	key_t key = 1234;
	msqid = msgget(key, IPC_CREAT|0666);
	m.type = 100;
	strcpy(m.str, "I am sending message!");
	msgsnd(msqid, &m, sizeof(m), IPC_NOWAIT);
	struct msg m_cp;
	m_cp.type = 101;
	strcpy(m_cp.str, "Here is the 2nd message");
	msgsnd(msqid, &m_cp, sizeof(m_cp), IPC_NOWAIT);
	return 0;
}
