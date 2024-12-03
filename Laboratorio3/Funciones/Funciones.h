#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    char dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

typedef struct {
    Nodo* head;
} ListaDobleCircular;

void InicializarLista(ListaDobleCircular* lista);
void InsertarFinal(ListaDobleCircular* lista, char dato);
ListaDobleCircular* ConcatInicio(ListaDobleCircular* lista1, ListaDobleCircular* lista2);
ListaDobleCircular* ConcatFinal(ListaDobleCircular* lista1, ListaDobleCircular* lista2);
ListaDobleCircular* ConcatPos(ListaDobleCircular* lista1, ListaDobleCircular* lista2, int pos);
void MostrarLista(ListaDobleCircular* lista);
void LiberarLista(ListaDobleCircular* lista);
