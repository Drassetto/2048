#include "header.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
InstanciaTablero deslizar_izquierda(InstanciaTablero instancia) {
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
    return instancia;
}
InstanciaTablero compactar_horiz(InstanciaTablero instancia) {
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
    return instancia;
}
InstanciaTablero mover_izquierda(InstanciaTablero instancia) {
    deslizar_izquierda(instancia);
    compactar_izquierda(instancia);
    deslizar_izquierda(instancia);
    return instancia;
}



InstanciaTablero deslizar_derecha(InstanciaTablero instancia) {
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
    return instancia;
}

InstanciaTablero mover_derecha(InstanciaTablero instancia) {
    deslizar_derecha(instancia);
    compactar_derecha(instancia);
    deslizar_derecha(instancia);
    return instancia;
}

InstanciaTablero deslizar_arriba(InstanciaTablero instancia) {
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
    return instancia;
}
InstanciaTablero compactar_vertical(InstanciaTablero instancia) {
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
    return instancia;
}
InstanciaTablero mover_arriba(InstanciaTablero instancia) {
    deslizar_arriba(instancia);
    compactar_arriba(instancia);
    deslizar_arriba(instancia);
    return instancia;
}

InstanciaTablero deslizar_abajo(InstanciaTablero instancia) {
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
    return instancia;
}

InstanciaTablero mover_abajo(InstanciaTablero instancia) {
    deslizar_abajo(instancia);
    compactar_abajo(instancia);
    deslizar_abajo(instancia);
    return instancia;
}

InstanciaTablero mover(InstanciaTablero instancia) {
    int direccion = getch();
    if (direccion == 224) {
        direccion = getch();
    }
    switch (direccion) {
        case 119: 
        case FLECHA_ARRIBA:
            return mover_arriba(instancia);
        break;
        case 97:
        case FLECHA_IZQUIERDA:
            return mover_izquierda(instancia);
            break;
        case 115:
        case FLECHA_ABAJO:
            return mover_abajo(instancia);
         break;
        case 100:
        case FLECHA_DERECHA:
            return mover_derecha(instancia);
            break;
        default:
            return instancia;
    }
}
