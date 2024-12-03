#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente {
    int ticks;
    struct Cliente* siguiente;
} Cliente;

typedef struct {
    Cliente* frente;
    Cliente* final;
    int size;
    int max_size;
} Cola;


Cliente* crearCliente(int ticks);
void inicializarCola(Cola* cola, int max_size);
void PushQueue(Cola* cola, int ticks);
int PopQueue(Cola* cola);
int PeekQueue(Cola* cola);
int EstaLlena(Cola* cola);
int EstaVacia(Cola* cola);
void VaciarCola(Cola* cola);
void PrintQueue(Cola* cola);
void liberarCola(Cola* cola);


