#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;
    struct dirent *dir;
    DIR *d;

    // Verificar si se pasó un argumento (nombre del directorio)
    if(argc != 2) {
        printf("Uso: %s <nombre del directorio>\n", argv[0]);
        return 1;
    }

    // Intentar abrir el directorio especificado
    d = opendir(argv[1]);
    // Verificar si se pudo abrir el directorio
    if(d == NULL) {
        perror(argv[1]);
        printf("No se pudo abrir el directorio: %s\n", argv[1]);
        printf("Asegúrese de que el directorio existe y tiene permisos de lectura.\n");
        printf("Si el directorio no existe, puede crearlo con 'mkdir %s'.\n", argv[1]);
        printf("Si el directorio existe, verifique los permisos con 'ls -ld %s'.\n", argv[1]);
        return 2;
    }

    // Imprimir encabezados de la tabla
    printf("File name \tDevice \t Inode \t Mode \t Links \t UID \t GID \t Rdev \t Size \t Blksize \t Blocks \t Atime \t Mtime\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    // Leer los archivos del directorio
    while((dir = readdir(d)) != NULL) {
        // Ignorar los directorios especiales "." y ".."
        if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
            continue;
        }
        // Sistat devuelve un error, imprimir el error y salir
        if(stat(dir->d_name,&fileStat) < 0) {
            perror(dir->d_name);
            return 3;
        }
        printf("%s\t%ld\t%ld\t%d\t%ld\t%d\t%d\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\n",dir->d_name,fileStat.st_dev,fileStat.st_ino,fileStat.st_mode,fileStat.st_nlink,fileStat.st_uid,fileStat.st_gid,fileStat.st_rdev,fileStat.st_size,fileStat.st_blksize,fileStat.st_blocks,fileStat.st_atime,fileStat.st_mtime);
    }
    closedir(d);
    return 0;
}