#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Funciones/Funciones.h"
//valgrind --leak-check=full ./programa
#define TAM_MATRIZ 4 
#define SUB_TAM 2
#define NUCLEOS 4

void simularParalelismo() {
    srand(time(NULL));

    // Inicializar matrices grandes
    int* A = crearMatriz(TAM_MATRIZ, TAM_MATRIZ);
    int* B = crearMatriz(TAM_MATRIZ, TAM_MATRIZ);
    inicializarMatriz(A, TAM_MATRIZ, TAM_MATRIZ);
    inicializarMatriz(B, TAM_MATRIZ, TAM_MATRIZ);

    // Crear pila
    Pila pila;
    inicializarPila(&pila);

    // Subdividir matrices y realizar operaciones
    for (int i = 0; i < NUCLEOS / 2; i++) {
        for (int j = 0; j < NUCLEOS / 2; j++) {
            int* A_sub = crearMatriz(SUB_TAM, SUB_TAM);
            int* B_sub = crearMatriz(SUB_TAM, SUB_TAM);
            for (int x = 0; x < SUB_TAM; x++) {
                for (int y = 0; y < SUB_TAM; y++) {
                    A_sub[x * SUB_TAM + y] = A[(i * SUB_TAM + x) * TAM_MATRIZ + (j * SUB_TAM + y)];
                    B_sub[x * SUB_TAM + y] = B[(i * SUB_TAM + x) * TAM_MATRIZ + (j * SUB_TAM + y)];
                }
            }
            int* C_sub = prodSum(A_sub, B_sub, SUB_TAM, SUB_TAM);
            Push(&pila, C_sub);
            liberarMatriz(A_sub);
            liberarMatriz(B_sub);
        }
    }

    // Formar matriz final
    int* C = crearMatriz(TAM_MATRIZ, TAM_MATRIZ);
    for (int i = 0; i < NUCLEOS / 2; i++) {
        for (int j = 0; j < NUCLEOS / 2; j++) {
            int* C_sub = Pop(&pila);
            for (int x = 0; x < SUB_TAM; x++) {
                for (int y = 0; y < SUB_TAM; y++) {
                    C[(i * SUB_TAM + x) * TAM_MATRIZ + (j * SUB_TAM + y)] = C_sub[x * SUB_TAM + y];
                }
            }
            liberarMatriz(C_sub);
        }
    }

    // Imprimir matrices iniciales y la matriz resultante (para matrices pequeñas)
    printf("Matriz A:\n");
    imprimirMatriz(A, TAM_MATRIZ, TAM_MATRIZ);

    printf("Matriz B:\n");
    imprimirMatriz(B, TAM_MATRIZ, TAM_MATRIZ);

    printf("Matriz C (Resultado):\n");
    imprimirMatriz(C, TAM_MATRIZ, TAM_MATRIZ);

    // Liberar memoria
    liberarMatriz(A);
    liberarMatriz(B);
    liberarMatriz(C);
    liberarPila(&pila);
}

int main() {
    simularParalelismo();
    return 0;
}
