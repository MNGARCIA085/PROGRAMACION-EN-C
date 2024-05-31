#include "auxiliares.h"
#include <iostream>

/**
 * Dado un árbol t y un entero x devuelve True si x pertenece al árbol
*/

bool pertenece(AG t, int x){
    if ( t == NULL ){
        return false;
    }
    else if ( t -> dato == x){
        return true;
    }
    else {
        return ( pertenece(t->pH, x)  || pertenece (t->sH, x) );
    }
}


// main para chequear
int main() {

    // árbol de prueba
    AG arbol2 = nuevoNodo(1);
    insertarHijo(arbol2, 2);
    insertarHijo(arbol2, 3);
 

    // pertenecen
    bool pertenece1 = pertenece(arbol2, 3);
    printf("El valor booleano es: %s\n", pertenece1 ? "true" : "false");
    bool pertenece3 = pertenece(arbol2, 2);
    printf("El valor booleano es: %s\n", pertenece3 ? "true" : "false");


    // no pertenece
    bool pertenece2 = pertenece(arbol2, 7);
    printf("El valor booleano es: %s\n", pertenece2 ? "true" : "false");

    // Liberar la memoria del árbol
    liberarArbol(arbol2);

    return 0;
}

// g++ 5.3.pertenece.cpp auxiliares.cpp -o pertenece