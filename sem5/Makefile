# Prepa Semana 5 - Sistemas Operativos 1 (CI-3825)
# Juan Andres Cuevas 19-10056

# Variables
CC = gcc
CFLAGS = -c
LFLAGS = -o
SRC = main.c
SRC_H = main.h
TARGET = main.out

HILOS_FLAGS = -lpthread
SRC_HILOS = hilos.c
SRC_HILOS_H = hilos.h
TARGET_HILOS = $(patsubst %.c,%.out,$(SRC_HILOS))

SRC_SELEC = selection_sort.c
SRC_SELEC_H = selection_sort.h
TARGET_SELEC = $(patsubst %.c,%.out,$(SRC_SELEC))


# Reglas
.PHONY : all clean

all: main hilos selection

hilos:
	$(CC) $(HILOS_FLAGS) -o $(TARGET_HILOS) $(SRC_HILOS) $(SRC_HILOS_H)

selection:
	$(CC) -o $(TARGET_SELEC) $(SRC_SELEC) $(SRC_SELEC_H)

main: 
	$(CC) $(LFLAGS) $(TARGET) $(SRC) $(SRC_H)

clean :
	rm -rf $(TARGET) *.out *.o