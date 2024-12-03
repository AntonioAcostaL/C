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

NodoBinario* encontrarMinimo(NodoBinario* nodo) {
    while (nodo && nodo->izq != NULL) {
        nodo = nodo->izq;
    }
    return nodo;
}

NodoBinario* eliminarNodo(NodoBinario* raiz, char* dato) {
    if (raiz == NULL) return raiz;

    if (strcmp(dato, raiz->dato) < 0) {
        raiz->izq = eliminarNodo(raiz->izq, dato);
    } else if (strcmp(dato, raiz->dato) > 0) {
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

// Función para buscar palabras por prefijo
void buscarPorPrefijo(const NodoBinario* nodo, const char* prefijo, void (*imprimir)(char*)) {
    if (nodo == NULL) return;

    if (strncmp(nodo->dato, prefijo, strlen(prefijo)) == 0) {
        imprimir(nodo->dato);
    }
    buscarPorPrefijo(nodo->izq, prefijo, imprimir);
    buscarPorPrefijo(nodo->der, prefijo, imprimir);
}

// Función para buscar palabras por subcadena
void buscarPorSubcadena(const NodoBinario* nodo, const char* subcadena, void (*imprimir)(char*)) {
    if (nodo == NULL) return;

    if (strstr(nodo->dato, subcadena) != NULL) {
        imprimir(nodo->dato);
    }
    buscarPorSubcadena(nodo->izq, subcadena, imprimir);
    buscarPorSubcadena(nodo->der, subcadena, imprimir);
}
