#include "auxiliares.h"



int contarNodos(ABB t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + contarNodos(t->izq) + contarNodos(t->der);
    }
}

ABB kesimoABB(uint k, ABB t) {
    int numNodosIzq = contarNodos(t->izq) + 1; // Número de nodos en el subárbol izquierdo + 1 (el nodo actual)
    if (k == numNodosIzq) {
        return t;
    } else if (k < numNodosIzq) {
        return kesimoABB(k, t->izq);
    } else {
        return kesimoABB(k - numNodosIzq, t->der);
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


    uint k = 1; // Encontrar el subárbol con el tercer elemento más pequeño
    ABB subarbolKesimo = kesimoABB(k, arbol);


    imprimirEnOrden(subarbolKesimo);
   

    return 0;
}


// g++ 3.6.k-esimo.cpp auxiliares.cpp -o k-esimo