#include "auxiliares.h"

/**
 * árbol vacío: 0 elementos
 * árbol no vacío: AB (izq, r, der) = 1 + elementos(izq) + elementos(der)
*/

int contarElems(AB a){
    if ( a == NULL){
        return 0;
    } else {
        return 1 + contarElems(a -> izq) + contarElems(a -> der);
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
    int cant = contarElems(raiz);
    
    // Imprimir el árbol en recorrido en-orden
    enOrden(raiz);
    printf("\n%d elems \n",  cant);

    // Liberar la memoria del árbol
    liberarArbol(raiz);
    

    return 0;
}


// g++ 1.2.contarElems.cpp auxiliares.cpp -o contarElems