#include "auxiliares.h"
#include <iostream>

/**
 * Dice si el árbol es sólo una hoja
*/

bool esArbolHoja(AG t){
    // que no sea vacío y que no tenga hijos
    return (  (t != NULL) && ( t -> pH == NULL) );
}

// observe que no hace falta chequear los hermanos


// main para chequear
int main() {
    // Crear un árbol hoja
    AG arbol = arbolHoja(10);
    bool esHoja = esArbolHoja(arbol);
    printf("El valor booleano es: %s\n", esHoja ? "true" : "false");

    // no es
    AG arbol2 = nuevoNodo(1);
    insertarHijo(arbol2, 2);
    insertarHijo(arbol2, 3);
    bool esHoja2 = esArbolHoja(arbol2);
    printf("El valor booleano es: %s\n", esHoja2 ? "true" : "false");



    // Liberar la memoria del árbol
    liberarArbol(arbol);
    liberarArbol(arbol2);

    return 0;
}

// g++ 5.2.esArbolHoja.cpp auxiliares.cpp -o esArbolHoja