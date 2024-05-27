#include "auxiliares.h"

/**
 * vacío: 0
 * no vacío: 1 + máximo de alturas entre el izquierdo y el derecho
*/

uint altura(AB a){
    if (a==NULL){
        return 0;
    }
    else {
        uint alt_izq = altura(a->izq);
        uint alt_der = altura(a->der);
        if (alt_izq > alt_der){
            return 1 + alt_izq;
        } else {
            return 1 + alt_der;
        }
    }
}



// test
int main() {
    
    AB raiz = NULL;
    uint valores[] = {5, 3, 7, 2, 4, 6, 8, 12, 17, 20};
    
    // Insertar valores en el árbol binario
    for (uint valor : valores) {
        raiz = insertar(raiz, valor);
    }

    // pruebo la función
    int cant = altura(raiz);
    
    // Imprimir el árbol en recorrido en-orden
    enOrden(raiz);
    printf("\n%d de alto \n",  cant);

    // Liberar la memoria del árbol
    liberarArbol(raiz);
    

    return 0;
}


// g++ 1.4.altura.cpp auxiliares.cpp -o altura