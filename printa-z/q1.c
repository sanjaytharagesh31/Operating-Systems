#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
char ch='a';

void *vowels() {
	while(ch<='z') {
	pthread_mutex_lock(&m1);
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') {
		printf("%c", ch);	
		ch++;
		pthread_cond_signal(&cond1);
	}
	else {
		pthread_cond_wait(&cond2, &m1);	
	}
	
	pthread_mutex_unlock(&m1);
	}
}

void *conson() {
	while(ch<='z') {
	pthread_mutex_lock(&m1);
	if(ch!='a'||ch!='e'||ch!='i'||ch!='o'||ch!='u') {
		printf("%c", ch);	
		ch++;
		pthread_cond_signal(&cond2);
	}
	else {
		pthread_cond_wait(&cond1, &m1);	
	}
	
	pthread_mutex_unlock(&m1);
	}
}

int main() {
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, vowels, NULL);
	pthread_create(&tid2, NULL, conson, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
}
