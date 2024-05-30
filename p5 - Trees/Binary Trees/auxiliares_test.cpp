#include "auxiliares.h"


int main() {
    AB raiz = nullptr;
    uint valores[] = {5, 3, 7, 2, 4, 6, 8};
    
    // Insertar valores en el árbol binario
    for (uint valor : valores) {
        raiz = insertar(raiz, valor);
    }
    
    // Imprimir el árbol en recorrido en-orden
    printf("Recorrido en-orden del árbol binario: ");
    enOrden(raiz);

    //
    //imprimirArbol(raiz, 7);

    // Liberar la memoria del árbol
    liberarArbol(raiz);
    


    
    return 0;
}


// g++ auxiliares_test.cpp auxiliares.cpp -o auxliares_test