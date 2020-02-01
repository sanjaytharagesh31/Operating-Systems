#include<stdio.h> 
#include <fcntl.h> 
int main() 
{ 
  int sz; 
  
  int fd = open("foo.txt", O_WRONLY); 
  if (fd < 0) 
  { 
     perror("r1"); 
     exit(1); 
  } 
  
  sz = write(fd, "hello geeks\n", strlen("hello geeks\n")); 
  
  printf("called write(% d, \"hello geeks\\n\", %d)."
    " It returned %d\n", fd, strlen("hello geeks\n"), sz); 
  
  close(fd); 
  return 0;
}
