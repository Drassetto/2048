#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
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

void inicializar_tablero(InstanciaTablero instancia) {
for (int i = 0; i < instancia.dimension; i++) {
        for (int j = 0; j < instancia.dimension; j++) {
            instancia.Tablero[i][j] = 0;
        }
    }
}

void colocar_num(InstanciaTablero instancia) {
    int fila = determinar_pos(instancia.dimension);
    int columna = determinar_pos(instancia.dimension);
    while (instancia.Tablero[fila][columna] != 0) {
        fila = determinar_pos(instancia.dimension);
        columna = determinar_pos(instancia.dimension);
    }
    instancia.Tablero[fila][columna] = dos_o_cuatro();
}

void imprimir_tablero(InstanciaTablero instancia) {
    for (int i = 0; i < instancia.dimension; i++) {
        for (int j = 0; j < instancia.dimension; j++) 
            printf("\t%d\t", instancia.Tablero[i][j]);

    printf("\n");
    }
}

void push(UndoStack* stack, InstanciaTablero instancia){
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->instancia = instancia;
    nuevoNodo->siguiente = stack->cima;
    stack->cima = nuevoNodo;
}

InstanciaTablero pop(UndoStack* stack) {
    if (stack->cima == NULL) {;
        exit(EXIT_FAILURE);
    }
    Nodo* nodoEliminado = stack->cima;
    InstanciaTablero instancia = nodoEliminado->instancia;
    stack->cima = nodoEliminado->siguiente;
    free(nodoEliminado);
    return instancia;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int dimension;
    if (argc < 2) 
        dimension =  pedir_tamaño();
     else 
        dimension =  atoi(argv[1]);
    
    InstanciaTablero Instancia;
    Instancia.dimension = dimension;
    Instancia.Tablero = crear_tablero(dimension);
    inicializar_tablero(Instancia);
    colocar_num(Instancia);
    colocar_num(Instancia);
    int juegoTerminado = 0;
    while (!juegoTerminado) {
    imprimir_tablero(Instancia);
    printf
    return 0;
}
}
