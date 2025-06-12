#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

int cantidadOpciones = sizeof(menu) / sizeof(menu[0]);

/**
 * Funcion que busca un item en un arreglo
*/
int buscarIndice(char* arr[], char* item, int n){
    char* item1 = minusculas(item);
    int i = 0;
    while(i < n){
        char* item2 = minusculas(arr[i]);
        if (strcmp(item1, item2) == 0) return i;
        i++;
    }
    return -1;
}

/**
 * Funcion que muestra el menu
*/
void mostrarMenu(){
    int i = 0;
    while(i < cantidadOpciones){
        printf("\033[92m%d.\033[0m %s\n", i+1, menu[i]);
        i++;
    }
}

/**
 * Funcion que convierte un string a minusculas
*/
char* minusculas(char* str){
    char* str2 = malloc(strlen(str) * sizeof(char));
    if (str2 == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (i < strlen(str)){
        str2[i] = tolower(str[i]);
        i++;
    }
    return str2;
}

/**
 * Funcion que lee una opcion del menu
*/
int leerOpcion(){
    int opcion = -1;
    char* texto = malloc(100 * sizeof(char));
    if (texto == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    printf("Ingrese una opcion: \033[92;1m");
    // Leemos el texto con espacios
    scanf(" %[^\n]s", texto);
    opcion = buscarIndice(menu, texto, cantidadOpciones);
    printf("\033[0m");
    printf("\n");
    free(texto);
    return opcion;
}

int main(int argc, char const *argv[]) {
    int opcion = -1;
    // Mientras la opcion no sea salir
    while(opcion != 0){
        // Mostrar menu
        mostrarMenu();
        // leer opcion
        opcion = leerOpcion();
        switch(opcion){
            case 0: // Salir
                printf("\033[91;1mSaliendo...\033[0m\n");
                break;
            case 1: // Jugar (Se apuesta)
                printf("\033[96mTu\033[0m: Vamos a jugar!\n\n");
                break;
            case 2: // Usar consumible
                printf("\033[96mTu\033[0m: Usando consumible...\n\n");
                break;
            case 3: // Saludar
                printf("\033[96mTu\033[0m: Hola, Pikachu!\n\n");
                break;
            case 4: // Ir a la tienda
                printf("\033[96mTu\033[0m: Vamos a la tienda!\n\n");
                break;
            case 5: // Mostrar Inventario
                printf("\033[96mTu\033[0m: Mostrando inventario...\n\n");
                break;
            default:
                printf("\033[91mOpcion invalida\033[0m\n");
                break;
        }
    }
    return 0;
}
