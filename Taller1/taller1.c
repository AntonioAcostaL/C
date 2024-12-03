#include <stdio.h>
#include "ListaSimple/ListaSimple.h"
//gcc -Wall -Werror -std=c99 -pedantic -o taller1 Taller1/ListaSimple/ListaSimple.c Taller1/taller1.c
int main()
{
    ListaSimple lista;
    InicializarLista(&lista);

    PushFront(&lista, 'U');
    PushFront(&lista, 'A');
    PushBack(&lista, 'B');
    PushBack(&lista, 'C');
    PushFront(&lista, 'I');
    PushPos(&lista, 5, 'S');
    PushPos(&lista, 0, 'T');
    PushPos(&lista, 3, 'E');

    printf("Lista final:\n");
    ImprimirLista(&lista);

    printf("Cabeza de la lista: %c\n",lista.head ? lista.head->dato: 'N');
    printf("Cola de la lista: %c\n", lista.tail ? lista.tail->dato : 'N');

    LiberarLista(&lista);

    return 0;
}