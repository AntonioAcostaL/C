#include "Funciones.h"

#include <stdio.h>

// Implementación de la función hash1 usando folding
int hashFuncion1(void* llave) {
    char* str = (char*)llave;
    int hash = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        hash = (hash << 5) + hash + str[i]; // hash * 33 + str[i]
    }

    return hash;
}

// Implementación de la función hash2 para doble hashing
int hashFuncion2(void* llave) {
    char* str = (char*)llave;
    int hash = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        hash = (hash << 5) + hash + str[i]; // hash * 33 + str[i]
    }

    return (hash | 1); // Asegurarse de que sea impar
}

TablaHash* crearTablaHash(int capacidad, FuncionHash hash1, FuncionHash hash2, const char* tipo_colision) {
    TablaHash* tabla = (TablaHash*)malloc(sizeof(TablaHash));
    tabla->hash1 = hash1;
    tabla->hash2 = hash2;
    tabla->capacidad = capacidad;
    tabla->size = 0;
    strcpy(tabla->tipo_colision, tipo_colision);
    tabla->slots = (Tupla**)calloc(capacidad, sizeof(Tupla*));
    return tabla;
}

void insertar(TablaHash* tabla, void* llave, void* dato) {
    int indice1 = tabla->hash1(llave) % tabla->capacidad;
    int indice2 = tabla->hash2(llave) % tabla->capacidad;
    int i = 0;

    while (tabla->slots[indice1] != NULL && i < tabla->capacidad) {
        if (strcmp(tabla->tipo_colision, "chain") == 0) {
            // Implementa encadenamiento aquí (no se usa indice2)
        } else if (strcmp(tabla->tipo_colision, "double") == 0) {
            indice1 = (indice1 + i * indice2) % tabla->capacidad;
        }
        i++;
    }

    if (i < tabla->capacidad) {
        Tupla* tupla = (Tupla*)malloc(sizeof(Tupla));
        tupla->llave = llave;
        tupla->dato = dato;
        tabla->slots[indice1] = tupla;
        tabla->size++;
    }
}

void* buscar(TablaHash* tabla, void* llave) {
    int indice1 = tabla->hash1(llave) % tabla->capacidad;
    int indice2 = tabla->hash2(llave) % tabla->capacidad;
    int i = 0;

    while (tabla->slots[indice1] != NULL && i < tabla->capacidad) {
        if (strcmp(tabla->tipo_colision, "chain") == 0) {
            // Implementa la búsqueda con encadenamiento aquí (no se usa indice2)
        } else if (strcmp(tabla->tipo_colision, "double") == 0) {
            if (strcmp(tabla->slots[indice1]->llave, llave) == 0) {
                return tabla->slots[indice1]->dato;
            }
            indice1 = (indice1 + i * indice2) % tabla->capacidad;
        }
        i++;
    }

    return NULL;
}

void eliminar(TablaHash* tabla, void* llave) {
    int indice1 = tabla->hash1(llave) % tabla->capacidad;
    int indice2 = tabla->hash2(llave) % tabla->capacidad;
    int i = 0;

    while (tabla->slots[indice1] != NULL && i < tabla->capacidad) {
        if (strcmp(tabla->tipo_colision, "chain") == 0) {
            // Implementa la eliminación con encadenamiento aquí (no se usa indice2)
        } else if (strcmp(tabla->tipo_colision, "double") == 0) {
            if (strcmp(tabla->slots[indice1]->llave, llave) == 0) {
                free(tabla->slots[indice1]);
                tabla->slots[indice1] = NULL;
                tabla->size--;
                return;
            }
            indice1 = (indice1 + i * indice2) % tabla->capacidad;
        }
        i++;
    }
}

void imprimirTabla(TablaHash* tabla) {
    for (int i = 0; i < tabla->capacidad; i++) {
        if (tabla->slots[i] != NULL) {
            printf("Slot %d: Llave = %s, Dato = %s\n", i, (char*)tabla->slots[i]->llave, (char*)tabla->slots[i]->dato);
        } else {
            printf("Slot %d: Vacío\n", i);
        }
    }
}
