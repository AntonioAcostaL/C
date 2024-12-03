
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alumno {
    char nombre[50];
    char apellidos[50];
    int semestre;
} Alumno;

typedef struct Nodo {
    Alumno* dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* head;
    Nodo* tail;
    Nodo* current;
    int size;
} ListaSimple;

void InicializarLista(ListaSimple* lista);
void PushFront(ListaSimple* lista, Alumno* dato);
void PushBack(ListaSimple* lista, Alumno* dato);
void PushPos(ListaSimple* lista, int pos, Alumno* dato);
int BorrarPos(ListaSimple* lista, int pos);
void MostrarLista(ListaSimple* lista);
void LiberarLista(ListaSimple* lista);


