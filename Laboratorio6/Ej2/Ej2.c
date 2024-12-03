#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones/Funciones.h"

void imprimirPalabra(char* palabra) {
    printf("%s ", palabra);
}

int main() {
    ArbolBinario arbol;
    inicializarArbol(&arbol);

    char* palabras[] = {"Amor", "Azul", "Casa", "Broma", "Cielo", "Dedal", "Esfera", "Florido", "Generoso", "Aguacates"};
    int n = sizeof(palabras) / sizeof(palabras[0]);

    for (int i = 0; i < n; i++) {
        char* palabra = (char*)malloc((strlen(palabras[i]) + 1) * sizeof(char));
        strcpy(palabra, palabras[i]);
        agregarArbol(&arbol, palabra);
    }

    printf("Árbol impreso por nivel (BFS): ");
    BFS(&arbol, imprimirPalabra);
    printf("\n");

    return 0;
}
