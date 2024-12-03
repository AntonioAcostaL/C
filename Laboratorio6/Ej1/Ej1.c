#include <stdio.h>
#include "Funciones/Funciones.h"

void imprimirEntero(int dato) {
    printf("%d ", dato);
}

int main() {
    ArbolBinario arbol;
    inicializarArbol(&arbol);

    int valores[] = {42, 61, -71, 71, -80, 16, -54, 97, 40, 81, -53, 14, 79, -49, 56, 45, 87, -65, -80, 82};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        agregarArbol(&arbol, valores[i]);
    }

    printf("Números del mayor al menor (InOrden): ");
    inOrden(&arbol, imprimirEntero);
    printf("\n");

    return 0;
}
