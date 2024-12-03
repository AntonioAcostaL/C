#include <stdio.h>
#include <stdlib.h>
#include "Funciones/Funciones.h"

int main() {
    ListaDobleCircular lista1;
    ListaDobleCircular lista2;
    InicializarLista(&lista1);
    InicializarLista(&lista2);

    // Lista 1: INGENIERO
    char datos1[] = {'I', 'N', 'G', 'E', 'N', 'I', 'E', 'R', 'O'};
    for (int i = 0; i < sizeof(datos1) / sizeof(datos1[0]); ++i) {
        InsertarFinal(&lista1, datos1[i]);
    }

    // Lista 2: SOFTWARE
    char datos2[] = {'S', 'O', 'F', 'T', 'W', 'A', 'R', 'E'};
    for (int i = 0; i < sizeof(datos2) / sizeof(datos2[0]); ++i) {
        InsertarFinal(&lista2, datos2[i]);
    }

    // Concatenación al inicio
    ListaDobleCircular* lista3 = ConcatInicio(&lista1, &lista2);
    printf("Concatenación al inicio:\n");
    MostrarLista(lista3);
    
    // Concatenación al final
    ListaDobleCircular* lista4 = ConcatFinal(&lista1, &lista2);
    printf("Concatenación al final:\n");
    MostrarLista(lista4);

    // Concatenación en posición
    ListaDobleCircular* lista5 = ConcatPos(&lista1, &lista2, 3);
    printf("Concatenación en posición:\n");
    MostrarLista(lista5);

    // Liberar memoria
    LiberarLista(lista3);
    LiberarLista(lista4);
    LiberarLista(lista5);
    free(lista3);
    free(lista4);
    free(lista5);
    LiberarLista(&lista1);
    LiberarLista(&lista2);

    return 0;
}
