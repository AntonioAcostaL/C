#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    char dato;
    struct Nodo *siguiente;
};

typedef struct _ListaSimple
{
    struct Nodo *head;
    struct Nodo *tail;
    struct Nodo *curr;
    int size;
}ListaSimple;

void InicializarLista(ListaSimple* lista);
void LiberarLista(ListaSimple* lista);
void PushFront(ListaSimple* lista, char dato);
void PushBack(ListaSimple* lista, char dato);
void PushPos(ListaSimple* lista, int pos, char dato);
int BorrarPos(ListaSimple* lista, int pos);
void ImprimirLista(ListaSimple* lista);

