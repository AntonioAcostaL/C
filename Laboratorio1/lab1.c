#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Funciones/Funciones.h"

void GenerarAlumnoAleatorio(Alumno* alumno) {
    const char* nombres[] = {"Juan", "Maria", "Luis", "Ana", "Carlos", "Lucia"};
    const char* apellidos[] = {"Garcia", "Martinez", "Lopez", "Sanchez", "Gomez", "Diaz"};

    strcpy(alumno->nombre, nombres[rand() % 6]);
    strcpy(alumno->apellidos, apellidos[rand() % 6]);
    alumno->semestre = rand() % 10 + 1;
}

int main() {
    ListaSimple lista;
    InicializarLista(&lista);

    srand(time(NULL));


    int numAltas = rand() % 36 + 5; 
    printf("Registrando %d alumnos...\n", numAltas);
    for (int i = 0; i < numAltas; i++) {
        Alumno* nuevoAlumno = (Alumno*)malloc(sizeof(Alumno));
        GenerarAlumnoAleatorio(nuevoAlumno);
        PushBack(&lista, nuevoAlumno);
    }

    MostrarLista(&lista);


    int maxBajas = numAltas - 5;          // Máximo número de bajas permitidas
    int numBajas = rand() % 13 + 3;       // Número de bajas entre 3 y 15

    if (numBajas > maxBajas) { 
        numBajas = maxBajas;             // Ajustar número de bajas si excede el máximo permitido
    }

    printf("Dando de baja a %d alumnos...\n", numBajas);

    for (int i = 0; i < numBajas && lista.size > 5; i++) { 
        int posBaja = rand() % lista.size; 
        BorrarPos(&lista, posBaja); 
    }

    printf("Lista despues de las bajas:\n");
    MostrarLista(&lista);

    // Liberar la lista
    LiberarLista(&lista);

    return 0;
}
