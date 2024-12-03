#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


Cliente* crearCliente(int ticks) {
    Cliente* cliente = (Cliente*)malloc(sizeof(Cliente));
    cliente->ticks = ticks;
    cliente->siguiente = NULL;
    return cliente;
}


void inicializarCola(Cola* cola, int max_size) {
    cola->frente = NULL;
    cola->final = NULL;
    cola->size = 0;
    cola->max_size = max_size;
}


void PushQueue(Cola* cola, int ticks) {
    if (EstaLlena(cola)) {
        printf("Error: La cola está llena\n");
        return;
    }
    Cliente* nuevoCliente = crearCliente(ticks);
    if (cola->final == NULL) {
        cola->frente = nuevoCliente;
    } else {
        cola->final->siguiente = nuevoCliente;
    }
    cola->final = nuevoCliente;
    cola->size += 1;
}

int PopQueue(Cola* cola) {
    if (EstaVacia(cola)) {
        fprintf(stderr, "Error: La cola está vacía\n");
        exit(EXIT_FAILURE);
    }

    Cliente* clienteAEliminar = cola->frente;
    int ticks = clienteAEliminar->ticks;
    cola->frente = cola->frente->siguiente;
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    free(clienteAEliminar);
    cola->size -= 1;

    return ticks;
}

int PeekQueue(Cola* cola) {
    if (cola->frente == NULL) {
        fprintf(stderr, "Error: La cola está vacía\n");
        exit(EXIT_FAILURE);
    }
    return cola->frente->ticks;
}

// Funcin para verificar si la cola está llena
int EstaLlena(Cola* cola) {
    return cola->size >= cola->max_size;
}

// Funcion para verificar si esta vacia
int EstaVacia(Cola* cola) {
    return cola->size == 0;
}

// vaciar la cola
void VaciarCola(Cola* cola) {
    while (!EstaVacia(cola)) {
        PopQueue(cola);
    }
}


void PrintQueue(Cola* cola) {
    Cola aux;
    inicializarCola(&aux, cola->max_size);
    int temp;

    while (cola->size != 0) {
        temp = PopQueue(cola);
        printf("%d -> ", temp);
        PushQueue(&aux, temp);
    }
    printf("NULL\n");

    while (aux.size != 0) {
        temp = PopQueue(&aux);
        PushQueue(cola, temp);
    }
}


void liberarCola(Cola* cola) {
    VaciarCola(cola);
}
