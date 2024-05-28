#include "auxiliares.h"

/**
 * el máximo de un ABB es el que está más a la derecha
*/


// retorna un árbol
ABB maxABB(ABB t) {
    if (t == NULL) {
        return NULL;
    } else {
        // Recorre hacia la derecha hasta encontrar el nodo más a la derecha
        while (t->der != NULL) {
            t = t->der;
            printf("%d ", t -> elem);
        }
        return t;
    }
}


// retorna el valor del máximo
uint maxABB2(ABB t) {
    if (t == NULL) {
        return -1;
    } else {
        // Recorre hacia la derecha hasta encontrar el nodo más a la derecha
        while (t->der != NULL) {
            t = t->der;
        }
        return t -> elem;
    }
}




int main() {
    ABB arbol = NULL;

    // Insertar algunos elementos en el árbol.


    insertABB(40, arbol);
    insertABB(20, arbol);
    insertABB(60, arbol);
    insertABB(50, arbol);
    insertABB(70, arbol);
    insertABB(15, arbol);
    insertABB(93, arbol);
    insertABB(80, arbol);





    // Imprimir los elementos del árbol en orden.
    printf("Elementos del árbol en orden: ");
    imprimirEnOrden(arbol);


    // máximo (árbol)
    printf("\n Máximo: ");
    ABB max = maxABB(arbol);
    imprimirEnOrden(max); // imprime 80 93


    // valor del máximo
    printf("\n Valor del Máximo: ");
    uint max2 = maxABB2(arbol);
    printf("%d", max2);

    

    // libero memoria
    liberarMemoria(arbol);





    return 0;
}

// g++ 3.3.maxABB.cpp auxiliares.cpp -o maxABB
