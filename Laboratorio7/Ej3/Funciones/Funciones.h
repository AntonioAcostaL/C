typedef struct NodoBinario {
    char* dato;
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
void agregarArbol(ArbolBinario* arbol, char* dato);
void agregarNodo(NodoBinario** raiz, NodoBinario* nuevo);
NodoBinario* eliminarNodo(NodoBinario* raiz, char* dato);

// Recorrido del árbol binario
void BFS(const ArbolBinario* arbol, void (*imprimir)(char*));
void buscarPorPrefijo(const NodoBinario* nodo, const char* prefijo, void (*imprimir)(char*));
void buscarPorSubcadena(const NodoBinario* nodo, const char* subcadena, void (*imprimir)(char*));

