
typedef struct NodoBinario {
    char dato;
    struct NodoBinario* izq;
    struct NodoBinario* der;
} NodoBinario;

typedef struct ArbolBinario {
    NodoBinario* raiz;
    int altura;
    int tam;
} ArbolBinario;

// Funciones para manejo del árbol binario
NodoBinario* crearNodoBinario(char dato);
void agregarNodo(NodoBinario** raiz, NodoBinario* nuevo);
void imprimirNivel(NodoBinario* raiz, int nivel);
int altura(NodoBinario* nodo);
void BFS(const ArbolBinario* arbol, void (*imprimir)(char));

// Funciones auxiliares para manejar expresiones
int precedencia(char operador);
int esOperador(char c);
char* infijaAPostfija(const char* expresion);
ArbolBinario* construirArbolDeExpresion(const char* expresionPostfija);
