
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _BLOG {
    char usuario[30];
    char comentario[255];
} Blog;

typedef struct Nodo {
    Blog* dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

typedef struct {
    Nodo* head;
    Nodo* tail;
    int size;
} ListaDoble;

void InicializarLista(ListaDoble* lista);
void InsertarAleatorio(ListaDoble* lista, Blog* dato);
void MostrarLista(ListaDoble* lista);
void MostrarListaReversa(ListaDoble* lista);
void OrdenarPorComentario(ListaDoble* lista);
void FiltrarPorLongitud(ListaDoble* lista, int longitud);
void EliminarPorUsuario(ListaDoble* lista, int longitud);
void LiberarLista(ListaDoble* lista);

