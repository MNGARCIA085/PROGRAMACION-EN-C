#include "auxiliares.h"


void insertarABB (uint elem, ABB & t){
    if (t == NULL){
        t = new nodoABB ;
        t->elem = elem;
        t->izq = t->der = NULL;
    }
    else if (elem < t->elem){ // va en el izquierdo
        insertarABB (elem, t->izq);
    }
    else if (elem > t->elem) { // va en el derecho
        insertarABB (elem, t->der);
    }
        
}


int main() {
    ABB arbol = NULL;

    // Insertar algunos elementos en el árbol.
    insertarABB(5, arbol);
    insertarABB(3, arbol);
    insertarABB(8, arbol);
    insertarABB(1, arbol);
    insertarABB(4, arbol);
    insertarABB(7, arbol);
    insertarABB(9, arbol);
    insertarABB(7, arbol); // no debería insertarlo, el 7 ya está

    // Imprimir los elementos del árbol en orden.
    printf("Elementos del árbol en orden: ");
    imprimirEnOrden(arbol);
    

    // libero memoria
    liberarMemoria(arbol);





    return 0;
}

// g++ 3.1.insertarABB.cpp auxiliares.cpp -o insertarABB
