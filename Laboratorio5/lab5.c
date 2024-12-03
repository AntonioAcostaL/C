#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Funciones/Funciones.h"

#define MAX_CLIENTES_CAJA 3
#define MAX_CLIENTES_FILA_PRINCIPAL 25
#define MAX_TICKS 100000
#define INTERVALO_NUEVO_CLIENTE 100

void simularSupermercado() {
    srand(time(NULL));

    Cola filaPrincipal;
    inicializarCola(&filaPrincipal, MAX_CLIENTES_FILA_PRINCIPAL);

    Cola pasilloEmergencia;
    inicializarCola(&pasilloEmergencia, MAX_CLIENTES_FILA_PRINCIPAL);

    Cola caja1;
    inicializarCola(&caja1, MAX_CLIENTES_CAJA);

    Cola caja2;
    inicializarCola(&caja2, MAX_CLIENTES_CAJA);

    Cola caja3;
    inicializarCola(&caja3, MAX_CLIENTES_CAJA);

    int ticks = 0;
    int siguienteNuevoCliente = INTERVALO_NUEVO_CLIENTE;

    while (ticks < MAX_TICKS || !EstaVacia(&filaPrincipal) || !EstaVacia(&caja1) || !EstaVacia(&caja2) || !EstaVacia(&caja3)) {
        // Agregar nuevos clientes a la fila principal cada 100 ticks
        if (ticks < MAX_TICKS && ticks >= siguienteNuevoCliente) {
            if (!EstaLlena(&filaPrincipal)) {
                PushQueue(&filaPrincipal, rand() % 100 + 1);
            } else if (!EstaLlena(&pasilloEmergencia)) {
                PushQueue(&pasilloEmergencia, rand() % 100 + 1);
            }
            siguienteNuevoCliente += INTERVALO_NUEVO_CLIENTE;
        }

        // Mover clientes de la fila principal a las cajas si hay espacio
        if (!EstaVacia(&filaPrincipal)) {
            if (!EstaLlena(&caja1)) {
                PushQueue(&caja1, PopQueue(&filaPrincipal));
            } else if (!EstaLlena(&caja2)) {
                PushQueue(&caja2, PopQueue(&filaPrincipal));
            } else if (!EstaLlena(&caja3)) {
                PushQueue(&caja3, PopQueue(&filaPrincipal));
            }
        }

        // Procesar clientes en las cajas
        if (!EstaVacia(&caja1)) {
            int ticksCliente = PopQueue(&caja1);
            ticksCliente--;
            if (ticksCliente > 0) {
                PushQueue(&caja1, ticksCliente);
            }
        }
        if (!EstaVacia(&caja2)) {
            int ticksCliente = PopQueue(&caja2);
            ticksCliente--;
            if (ticksCliente > 0) {
                PushQueue(&caja2, ticksCliente);
            }
        }
        if (!EstaVacia(&caja3)) {
            int ticksCliente = PopQueue(&caja3);
            ticksCliente--;
            if (ticksCliente > 0) {
                PushQueue(&caja3, ticksCliente);
            }
        }

        ticks++;
    }

    liberarCola(&filaPrincipal);
    liberarCola(&pasilloEmergencia);
    liberarCola(&caja1);
    liberarCola(&caja2);
    liberarCola(&caja3);
}

int main() {
    simularSupermercado();
    return 0;
}
