#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones/Funciones.h"

void imprimirPalabra(char* palabra) {
    printf("%s ", palabra);
}

void cargarArchivoEnArbol(ArbolBinario* arbol, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), archivo)) {
        // Eliminar el salto de línea del final de la palabra
        buffer[strcspn(buffer, "\n")] = '\0';
        char* palabra = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(palabra, buffer);
        agregarArbol(arbol, palabra);
    }

    fclose(archivo);
}

int main() {
    ArbolBinario arbol;
    inicializarArbol(&arbol);

    cargarArchivoEnArbol(&arbol, "palabras.txt");

    char entrada[4];
    while (1) {
        printf("Escribe hasta 3 letras (o 'exit' para salir): ");
        scanf("%3s", entrada);
        if (strcmp(entrada, "exit") == 0) break;

        printf("Recomendación por prefijo: ");
        buscarPorPrefijo(arbol.raiz, entrada, imprimirPalabra);
        printf("\n");

        printf("Recomendación por subcadena: ");
        buscarPorSubcadena(arbol.raiz, entrada, imprimirPalabra);
        printf("\n");
    }

    return 0;
}
