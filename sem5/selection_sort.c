#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//Funcion para intercambiar 2 elementos de un array
void swap(int* elementx, int* elementy){
    int temp = *elementx;
    *elementx = *elementy;
    *elementy = temp;
}

//Funcion para imprimir un array
void arrayprinter(int array[], int len){
    int i;
    for(i = 0; i < len; i++)
        printf("%d ", array[i]);
    printf("\n");
}

//Selection sort usando procesos, el proceso padre espera en el elemento i (i yendo desde 0 hasta len-2) que el proceso hijo consiga el indice del menor elemento
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
