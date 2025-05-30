#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "selection_sort.h"

/**
 * @file selection_sort.c
 * Swaps two elements in an array.
*/
void swap(int* elementx, int* elementy){
    int temp = *elementx;
    *elementx = *elementy;
    *elementy = temp;
}

/** 
 * @file selection_sort.c
 * Prints the elements of an array.
*/
void arrayprinter(int array[], int len){
    int i;
    for(i = 0; i < len; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/**
 * @file selection_sort.c
 * Performs selection sort on an array using processes.
*/
void selectionSort(int array[], int len){
    // Variables
    int i, j, index;
    pid_t pid;
    // First cycle for selection sort
    for (i = 0; i < len-1; i++){
        index = i;
        // Fork a new process
        pid = fork();
        // If fork is successful, we have two processes: parent and child
        if (pid == 0){
            // Second cycle to find the minimum element
            for (j = i+1; j < len; j++){
                // Change the index if a smaller element is found
                if (array[j] < array[index]){
                    index = j;
                }
            }
            // Take the minimum element and swap it with the first unsorted element
            exit(index);
        }
        //padre
        else if (pid > 0){
            int status;
            // Wait for the child process to finish
            wait(&status);
            // Swap the elements in the parent process
            swap(&array[i], &array[WEXITSTATUS(status)]);
            // Print the array after each swap
            arrayprinter(array, len);
        }
        // If fork fails, print an error message and exit
        else {
            printf("Fork failed \n");
            exit(-1);
        }
    }
}

int main(){
    int array[] = {5, 3, 8, 0, 1};
    int len = sizeof(array)/sizeof(array[0]);
    selectionSort(array, len);
}
