#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones/Funciones.h"

typedef struct Paquete {
    char destinatario[50];
    char remitente[50];
    char direccion_destino[100];
    char direccion_origen[100];
    float peso;
    struct {
        float ancho;
        float alto;
        float profundidad;
    } dimensiones;
} Paquete;

void registrarPaquete(TablaHash* tabla) {
    Paquete* paquete = (Paquete*)malloc(sizeof(Paquete));
    printf("Ingrese el nombre del destinatario: ");
    scanf("%s", paquete->destinatario);
    printf("Ingrese el nombre del remitente: ");
    scanf("%s", paquete->remitente);
    printf("Ingrese la dirección destino: ");
    scanf("%s", paquete->direccion_destino);
    printf("Ingrese la dirección de origen: ");
    scanf("%s", paquete->direccion_origen);
    printf("Ingrese el peso del paquete: ");
    scanf("%f", &paquete->peso);
    printf("Ingrese las dimensiones (ancho, alto, profundidad): ");
    scanf("%f %f %f", &paquete->dimensiones.ancho, &paquete->dimensiones.alto, &paquete->dimensiones.profundidad);

    insertar(tabla, paquete->destinatario, paquete);
}

void buscarPaquetePorDestinatario(TablaHash* tabla) {
    char destinatario[50];
    printf("Ingrese el nombre del destinatario: ");
    scanf("%s", destinatario);

    Paquete* paquete = (Paquete*)buscar(tabla, destinatario);
    if (paquete != NULL) {
        printf("Paquete encontrado: %s\n", paquete->direccion_destino);
    } else {
        printf("Paquete no encontrado.\n");
    }
}

int main() {
    TablaHash* tabla = crearTablaHash(10, hashFuncion1, hashFuncion2, "double");

    int opcion;
    do {
        printf("\n1. Registrar paquete\n");
        printf("2. Buscar paquete por destinatario\n");
        printf("3. Imprimir tabla\n");
        printf("4. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarPaquete(tabla);
                break;
            case 2:
                buscarPaquetePorDestinatario(tabla);
                break;
            case 3:
                imprimirTabla(tabla);
                break;
            case 4:
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 4);

    return 0;
}
