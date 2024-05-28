#include "auxiliares.h"
#include <iostream>



void removerABB(uint elem, ABB & t) {
    if (t == NULL) {
        return;
    } else if (elem < t->elem) {
        removerABB(elem, t->izq);
    } else if (elem > t->elem) {
        removerABB(elem, t->der);
    } else { // Encontramos el elemento a eliminar
        if (t->izq == NULL && t->der == NULL) { // Caso 1: Nodo hoja
            delete t;
            t = NULL;
        } else if (t->izq == NULL) { // Caso 2: Solo tiene hijo derecho
            ABB temp = t;
            t = t->der;
            delete temp;
        } else if (t->der == NULL) { // Caso 2: Solo tiene hijo izquierdo
            ABB temp = t;
            t = t->izq;
            delete temp;
        } else { // Caso 3: Tiene dos hijos
            ABB sucesor = encontrarMinABB(t->der);
            t->elem = sucesor->elem;
            removerABB(sucesor->elem, t->der);
        }
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

    // Eliminamos el elemento 7
    uint elementoAEliminar = 7;
    removerABB(elementoAEliminar, arbol);

    imprimirEnOrden(arbol);
    

    //
    liberarMemoria(arbol);

    return 0;
}


// g++ 3.5.removerABB.cpp auxiliares.cpp -o removerABB