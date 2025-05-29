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
    //variables
    int i, j, index;
    pid_t pid;
    //primer ciclo for
    for (i = 0; i < len-1; i++){
        index = i;
        //fork, aqui el padre espera a que el hijo termine
        pid = fork();
        //hijo
        if (pid == 0){
            //segundo ciclo for
            for (j = i+1; j < len; j++){
                //cambio de indice del menor elemento
                if (array[j] < array[index]){
                    index = j;
                }
            }
            //ponemos que el proceso salga con index para asi llamarlo desde el padre
            exit(index);
        }
        //padre
        else if (pid > 0){
            int status;
            //espera a que el hijo acabe
            wait(&status);
            //swap
            swap(&array[i], &array[WEXITSTATUS(status)]);
            //imprimir el array para verificar
            arrayprinter(array, len);
        }
        //si fork falla
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
