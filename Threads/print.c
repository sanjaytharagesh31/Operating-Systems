#include <pthread.h>
#include <stdio.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int c= 0;

void *print1() {
    while(1) {
        pthread_mutex_lock(&m);
        if(c>3 && c<6) {
            pthread_cond_wait(&cond1, &m);
            continue;
        }
        else {
            pthread_cond_signal(&cond2);
        }
        printf("Thread 1: %d", c);
        c++;
        pthread_mutex_unlock(&m);
        
    }        
}

void *print2() {
    while(1) {
        pthread_mutex_lock(&m);
        if(c<3 || c>6) {
            pthread_cond_wait(&cond2, NULL);
            continue;
        }
        else {
            pthread_cond_signal(&cond1);
        }
        printf("Thread 2: %d", c);
        c++;
        pthread_mutex_unlock(&m);
        
    }
}

int main() {
    pthread_t tid, tid2;
    pthread_create(&tid, NULL, print1, NULL);
    pthread_create(&tid2, NULL, print2, NULL);
    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);
    return 0;
}