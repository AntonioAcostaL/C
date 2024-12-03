#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int* matriz;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* head;
    Nodo* tail;
    int size;
} Pila;

// Funciones para manejo de la pila
Nodo* crearNodo(int* matriz);
void inicializarPila(Pila* pila);
void Push(Pila* pila, int* matriz);
int* Pop(Pila* pila);
int* Peek(Pila* pila);
int EstaVacia(Pila* pila);
void liberarPila(Pila* pila);

// Funciones para manejo de matrices
int* crearMatriz(int filas, int columnas);
void liberarMatriz(int* matriz);
void inicializarMatriz(int* matriz, int filas, int columnas);
void imprimirMatriz(int* matriz, int filas, int columnas);
int* prodSum(int* A, int* B, int filas, int columnas);


