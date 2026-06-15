#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forks[N];
pthread_t philosophers[N];

void* philosopher(void* num) {
    int id = *(int*)num;
    int left = id;
    int right = (id + 1) % N;
    
    // To avoid deadlock, philosopher N-1 picks up right fork first
    int first = (id == N - 1) ? right : left;
    int second = (id == N - 1) ? left : right;

    for (int i = 0; i < 3; i++) {
        printf("Philosopher %d is thinking.\n", id);
        usleep(rand() % 100000);
        
        pthread_mutex_lock(&forks[first]);
        pthread_mutex_lock(&forks[second]);
        
        printf("Philosopher %d is eating.\n", id);
        usleep(rand() % 100000);
        
        pthread_mutex_unlock(&forks[second]);
        pthread_mutex_unlock(&forks[first]);
    }
    return NULL;
}

int main(void) {
    int ids[N];
    for (int i = 0; i < N; i++) pthread_mutex_init(&forks[i], NULL);
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }
    for (int i = 0; i < N; i++) pthread_join(philosophers[i], NULL);
    for (int i = 0; i < N; i++) pthread_mutex_destroy(&forks[i]);
    return 0;
}
