#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

void inicializarArbol(ArbolBinario* arbol) {
    arbol->raiz = NULL;
    arbol->altura = 0;
    arbol->tam = 0;
}

NodoBinario* crearNodoBinario(char* dato) {
    NodoBinario* nodo = (NodoBinario*)malloc(sizeof(NodoBinario));
    nodo->dato = dato;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

void agregarArbol(ArbolBinario* arbol, char* dato) {
    NodoBinario* nuevo = crearNodoBinario(dato);
    agregarNodo(&arbol->raiz, nuevo);
    arbol->tam++;
}

int reglaDeInsercion(char* dato) {
    return (dato[0] >= 'A' && dato[0] <= 'C') || (strlen(dato) < 6);
}

void agregarNodo(NodoBinario** raiz, NodoBinario* nuevo) {
    if (*raiz == NULL) {
        *raiz = nuevo;
        return;
    }

    if (reglaDeInsercion(nuevo->dato)) {
        agregarNodo(&(*raiz)->izq, nuevo);
    } else {
        agregarNodo(&(*raiz)->der, nuevo);
    }
}

// Función para recorrido BFS (por nivel)
void BFS(const ArbolBinario* arbol, void (*imprimir)(char*)) {
    if (arbol->raiz == NULL) return;

    NodoBinario* cola[100];
    int frente = 0, final = 0;

    cola[final++] = arbol->raiz;

    while (frente < final) {
        NodoBinario* actual = cola[frente++];
        imprimir(actual->dato);

        if (actual->izq != NULL) cola[final++] = actual->izq;
        if (actual->der != NULL) cola[final++] = actual->der;
    }
}
