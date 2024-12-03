#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"

void InicializarLista(ListaSimple* lista)
{
    lista->head = NULL;
    lista->tail = NULL;
    lista->curr = NULL;
    lista->size = 0;
}

void LiberarLista(ListaSimple* lista) {
    struct Nodo* actual = lista->head;
    struct Nodo* siguienteNodo;
    
    while (actual != NULL) {
        siguienteNodo = actual->siguiente; // Guarda el siguiente nodo
        free(actual); // Libera el nodo actual
        actual = siguienteNodo; // Avanza al siguiente nodo
    }
    
    // Opcional: Restablece los punteros de la lista y el tamaño
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}


void PushFront(ListaSimple* lista, char dato)
{
    struct Nodo* newNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    newNodo->dato=dato;
    if (lista->head == NULL)
    {
        lista->tail = newNodo;
        newNodo->siguiente = NULL;
    }
    else {
        newNodo->siguiente = lista->head;
    }
    lista->head = newNodo;
    lista->size++;
}

void PushBack(ListaSimple* lista, char dato)
{
    struct Nodo* newNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    newNodo->dato = dato;
    newNodo->siguiente = NULL;
    if (lista->tail == NULL)
    {
        lista->head = newNodo;
    }
    else{
        lista->tail->siguiente = newNodo;
    }
    lista->tail = newNodo;
    lista->size++;
}

void PushPos(ListaSimple* lista, int pos, char dato)
{
    if (pos<0||pos>lista->size) return;
    if (pos == 0)   
    {
        PushFront(lista,dato);
        return;
    }
    if (pos == lista->size)
    {
        PushBack(lista, dato);
        return;
    }
    struct Nodo* newNodo=(struct Nodo*)malloc(sizeof(struct Nodo));
    newNodo->dato = dato;
    struct Nodo* actual = lista->head;
    for (int i = 1; i < pos; i++)
    {
        actual = actual->siguiente;
    }
    newNodo->siguiente = actual->siguiente;
    actual->siguiente = newNodo;
    lista->size++;
}

int BorrarPos(ListaSimple* lista, int pos)
{
    if (pos<0||pos>lista->size)return -1;
    struct Nodo* temp;
    if (pos==0)
    {
        temp=lista->head->siguiente;
        free(lista->head);
        lista->head = temp;
        if (lista->size == 1)
        {
            lista->tail=NULL;
        }
        lista->size--;
        return 1;
    }
    struct Nodo* actual = lista->head;
    for (int i = 1; i < pos; i++)
    {
        actual=actual->siguiente;
    }
    struct Nodo* borrar = actual->siguiente;
    actual->siguiente = borrar->siguiente;
    if (pos==lista->size-1)
    {
        lista->tail=actual;
    }
    free(borrar);
    lista->size--;
    return 1;
}

void ImprimirLista(ListaSimple* lista)
{
    lista->curr=lista->head;
    while (lista->curr!=NULL)   
    {
        printf("%c ->",lista->curr->dato);
        lista->curr=lista->curr->siguiente;
    }
    printf("NULL\n");
}