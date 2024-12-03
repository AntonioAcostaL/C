#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Funciones.h"

// Funciones para manejo del árbol binario
NodoBinario* crearNodoBinario(char dato) {
    NodoBinario* nodo = (NodoBinario*)malloc(sizeof(NodoBinario));
    if (nodo == NULL) {
        perror("Error al asignar memoria para el nodo");
        exit(EXIT_FAILURE);
    }
    nodo->dato = dato;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
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

void imprimirNivel(NodoBinario* raiz, int nivel) {
    if (raiz == NULL) return;
    if (nivel == 1) {
        printf("%c ", raiz->dato);
    } else if (nivel > 1) {
        imprimirNivel(raiz->izq, nivel - 1);
        imprimirNivel(raiz->der, nivel - 1);
    }
}

int altura(NodoBinario* nodo) {
    if (nodo == NULL) return 0;
    int alturaIzq = altura(nodo->izq);
    int alturaDer = altura(nodo->der);
    return (alturaIzq > alturaDer) ? (alturaIzq + 1) : (alturaDer + 1);
}

void BFS(const ArbolBinario* arbol, void (*imprimir)(char)) {
    if (arbol == NULL || arbol->raiz == NULL) return;

    int h = altura(arbol->raiz);
    for (int i = 1; i <= h; i++) {
        imprimirNivel(arbol->raiz, i);
        printf("\n");
    }
}

// Funciones auxiliares para manejar expresiones
int precedencia(char operador) {
    switch (operador) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        case '(': 
        case ')': return 0;
    }
    return -1;
}

int esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')');
}

char* infijaAPostfija(const char* expresion) {
    int longitud = strlen(expresion);
    char* postfija = (char*)malloc((longitud + 1) * sizeof(char));
    if (postfija == NULL) {
        perror("Error al asignar memoria para la expresión postfija");
        exit(EXIT_FAILURE);
    }
    char pila[100];
    int tope = -1, k = 0;

    for (int i = 0; i < longitud; i++) {
        if (isalnum(expresion[i])) {
            postfija[k++] = expresion[i];
        } else if (expresion[i] == '(') {
            pila[++tope] = expresion[i];
        } else if (expresion[i] == ')') {
            while (tope != -1 && pila[tope] != '(') {
                postfija[k++] = pila[tope--];
            }
            tope--; // Eliminar '(' de la pila
        } else if (esOperador(expresion[i])) {
            while (tope != -1 && precedencia(pila[tope]) >= precedencia(expresion[i])) {
                postfija[k++] = pila[tope--];
            }
            pila[++tope] = expresion[i];
        }
    }

    while (tope != -1) {
        postfija[k++] = pila[tope--];
    }
    postfija[k] = '\0';

    return postfija;
}

ArbolBinario* construirArbolDeExpresion(const char* expresionPostfija) {
    ArbolBinario* arbol = (ArbolBinario*)malloc(sizeof(ArbolBinario));
    if (arbol == NULL) {
        perror("Error al asignar memoria para el árbol");
        exit(EXIT_FAILURE);
    }
    arbol->raiz = NULL;
    NodoBinario* pila[100];
    int tope = -1;

    int longitud = strlen(expresionPostfija);
    for (int i = 0; i < longitud; i++) {
        NodoBinario* nodo = crearNodoBinario(expresionPostfija[i]);

        if (!esOperador(expresionPostfija[i])) {
            pila[++tope] = nodo;
        } else {
            if (tope < 1) {
                fprintf(stderr, "Expresión postfija inválida\n");
                exit(EXIT_FAILURE);
            }
            nodo->der = pila[tope--];
            if (esOperador(expresionPostfija[i]) && esOperador(expresionPostfija[i - 1])) {
                nodo->izq = NULL;
            } else {
                nodo->izq = pila[tope--];
            }
            pila[++tope] = nodo;
        }
    }

    if (tope != 0) {
        fprintf(stderr, "Expresión postfija inválida\n");
        exit(EXIT_FAILURE);
    }
    arbol->raiz = pila[tope];
    return arbol;
}
