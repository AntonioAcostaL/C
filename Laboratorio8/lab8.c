#include <stdio.h>
#include <stdlib.h>
#include "Funciones/Funciones.h"

void imprimirNodo(char dato) {
    printf("%c ", dato);
}

void resolverExpresion(const char* expresion) {
    printf("Expresión infija: %s\n", expresion);

    char* postfija = infijaAPostfija(expresion);
    printf("Expresión postfija: %s\n", postfija);

    ArbolBinario* arbol = construirArbolDeExpresion(postfija);
    printf("Árbol de expresión (por niveles):\n");
    BFS(arbol, imprimirNodo);

    free(postfija);
    free(arbol);
}

int main() {
    printf("Problema 1:\n");
    resolverExpresion("(P*Q)+C^(-D)");

    printf("Problema 2:\n");
    resolverExpresion("A^B^C");

    printf("Problema 3:\n");
    resolverExpresion("A+B*C/F^H");

    return 0;
}
