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

NodoBinario* encontrarMinimo(NodoBinario* nodo) {
    while (nodo && nodo->izq != NULL) {
        nodo = nodo->izq;
    }
    return nodo;
}

NodoBinario* eliminarNodo(NodoBinario* raiz, int dato) {
    if (raiz == NULL) return raiz;

    if (dato < raiz->dato) {
        raiz->izq = eliminarNodo(raiz->izq, dato);
    } else if (dato > raiz->dato) {
        raiz->der = eliminarNodo(raiz->der, dato);
    } else {
        if (raiz->izq == NULL) {
            NodoBinario* temp = raiz->der;
            free(raiz);
            return temp;
        } else if (raiz->der == NULL) {
            NodoBinario* temp = raiz->izq;
            free(raiz);
            return temp;
        }

        NodoBinario* temp = encontrarMinimo(raiz->der);
        raiz->dato = temp->dato;
        raiz->der = eliminarNodo(raiz->der, temp->dato);
    }

    return raiz;
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
