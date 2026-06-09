typedef struct InstanciaTablero{
    int** Tablero;
    int dimension;
} InstanciaTablero;

typedef struct Nodo{
    InstanciaTablero instancia;
    struct Nodo* siguiente;
} Nodo; 
typedef struct Stack{
    Nodo* cima;
} UndoStack;


int pedir_tamaño();

int** crear_tablero(int dimension);
void inicializar_tablero(InstanciaTablero instancia);
int determinar_pos(int dimension);
int dos_o_cuatro();
void colocar_num(InstanciaTablero instancia);
void imprimir_tablero(InstanciaTablero instancia);

void push(UndoStack* stack, InstanciaTablero instancia);
InstanciaTablero pop(UndoStack* stack);
void liberar_stack(UndoStack* stack);  


#define FLECHA_ARRIBA 72
#define FLECHA_ABAJO 80
#define FLECHA_IZQUIERDA 75
#define FLECHA_DERECHA 77
InstanciaTablero deslizar_izquierda(InstanciaTablero instancia);
InstanciaTablero compactar_izquierda(InstanciaTablero instancia);
InstanciaTablero mover_izquierda(InstanciaTablero instancia);

InstanciaTablero deslizar_derecha(InstanciaTablero instancia);
InstanciaTablero compactar_derecha(InstanciaTablero instancia);
InstanciaTablero mover_derecha(InstanciaTablero instancia);

InstanciaTablero deslizar_arriba(InstanciaTablero instancia);
InstanciaTablero compactar_arriba(InstanciaTablero instancia);
InstanciaTablero mover_arriba(InstanciaTablero instancia);

InstanciaTablero deslizar_abajo(InstanciaTablero instancia);
InstanciaTablero compactar_abajo(InstanciaTablero instancia);
InstanciaTablero mover_abajo(InstanciaTablero instancia);
