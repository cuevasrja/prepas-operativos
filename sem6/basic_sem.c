#include <stdio.h>
#include <pthread.h>

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t condition;
    int value;
} semaphore;

void semaphore_init(semaphore* sem, int initial_value) {
    pthread_mutex_init(&(sem->mutex), NULL);
    pthread_cond_init(&(sem->condition), NULL);
    sem->value = initial_value;
}

void semaphore_wait(semaphore* sem) {
    pthread_mutex_lock(&(sem->mutex));
    printf("Waiting for semaphore, current value: %d\n", sem->value);
    while (sem->value <= 0) {
        pthread_cond_wait(&(sem->condition), &(sem->mutex));
    }
    sem->value--;
    printf("Semaphore acquired, current value: %d\n", sem->value);
    pthread_mutex_unlock(&(sem->mutex));
}

void semaphore_signal(semaphore* sem) {
    pthread_mutex_lock(&(sem->mutex));
    printf("Releasing semaphore, current value: %d\n", sem->value);
    sem->value++;
    printf("Semaphore released, current value: %d\n", sem->value);
    pthread_cond_signal(&(sem->condition));
    pthread_mutex_unlock(&(sem->mutex));
}

void* thread_function(void* arg) {
    semaphore* sem = (semaphore*)arg;

    printf("Thread waiting\n");
    semaphore_wait(sem);

    printf("Thread acquired the semaphore\n");
    // Perform some critical section or shared resource access here

    printf("Thread releasing the semaphore\n");
    semaphore_signal(sem);

    return NULL;
}

int main() {
    semaphore sem;
    semaphore_init(&sem, 1); // Initialize the semaphore with initial value 1

    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, (void*)&sem);

    // Main thread also performs some work
    printf("Main thread performing some work\n");

    // Main thread waits for the semaphore
    printf("Main thread waiting\n");
    semaphore_wait(&sem);

    printf("Main thread acquired the semaphore\n");
    // Perform some critical section or shared resource access here

    printf("Main thread releasing the semaphore\n");
    semaphore_signal(&sem);

    pthread_join(thread, NULL);

    return 0;
}
