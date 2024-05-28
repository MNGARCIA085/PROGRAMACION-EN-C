#include "auxiliares.h"

ABB removerMaxABB(ABB t) {
    if (t == NULL) {
        return NULL;
    } else if (t->der == NULL) {
        // Si t->der es NULL, entonces t es el nodo con el valor máximo
        ABB temp = t;
        t = t->izq; // Reemplazamos t por su subárbol izquierdo
        delete temp; // Liberamos la memoria del nodo original
        return t;
    } else {
        // Recorremos hacia la derecha hasta encontrar el nodo máximo
        // y lo eliminamos
        t->der = removerMaxABB(t->der);
        return t;
    }
}



int main() {
    ABB arbol = NULL;

    // Insertamos algunos elementos en el árbol
    insertABB(5, arbol);
    insertABB(3, arbol);
    insertABB(8, arbol);
    insertABB(1, arbol);
    insertABB(4, arbol);
    insertABB(7, arbol);


    imprimirEnOrden(arbol);
    printf("\n");


    // Encontramos el máximo y lo eliminamos
    ABB max = maximoABB(arbol);
    if (max != NULL) {
        printf("El valor máximo en el árbol es: %d", max->elem);
        printf("\n");
        arbol = removerMaxABB(arbol);
    } else {
        printf("El árbol está vacío.");
    }

    printf("Elementos del árbol en orden después de eliminar el máximo: ");
    imprimirEnOrden(arbol);


    return 0;
}


// g++ 3.4.removerMaxABB.cpp auxiliares.cpp -o removerMaxABB