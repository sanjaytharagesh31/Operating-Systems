#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
 
    //open the file
    int fd = open("content.txt", O_RDWR|O_CREAT);
    printf("File descriptor of created file is %d\n", fd);
    char buf[10] = "abcdfgersd";
    write(fd, buf, 10);
    char *ans;
    int s = read(fd, ans, 10);
    printf("%s \n", ans);
    close(fd);
    return 0;
}