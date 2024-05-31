#include "auxiliares.h"




int main() {
    // Crear la raíz del árbol
    AG arbol = nuevoNodo(1);

    // Insertar hijos de la raíz
    insertarHijo(arbol, 2);
    insertarHijo(arbol, 3);
    insertarHijo(arbol, 4);
    insertarHijo(arbol, 15);

    // Insertar hijos del primer hijo de la raíz
    insertarHijo(arbol->pH, 5);
    insertarHijo(arbol->pH, 6);

    // Insertar un hijo del segundo hijo de la raíz
    insertarHijo(arbol->pH->sH, 7);

    // Imprimir el árbol en preorden
    imprimirPreorden(arbol);


    liberarArbol(arbol);

    return 0;
}


// g++ auxiliares_test.cpp auxiliares.cpp -o auxiliares_test