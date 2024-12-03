#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Funciones/Funciones.h"

void GenerarBlogAleatorio(Blog* blog) {
    const char* usuarios[] = {"Juan", "Maria", "Luis", "Ana", "Carlos", "Lucia"};
    strcpy(blog->usuario, usuarios[rand() % 6]);

    int longitud = rand() % 255 + 1;
    for (int i = 0; i < longitud - 1; i++) {
        blog->comentario[i] = 'a' + rand() % 26; // Generar letra aleatoria
    }
    blog->comentario[longitud - 1] = '\0';
}

int main() {
    ListaDoble lista;
    InicializarLista(&lista);

    srand(time(NULL));

    // Generar 100 comentarios y agregarlos a la lista con inserciones aleatorias
    for (int i = 0; i < 100; i++) {
        Blog* nuevoBlog = (Blog*)malloc(sizeof(Blog));
        GenerarBlogAleatorio(nuevoBlog);
        InsertarAleatorio(&lista, nuevoBlog);
    }

    // Ordenar por cantidad de letras
    printf("Lista ordenada por cantidad de letras:\n");
    OrdenarPorComentario(&lista);
    MostrarLista(&lista);

    // Filtrar comentarios de 20 letras o menos
    printf("\nLista con comentarios de 20 letras o menos:\n");
    FiltrarPorLongitud(&lista, 20);

    // Eliminar comentarios de usuarios con nombre mayor a 3 letras
    EliminarPorUsuario(&lista, 3);
    
    // Mostrar lista original
    printf("\nLista original después de eliminar usuarios con nombre mayor a 3 letras:\n");
    MostrarLista(&lista);

    // Mostrar lista original en orden inverso
    printf("\nLista original en orden inverso:\n");
    MostrarListaReversa(&lista);

    // Liberar la lista
    LiberarLista(&lista);

    return 0;
}
