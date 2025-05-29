#ifndef MAIN_H
#define MAIN_H

char* menu[] = {
    "Salir",
    "Jugar",
    "Usar item",
    "Saludar",
    "Ir a la tienda",
    "Mostrar inventario",
};

int cantidadOpciones;

/**
 * @brief Funcion que busca el indice de un string en un array de strings
 * @file main.c
 * Funcion que busca un item en un arreglo
 * @param arr: arreglo de strings
 * @param item: item a buscar
 * @return posicion del item en el arreglo, -1 si no se encuentra
*/
int buscarIndice(char* arr[], char* item, int n);

/**
 * @brief Funcion que muestra las opciones del menu.
 * @file main.c
 * Funcion que muestra el menu de opciones
 * @return void
 */
void mostrarMenu();

/**
 * @brief Funcion que lee una opcion del menu.
 * @file main.c
 * Funcion que convierte un string a minusculas
 * @param str: string a convertir
 * @return string convertido a minusculas
*/
char* minusculas(char* str);

/**
 * @brief Funcion que lee una opcion del menu.
 * @file main.c
 * Funcion que lee una opcion del menu
 * @return opcion seleccionada
*/
int leerOpcion();

#endif