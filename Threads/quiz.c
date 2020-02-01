#include <pthread.h>
#include <stdio.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int s = 4;
int order = 0;

void *func() {
    while(1) {
    pthread_mutex_lock(&m);
    if(s == 0) {
        while(order == 0) {
            pthread_cond_signal(&cond);
            printf("Pizza empty signal sent\n");
            order = 1;
        }
        pthread_cond_wait(&cond2, &m);
    }
    else {
        s--;
        printf("Pizza consumed\n");
    }
    pthread_mutex_unlock(&m);
    }
}

void *pizz() {
    while(1) {
    pthread_mutex_lock(&m);
    printf("Delivery waiting\n");
    pthread_cond_wait(&cond, &m);
    s = 4;
    printf("Pizza loaded\n");
    order = 0;
    pthread_cond_signal(&cond2);
    pthread_mutex_unlock(&m);
    
    }
}

int main() {
    pthread_t s1, s2, s3, p;
    pthread_create(&p, NULL, pizz, NULL);
    pthread_create(&s1, NULL, func, NULL);
    pthread_create(&s2, NULL, func, NULL);
    pthread_create(&s3, NULL, func, NULL);
    
    pthread_join(s1, NULL);
    pthread_join(s2, NULL);
    pthread_join(s3, NULL);
    pthread_join(p, NULL);
    return 0;
}