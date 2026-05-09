#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t fork1, fork2;
void *philosopher(void *num)
{
    int id = *(int *)num;
    printf("Philosopher %d is thinking\n", id);
    sem_wait(&fork1);
    sem_wait(&fork2);
    printf("Philosopher %d is eating\n", id);
    sleep(1);
    sem_post(&fork1);
    sem_post(&fork2);
    printf("Philosopher %d finished eating\n", id);
    return NULL;
}
int main()
{
    pthread_t p1, p2;
    int a = 1, b = 2;
    sem_init(&fork1, 0, 1);
    sem_init(&fork2, 0, 1);
    pthread_create(&p1, NULL, philosopher, &a);
    pthread_create(&p2, NULL, philosopher, &b);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    sem_destroy(&fork1);
    sem_destroy(&fork2);

    return 0;
}
