
typedef struct NodoBinario {
    int dato;
    struct NodoBinario* izq;
    struct NodoBinario* der;
} NodoBinario;

typedef struct ArbolBinario {
    NodoBinario* raiz;
    int altura;
    int tam;
} ArbolBinario;

// Funciones para manejo del árbol binario
void inicializarArbol(ArbolBinario* arbol);
void agregarArbol(ArbolBinario* arbol, int dato);
void agregarNodo(NodoBinario** raiz, NodoBinario* nuevo);

// Recorrido del árbol binario
void inOrden(const ArbolBinario* arbol, void (*imprimir)(int));

