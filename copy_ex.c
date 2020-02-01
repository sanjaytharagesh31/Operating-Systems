#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int fd_src = open("/home/tharagesh/code_stuff/OS/hello.txt", O_RDONLY);
	char str[10];
	read(fd_src, str, 10);
	int fd_des = open("/home/tharagesh/code_stuff/OS/hellocopy.txt", O_WRONLY);
	write(fd_des, str, 10);
	close(fd_src);
	close(fd_des);
	return 0;
}	
