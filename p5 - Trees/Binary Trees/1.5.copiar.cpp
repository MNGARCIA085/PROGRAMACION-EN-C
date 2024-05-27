#include "auxiliares.h"

/**
 * árbol vacío: devuelve uy¿n árbol vacío (puntero a NULL)
 * árbol no vacío a(I, r, D): devuelve un nuevo nodo en el cual se copia r en la raíz,
 *      como subárbol izquierdo una copia de I y como subárbol derecho una copia de D
*/


AB copiar(AB a){
    if (a == NULL){
        return NULL;
    }
    else {
        AB copia = new nodoAB; 
        copia -> elem = a -> elem;
        copia -> izq = copiar(a -> izq);
        copia -> der = copiar(a -> der);
        return copia;
    }
}

// main
int main() {
    
    AB raiz = NULL;
    uint valores[] = {5, 3, 7, 2, 4, 6, 8};
    
    // Insertar valores en el árbol binario
    for (uint valor : valores) {
        raiz = insertar(raiz, valor);
    }

    // pruebo la función
    AB copia = copiar(raiz);
    
    // Imprimir el árbol en recorrido en-orden
    enOrden(raiz);


    printf("\n");

    // copia
    enOrden(copia);


    // Liberar la memoria del árbol
    liberarArbol(raiz);
    

    return 0;
}


// g++ 1.5.copiar.cpp auxiliares.cpp -o copiar