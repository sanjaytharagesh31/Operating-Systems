#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	char *m1 = "hello";
	char *m2 = "there";
	char *m3 = "byeee";
	
	int fd[2];
	pipe(fd);
	pid_t pid =	fork();
	
	if(pid > 0) {
		write(fd[1], m1, 6);
		write(fd[1], m2, 6);
		write(fd[1], m3, 6);
		wait(NULL);
	}
	
	else {
		int i=0;
		char buf[100];
		while (read(fd[0], buf, 6))
            printf("% s\n", buf);
	}
	return 0;
}
