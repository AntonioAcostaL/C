#include "Funciones.h"
//valgrind --leak-check=full ./lab3
void InicializarLista(ListaDobleCircular* lista) {
    lista->head = NULL;
}

void InsertarFinal(ListaDobleCircular* lista, char dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    if (lista->head == NULL) {
        lista->head = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
    } else {
        Nodo* tail = lista->head->anterior;
        tail->siguiente = nuevoNodo;
        nuevoNodo->anterior = tail;
        nuevoNodo->siguiente = lista->head;
        lista->head->anterior = nuevoNodo;
    }
}

ListaDobleCircular* ConcatInicio(ListaDobleCircular* lista1, ListaDobleCircular* lista2) {
    ListaDobleCircular* lista3 = (ListaDobleCircular*)malloc(sizeof(ListaDobleCircular));
    InicializarLista(lista3);

    // Copiar lista1 en lista3
    Nodo* actual = lista1->head;
    do {
        InsertarFinal(lista3, actual->dato);
        actual = actual->siguiente;
    } while (actual != lista1->head);

    // Copiar lista2 en lista3 al inicio
    actual = lista2->head;
    do {
        InsertarFinal(lista3, actual->dato);
        actual = actual->siguiente;
    } while (actual != lista2->head);

    return lista3;
}

ListaDobleCircular* ConcatFinal(ListaDobleCircular* lista1, ListaDobleCircular* lista2) {
    ListaDobleCircular* lista4 = (ListaDobleCircular*)malloc(sizeof(ListaDobleCircular));
    InicializarLista(lista4);

    // Copiar lista2 en lista4
    Nodo* actual = lista2->head;
    do {
        InsertarFinal(lista4, actual->dato);
        actual = actual->siguiente;
    } while (actual != lista2->head);

    // Copiar lista1 en lista4 al final
    actual = lista1->head;
    do {
        InsertarFinal(lista4, actual->dato);
        actual = actual->siguiente;
    } while (actual != lista1->head);

    return lista4;
}

ListaDobleCircular* ConcatPos(ListaDobleCircular* lista1, ListaDobleCircular* lista2, int pos) {
    ListaDobleCircular* lista5 = (ListaDobleCircular*)malloc(sizeof(ListaDobleCircular));
    InicializarLista(lista5);

    // Copiar lista1 hasta la posición pos en lista5
    Nodo* actual = lista1->head;
    for (int i = 0; i < pos && actual != lista1->head; ++i) {
        InsertarFinal(lista5, actual->dato);
        actual = actual->siguiente;
    }

    // Copiar lista2 en lista5 en la posición pos
    Nodo* actual2 = lista2->head;
    do {
        InsertarFinal(lista5, actual2->dato);
        actual2 = actual2->siguiente;
    } while (actual2 != lista2->head);

    // Continuar copiando lista1 después de la posición pos en lista5
    while (actual != lista1->head) {
        InsertarFinal(lista5, actual->dato);
        actual = actual->siguiente;
    }

    return lista5;
}

void MostrarLista(ListaDobleCircular* lista) {
    if (lista->head == NULL) return;
    Nodo* actual = lista->head;
    do {
        printf("%c <-> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != lista->head);
    printf("head\n");
}

void LiberarLista(ListaDobleCircular* lista) {
    if (lista->head == NULL) return;
    Nodo* actual = lista->head;
    do {
        Nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    } while (actual != lista->head);
    lista->head = NULL;
}


