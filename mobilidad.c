#include "header.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
void deslizar_izquierda(InstanciaTablero instancia) {
for (int i = 0; i < instancia.dimension; i++) {
        int pos = 0; 
        for (int j = 0; j < instancia.dimension; j++) {
            if (instancia.Tablero[i][j] != 0) {

                instancia.Tablero[i][pos] = instancia.Tablero[i][j];

                if (pos != j) {
                    instancia.Tablero[i][j] = 0;
                }
                pos++;
            }
        }
    }
}
void compactar_horiz(InstanciaTablero instancia) {
for (int i = 0; i < instancia.dimension; i++) {
       
        for (int j = 0; j < instancia.dimension - 1; j++) {
            if (instancia.Tablero[i][j] != 0 && instancia.Tablero[i][j] == instancia.Tablero[i][j + 1]) {
                instancia.Tablero[i][j] *= 2;
                instancia.Tablero[i][j + 1] = 0;
            }else if(instancia.Tablero[i][j] != 0 && instancia.Tablero[i][j] == instancia.Tablero[i][j - 1]){
                instancia.Tablero[i][j] *= 2;
                instancia.Tablero[i][j - 1] = 0;
        }
    }
}
void mover_izquierda(InstanciaTablero instancia) {
    deslizar_izquierda(instancia);
    compactar_horiz(instancia);
    deslizar_izquierda(instancia);
}



void deslizar_derecha(InstanciaTablero instancia) {
for (int i = 0; i < instancia.dimension; i++) {
        int pos = instancia.dimension - 1; 
        for (int j = instancia.dimension - 1; j >= 0; j--) {
            if (instancia.Tablero[i][j] != 0) {

                instancia.Tablero[i][pos] = instancia.Tablero[i][j];

                if (pos != j) {
                    instancia.Tablero[i][j] = 0;
                }
                pos--;
            }
        }
    }
}

void mover_derecha(InstanciaTablero instancia) {
    deslizar_derecha(instancia);
    compactar_horiz(instancia);
    deslizar_derecha(instancia);
}

void deslizar_arriba(InstanciaTablero instancia) {
for (int j = 0; j < instancia.dimension; j++) {
        int pos = 0; 
        for (int i = 0; i < instancia.dimension; i++) {
            if (instancia.Tablero[i][j] != 0) {

                instancia.Tablero[pos][j] = instancia.Tablero[i][j];

                if (pos != i) {
                    instancia.Tablero[i][j] = 0;
                }
                pos++;
            }
        }
    }
}
void compactar_vertical(InstanciaTablero instancia) {
for (int j = 0; j < instancia.dimension; j++) {
       
        for (int i = 0; i < instancia.dimension - 1; i++) {
                if (instancia.Tablero[i][j] != 0 && instancia.Tablero[i][j] == instancia.Tablero[i + 1][j]) {
                        instancia.Tablero[i][j] *= 2;
                        instancia.Tablero[i + 1][j] = 0;
                }else if (instancia.Tablero[i][j] != 0 && instancia.Tablero[i][j] == instancia.Tablero[i - 1][j]){
                        instancia.Tablero[i][j] *= 2;
                        instancia.Tablero[i - 1][j] = 0;
                }
        }
}
void mover_arriba(InstanciaTablero instancia) {
    deslizar_arriba(instancia);
    compactar_vertical(instancia);
    deslizar_arriba(instancia);
}

void deslizar_abajo(InstanciaTablero instancia) {
for (int j = 0; j < instancia.dimension; j++) {
        int pos = instancia.dimension - 1; 
        for (int i = instancia.dimension - 1; i >= 0; i--) {
            if (instancia.Tablero[i][j] != 0) {

                instancia.Tablero[pos][j] = instancia.Tablero[i][j];

                if (pos != i) {
                    instancia.Tablero[i][j] = 0;
                }
                pos--;
            }
        }
    }
}

void mover_abajo(InstanciaTablero instancia) {
    deslizar_abajo(instancia);
    compactar_vertical(instancia);
    deslizar_abajo(instancia);
}

void mover(InstanciaTablero instancia) {
    int direccion = getch();
    if (direccion == 224) {
        direccion = getch();
    }
    switch (direccion) {
        case 119: 
        case FLECHA_ARRIBA:
                mover_arriba(instancia);
                break;
        case 97:
        case FLECHA_IZQUIERDA:
                mover_izquierda(instancia);
                break;
        case 115:
        case FLECHA_ABAJO:
                mover_abajo(instancia);
                break;
        case 100:
        case FLECHA_DERECHA:
                mover_derecha(instancia);
                break;
    }
}
