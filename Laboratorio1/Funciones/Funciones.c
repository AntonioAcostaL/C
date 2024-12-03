#include "Funciones.h"

void InicializarLista(ListaSimple* lista) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    lista->size = 0;
}

void PushFront(ListaSimple* lista, Alumno* dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = lista->head;
    lista->head = nuevoNodo;
    if (lista->size == 0) {
        lista->tail = nuevoNodo;
    }
    lista->size++;
}

void PushBack(ListaSimple* lista, Alumno* dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    if (lista->size == 0) {
        lista->head = nuevoNodo;
        lista->tail = nuevoNodo;
    } else {
        lista->tail->siguiente = nuevoNodo;
        lista->tail = nuevoNodo;
    }
    lista->size++;
}

void PushPos(ListaSimple* lista, int pos, Alumno* dato) {
    if (pos < 0 || pos > lista->size) return;
    if (pos == 0) {
        PushFront(lista, dato);
        return;
    }
    if (pos == lista->size) {
        PushBack(lista, dato);
        return;
    }
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    Nodo* actual = lista->head;
    for (int i = 1; i < pos; ++i) {
        actual = actual->siguiente;
    }
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
    lista->size++;
}

int BorrarPos(ListaSimple* lista, int pos) {
    if (pos < 0 || pos >= lista->size) return -1;
    Nodo* temporal;
    if (pos == 0) {
        temporal = lista->head->siguiente;
        free(lista->head->dato);
        free(lista->head);
        lista->head = temporal;
        if (lista->size == 1) {
            lista->tail = NULL;
        }
        lista->size--;
        return 1;
    }
    Nodo* actual = lista->head;
    for (int i = 1; i < pos; ++i) {
        actual = actual->siguiente;
    }
    Nodo* borrar = actual->siguiente;
    actual->siguiente = borrar->siguiente;
    if (pos == lista->size - 1) {
        lista->tail = actual;
    }
    free(borrar->dato);
    free(borrar);
    lista->size--;
    return 1;
}

void MostrarLista(ListaSimple* lista) {
    lista->current = lista->head;
    while (lista->current != NULL) {
        printf("Nombre: %s,\n Apellidos: %s,\n Semestre: %d\n ->\n ", 
               lista->current->dato->nombre, 
               lista->current->dato->apellidos, 
               lista->current->dato->semestre);
        lista->current = lista->current->siguiente;
    }
    printf("NULL\n");
}

void LiberarLista(ListaSimple* lista) {
    Nodo* actual = lista->head;
    Nodo* siguienteNodo;

    while (actual != NULL) {
        siguienteNodo = actual->siguiente;
        free(actual->dato);
        free(actual);
        actual = siguienteNodo;
    }

    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}
