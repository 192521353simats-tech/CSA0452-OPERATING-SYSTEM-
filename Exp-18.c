#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t empty, full, mutex;
int x = 0;
void *producer(void *arg)
{
    sem_wait(&empty);
    sem_wait(&mutex);
    x++;
    printf("Producer produces item %d\n", x);
    sem_post(&mutex);
    sem_post(&full);
    return NULL;
}
void *consumer(void *arg)
{
    sem_wait(&full);
    sem_wait(&mutex);
    printf("Consumer consumes item %d\n", x);
    x--;
    sem_post(&mutex);
    sem_post(&empty);
    return NULL;
}

int main()
{
    pthread_t p, c;
    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
