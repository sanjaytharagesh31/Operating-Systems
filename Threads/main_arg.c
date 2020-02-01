#include <stdio.h>
#include <pthread.h>

void *func1() {
	
	int i, s=0;
	for(i=1; i<=10; i++)
		s+=i;
	printf("thread 1 sum: %d\n", s);
}

void *func2() {
	
	int i, s=0;
	for(i=11; i<=20; i++)
		s+=i;
	printf("thread 2 sum: %d\n", s);
}

int main() {
	pthread_t tid, tid2;
	pthread_create(&tid, NULL, func1, NULL);
	pthread_create(&tid2, NULL, func2, NULL);
	pthread_exit(NULL);
	return 0;
}
