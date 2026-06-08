#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


int pedir_tamaño() {
    int tamaño;
    printf("Ingresar Tamaño del Tablero:    \n");
    scanf("%i", &tamaño);
    return tamaño;
}

int dos_o_cuatro() {
    int num = rand() % 4;
    if (num == 1) {
        return 4;
    } else {
        return 2;
    }
}
int determinar_pos(int dimension) {
    int pos = rand() % dimension;
    return pos;
}

int** crear_tablero(int dimension) {
    int **Tablero = (int**)malloc(dimension*sizeof(int*));
    for (int contador = 0; contador < dimension; contador++) {
        Tablero[contador]= (int*)malloc(dimension*sizeof(int));
    }
return Tablero;  
}

void inicializar_tablero(int** Tablero, int dimension){
for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            Tablero[i][j] = 0;
}}


}


void colocar_num(int** Tablero, int dimension){
    int fila = determinar_pos(dimension);
    int columna = determinar_pos(dimension);
    while (Tablero[fila][columna] != 0) {
        fila = determinar_pos(dimension);
        columna = determinar_pos(dimension);
    }
    Tablero[fila][columna] = dos_o_cuatro();
}


void imprimir_tablero(int** Tablero, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) 
            printf("\t%d\t", Tablero[i][j]);

    printf("\n");
}
}


int main(int argc, char *argv[]) {
    srand(time(NULL));
    int dimension;
    if (argc < 2) 
        dimension =  pedir_tamaño();
     else 
        dimension =  atoi(argv[1]);
    
    int** Tablero = crear_tablero(dimension);
    inicializar_tablero(Tablero, dimension);
    colocar_num(Tablero, dimension);
    colocar_num(Tablero, dimension);
    imprimir_tablero(Tablero, dimension);
    return 0;
}
