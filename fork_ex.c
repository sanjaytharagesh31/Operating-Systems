// simulate copy command, delete cmd

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
	pid_t pid;
	pid = fork();
	if(pid == -1)
		printf("Fork unsuccessful");
	else if(pid == 0) {
		printf("Inside child process\n");
		printf("parent process id %u \n", getppid());
		printf("Child process id %u \n", getpid()); 	
	}
	else {
		printf("Inside parent process\n");
		printf("parent process id %u \n", getpid());
		printf("Child process id %u \n", pid);
	} 
	return 0;
}
