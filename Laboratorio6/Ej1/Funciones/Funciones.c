#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void inicializarArbol(ArbolBinario* arbol) {
    arbol->raiz = NULL;
    arbol->altura = 0;
    arbol->tam = 0;
}

NodoBinario* crearNodoBinario(int dato) {
    NodoBinario* nodo = (NodoBinario*)malloc(sizeof(NodoBinario));
    nodo->dato = dato;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

void agregarArbol(ArbolBinario* arbol, int dato) {
    NodoBinario* nuevo = crearNodoBinario(dato);
    agregarNodo(&arbol->raiz, nuevo);
    arbol->tam++;
}

void agregarNodo(NodoBinario** raiz, NodoBinario* nuevo) {
    if (*raiz == NULL) {
        *raiz = nuevo;
        return;
    }

    if (nuevo->dato < (*raiz)->dato) {
        agregarNodo(&(*raiz)->izq, nuevo);
    } else {
        agregarNodo(&(*raiz)->der, nuevo);
    }
}

void inOrdenRecursivo(NodoBinario* nodo, void (*imprimir)(int)) {
    if (nodo == NULL) return;
    inOrdenRecursivo(nodo->der, imprimir);
    imprimir(nodo->dato);
    inOrdenRecursivo(nodo->izq, imprimir);
}

void inOrden(const ArbolBinario* arbol, void (*imprimir)(int)) {
    inOrdenRecursivo(arbol->raiz, imprimir);
}
