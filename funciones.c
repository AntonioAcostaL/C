#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void IniciarListaDoble(Lista *lista)
{
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}

struct Nodo* nuevoNodo(int data) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->data = data;
    nodo->next = NULL;
    return nodo;
}

void AddHead(Lista *lista, void *dato)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->data = dato;

    if (lista->tail == NULL)
    {
        lista->tail = nuevo;
        nuevo->next = NULL;
        nuevo->prev = NULL;
    }
    else
    {
        nuevo->next = lista->head;
        nuevo->prev = NULL;
    }
    lista->head = nuevo;
    lista->size++;
}

void AddPos(Lista *lista, void *dato, int pos) {
    if (pos == 0)
        AddHead(lista, dato);
    else if (pos == lista->size)
        AddTail(lista, dato);
    else
    {
        Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
        nuevo->data = dato;

        Nodo *ant = GetNodoPos(lista, pos - 1);
        if (ant != NULL) {
            nuevo->next = ant->next;
            nuevo->prev = ant;
            if (ant->next != NULL) {
                ant->next->prev = nuevo;
            }
            ant->next = nuevo;
            lista->size++;
        }
        else {
            free(nuevo);
        }
    }
}

