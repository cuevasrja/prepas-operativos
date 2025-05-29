#ifndef HILOS_H
#define HILOS_H

// Pipe: 0 for reading, 1 for writing
int pipefd[2]; // Pipe file descriptors

/**
 * @file hilos.c
 * @brief Function executed by the seller thread.
 * This function generates random prices and writes them to the pipe.
 * @param arg Pointer to any argument (not used).
 * @return Returns NULL when the thread finishes execution.
 */
void *seller(void *arg);

/**
 * @file hilos.c
 * @brief Function executed by the consumer thread.
 * This function reads prices from the pipe and processes them.
 * @param arg Pointer to any argument (not used).
 * @return Returns NULL when the thread finishes execution.
 */
void *consumer(void *arg);

#endif