#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include "hilos.h"

/**
 * @file hilos.c
 * Implementation of the seller thread
 */
void *seller(void *arg) {
    int price;
    for (int i = 0; i < 10; i++) {
        price = rand() % 100 + 1; // Generate a random price
        write(pipefd[1], &price, sizeof(price)); // Write price to pipe
        printf("Seller: Price set to %d\n", price);
        sleep(1); // Simulate time taken to set price
    }
    return NULL;
}

/**
 * @file hilos.c
 * Implementation of the consumer thread
 */
void *consumer(void *arg) {
    int price;
    for (int i = 0; i < 10; i++) {
        read(pipefd[0], &price, sizeof(price)); // Read price from pipe
        printf("Consumer: Price received is %d\n", price);
        sleep(1); // Simulate time taken to process price
    }
    return NULL;
}

int main(){
    pthread_t sell, cons;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create the seller thread
    pthread_create(&sell, NULL, seller, NULL);

    // Create the consumer thread
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for the seller thread to finish
    pthread_join(sell, NULL);

    // Wait for the consumer thread to finish
    pthread_join(cons, NULL);
}