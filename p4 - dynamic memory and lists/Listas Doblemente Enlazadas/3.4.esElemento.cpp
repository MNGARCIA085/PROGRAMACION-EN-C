#include "auxiliar.h"

// insertar al inicio
bool esElemento(lista l, int elemento) {

    bool encontro = false;

    while ( (l != NULL) && (!encontro) ){
        if ( l-> elem == elemento){
            encontro = true;
        }

        l = l -> sig;
    }

    return encontro;

}


// main de prueba
int main() {
    lista l = NULL; // Inicialización de la lista como vacía

    // Inserción de algunos elementos
    insertarAlInicio(l, 10);
    insertarAlInicio(l, 20);
    insertarAlInicio(l, 30);
    insertarAlInicio(l, 40);

    // test
    bool ver1 = esElemento(l, 40);
    bool ver2 = esElemento(l, 20);
    bool ver3 = esElemento(l, 10);
    bool false1 = esElemento(l, 25);

    
    printf("El valor booleano es: %s\n", ver1 ? "verdadero" : "falso");
    printf("El valor booleano es: %s\n", ver2 ? "verdadero" : "falso");
    printf("El valor booleano es: %s\n", ver3 ? "verdadero" : "falso");
    printf("El valor booleano es: %s\n", false1 ? "verdadero" : "falso");
    


    // Liberar la memoria
    nodo_doble* temp;
    while (l != NULL) {
        temp = l;
        l = l->sig;
        delete temp;  // Usar delete en lugar de free para liberar la memoria en C++
    }

    return 0;
}


// g++ 3.4.esElemento.cpp auxiliar.cpp -o esElemento