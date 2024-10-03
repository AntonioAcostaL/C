#pragma once

typedef struct Nodo
{
    void *data;
    struct Nodo *next;
    struct Nodo *prev;
}Nodo;

typedef struct Lista
{
    Nodo *head;
    Nodo *tail;
    int size;
}Lista;

