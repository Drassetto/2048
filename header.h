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
void deslizar_izquierda(InstanciaTablero instancia);
void compactar_horiz(InstanciaTablero instancia);
void mover_izquierda(InstanciaTablero instancia);

void deslizar_derecha(InstanciaTablero instancia);
void mover_derecha(InstanciaTablero instancia);

void deslizar_arriba(InstanciaTablero instancia);
void compactar_vertical(InstanciaTablero instancia);
void mover_arriba(InstanciaTablero instancia);

void deslizar_abajo(InstanciaTablero instancia);
void mover_abajo(InstanciaTablero instancia);
