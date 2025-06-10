#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


/*
Lee las primeras n líneas de un archivo y muestra su información de estado.
Este programa utiliza la estructura stat para obtener información sobre un archivo.
*/
int main(int argc, char const *argv[])
{
    // Verificar si se pasaron los argumentos correctos
    // En este caso, se esperan dos argumentos: el nombre del archivo y el número de líneas a leer
    if(argc != 3) {
        printf("Uso: %s <nombre del archivo> <n>\n", argv[0]);
        return 1;
    }

    // Convertir el segundo argumento a un entero
    int n = atoi(argv[2]);
    if(n <= 0) {
        printf("El número de líneas debe ser un entero positivo.\n");
        return 1;
    }
    // Estructura para almacenar la información del archivo
    struct stat fileStat;
    // Intentar obtener la información del archivo
    if(stat(argv[1], &fileStat) < 0) {
        perror("Error al obtener el estado del archivo");
        return 1;
    }
    // Imprimir la información del archivo
    printf("Información del archivo: %s\n", argv[1]);
    printf("Dispositivo: %ld\n", fileStat.st_dev);
    printf("Inodo: %ld\n", fileStat.st_ino);
    printf("Modo: %o\n", fileStat.st_mode);
    printf("Número de enlaces: %ld\n", fileStat.st_nlink);
    printf("UID: %d\n", fileStat.st_uid);
    printf("GID: %d\n", fileStat.st_gid);
    printf("Dispositivo especial: %ld\n", fileStat.st_rdev);
    printf("Tamaño: %ld bytes\n", fileStat.st_size);
    printf("Bloques: %ld\n", fileStat.st_blocks);
    printf("Tamaño de bloque: %ld bytes\n", fileStat.st_blksize);
    printf("Último acceso: %ld\n", fileStat.st_atime);
    printf("Última modificación: %ld\n", fileStat.st_mtime);
    printf("Último cambio de estado: %ld\n", fileStat.st_ctime);

    // Abrir el archivo para leer las primeras n líneas
    FILE *file = fopen(argv[1], "r");
    if(file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    if (ferror(file)) {
        perror("Error al leer el archivo");
        fclose(file);
        return 1;
    }

    printf("\nLeyendo las primeras %d líneas del archivo %s:\n", n, argv[1]);

    char line[256];
    int lineCount = 0;
    // Leer el archivo línea por línea
    while(fgets(line, sizeof(line), file) != NULL && lineCount < n) {
        // Imprimir la línea leída
        printf("Línea %d: %s", lineCount + 1, line);
        lineCount++;
    }
    printf("\n");

    // Cerrar el archivo
    fclose(file);

    // Si se leyeron menos líneas de las esperadas, informar al usuario
    if(lineCount < n) {
        printf("Se leyeron solo %d líneas del archivo %s.\n", lineCount, argv[1]);
    } else {
        printf("Se leyeron las primeras %d líneas del archivo %s.\n", n, argv[1]);
    }

    return 0;
}
