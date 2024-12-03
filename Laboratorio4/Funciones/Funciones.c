#include "Funciones.h"

// Funciones para manejo de matrices

int* crearMatriz(int filas, int columnas) {
    return (int*)malloc(filas * columnas * sizeof(int));
}

void liberarMatriz(int* matriz) {
    free(matriz);
}

void inicializarMatriz(int* matriz, int filas, int columnas) {
    for (int i = 0; i < filas * columnas; i++) {
        matriz[i] = rand() % 10;
    }
}

void imprimirMatriz(int* matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i * columnas + j]);
        }
        printf("\n");
    }
}

int* prodSum(int* A, int* B, int filas, int columnas) {
    int* C = crearMatriz(filas, columnas);
    for (int i = 0; i < filas * columnas; i++) {
        C[i] = A[i] + B[i];
    }
    return C;
}

// Funciones para manejo de la pila

Nodo* crearNodo(int* matriz) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->matriz = matriz;
    nodo->siguiente = NULL;
    return nodo;
}

void inicializarPila(Pila* pila) {
    pila->head = NULL;
    pila->tail = NULL;
    pila->size = 0;
}

void Push(Pila* pila, int* matriz) {
    Nodo* nuevoNodo = crearNodo(matriz);
    if (pila->tail == NULL) {
        pila->head = nuevoNodo;
    } else {
        pila->tail->siguiente = nuevoNodo;
    }
    pila->tail = nuevoNodo;
    pila->size += 1;
}

int* Pop(Pila* pila) {
    if (pila->size == 0) {
        fprintf(stderr, "Error: la pila está vacía\n");
        exit(EXIT_FAILURE);
    }

    Nodo* actual = pila->head;
    Nodo* anterior = NULL;

    while (actual->siguiente != NULL) {
        anterior = actual;
        actual = actual->siguiente;
    }

    int* matriz = actual->matriz;

    if (anterior == NULL) { // Solo un elemento en la pila
        pila->head = NULL;
        pila->tail = NULL;
    } else {
        anterior->siguiente = NULL;
        pila->tail = anterior;
    }

    free(actual);
    pila->size -= 1;

    return matriz;
}

int* Peek(Pila* pila) {
    if (pila->tail == NULL) {
        fprintf(stderr, "Error: la pila está vacía\n");
        exit(EXIT_FAILURE);
    }
    return pila->tail->matriz;
}

int EstaVacia(Pila* pila) {
    return pila->size == 0;
}

void liberarPila(Pila* pila) {
    while (!EstaVacia(pila)) {
        liberarMatriz(Pop(pila));
    }
}
