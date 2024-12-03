
#include <stdlib.h>
#include <string.h>

// Definición de la función hash
typedef int (*FuncionHash)(void* llave);

// Estructura para la tupla de la tabla hash
typedef struct Tupla {
    void* llave;
    void* dato;
} Tupla;

// Estructura para la tabla hash
typedef struct TablaHash {
    FuncionHash hash1;
    FuncionHash hash2;
    Tupla** slots;
    int size;
    int capacidad;
    char tipo_colision[15];
} TablaHash;

// Prototipos de funciones
TablaHash* crearTablaHash(int capacidad, FuncionHash hash1, FuncionHash hash2, const char* tipo_colision);
void insertar(TablaHash* tabla, void* llave, void* dato);
void* buscar(TablaHash* tabla, void* llave);
void eliminar(TablaHash* tabla, void* llave);
void imprimirTabla(TablaHash* tabla);

// Declaraciones de las funciones hash
int hashFuncion1(void* llave);
int hashFuncion2(void* llave);

