#include "Funciones.h"

void InicializarLista(ListaDoble* lista) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}

void InsertarAleatorio(ListaDoble* lista, Blog* dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = NULL;

    int tipoInsercion = rand() % 3;
    if (tipoInsercion == 0) { // Insertar al frente
        if (lista->head == NULL) {
            lista->head = nuevoNodo;
            lista->tail = nuevoNodo;
        } else {
            nuevoNodo->siguiente = lista->head;
            lista->head->anterior = nuevoNodo;
            lista->head = nuevoNodo;
        }
    } else if (tipoInsercion == 1) { // Insertar al final
        if (lista->tail == NULL) {
            lista->head = nuevoNodo;
            lista->tail = nuevoNodo;
        } else {
            nuevoNodo->anterior = lista->tail;
            lista->tail->siguiente = nuevoNodo;
            lista->tail = nuevoNodo;
        }
    } else { // Insertar en una posición aleatoria
        if (lista->size == 0) {
            lista->head = nuevoNodo;
            lista->tail = nuevoNodo;
        } else {
            int pos = rand() % (lista->size + 1);
            if (pos == 0) {
                nuevoNodo->siguiente = lista->head;
                lista->head->anterior = nuevoNodo;
                lista->head = nuevoNodo;
            } else if (pos == lista->size) {
                nuevoNodo->anterior = lista->tail;
                lista->tail->siguiente = nuevoNodo;
                lista->tail = nuevoNodo;
            } else {
                Nodo* actual = lista->head;
                for (int i = 0; i < pos - 1; ++i) {
                    actual = actual->siguiente;
                }
                nuevoNodo->siguiente = actual->siguiente;
                nuevoNodo->anterior = actual;
                actual->siguiente->anterior = nuevoNodo;
                actual->siguiente = nuevoNodo;
            }
        }
    }
    lista->size++;
}

void MostrarLista(ListaDoble* lista) {
    Nodo* actual = lista->head;
    while (actual != NULL) {
        printf("Usuario: %s, Comentario: %s\n", actual->dato->usuario, actual->dato->comentario);
        actual = actual->siguiente;
    }
}

void MostrarListaReversa(ListaDoble* lista) {
    Nodo* actual = lista->tail;
    while (actual != NULL) {
        printf("Usuario: %s, Comentario: %s\n", actual->dato->usuario, actual->dato->comentario);
        actual = actual->anterior;
    }
}

void OrdenarPorComentario(ListaDoble* lista) {
    if (lista->size < 2) return;

    for (Nodo* i = lista->head; i != NULL; i = i->siguiente) {
        for (Nodo* j = i->siguiente; j != NULL; j = j->siguiente) {
            if (strlen(i->dato->comentario) > strlen(j->dato->comentario)) {
                Blog* temp = i->dato;
                i->dato = j->dato;
                j->dato = temp;
            }
        }
    }
}

void FiltrarPorLongitud(ListaDoble* lista, int longitud) {
    Nodo* actual = lista->head;
    ListaDoble nuevaLista;
    InicializarLista(&nuevaLista);

    while (actual != NULL) {
        if (strlen(actual->dato->comentario) <= longitud) {
            Blog* datoCopia = (Blog*)malloc(sizeof(Blog));
            strcpy(datoCopia->usuario, actual->dato->usuario);
            strcpy(datoCopia->comentario, actual->dato->comentario);
            InsertarAleatorio(&nuevaLista, datoCopia);
        }
        actual = actual->siguiente;
    }

    MostrarLista(&nuevaLista);
    LiberarLista(&nuevaLista);
}

void EliminarPorUsuario(ListaDoble* lista, int longitud) {
    Nodo* actual = lista->head;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        if (strlen(actual->dato->usuario) > longitud) {
            if (actual->anterior != NULL) {
                actual->anterior->siguiente = actual->siguiente;
            } else {
                lista->head = actual->siguiente;
            }
            if (actual->siguiente != NULL) {
                actual->siguiente->anterior = actual->anterior;
            } else {
                lista->tail = actual->anterior;
            }
            free(actual->dato);
            free(actual);
            lista->size--;
        }
        actual = siguiente;
    }
}

void LiberarLista(ListaDoble* lista) {
    Nodo* actual = lista->head;
    Nodo* siguiente;

    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual->dato);
        free(actual);
        actual = siguiente;
    }

    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}
