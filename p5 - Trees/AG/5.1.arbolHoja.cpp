#include "auxiliares.h"
#include <iostream>

/**
 * Devuelve un árbol que sólo contiene una hoja
*/

AG arbolHoja(int x){
    AG arbol = new nodoAG;
    arbol -> dato = x;
    arbol -> pH = NULL;
    arbol -> sH = NULL;
    return arbol;
}


int main() {
    // Crear un árbol hoja
    AG arbol = arbolHoja(10);

    // imprimo el árbo
    imprimirPreorden(arbol);

    // Liberar la memoria del árbol
    liberarArbol(arbol);

    return 0;
}

// g++ 5.1.arbolHoja.cpp auxiliares.cpp -o arbolHoja