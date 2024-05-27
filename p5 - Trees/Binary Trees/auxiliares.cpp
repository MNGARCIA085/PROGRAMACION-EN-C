#include <iostream>
#include "auxiliares.h"

// Función para crear un nuevo nodo
AB crearNodo(uint valor) {
    AB nuevoNodo = new nodoAB();
    nuevoNodo->elem = valor;
    nuevoNodo->izq = nullptr;
    nuevoNodo->der = nullptr;
    return nuevoNodo;
}

// Función para insertar un nuevo nodo en el árbol binario de búsqueda
AB insertar(AB raiz, uint valor) {
    if (raiz == nullptr) {
        return crearNodo(valor);
    }
    if (valor < raiz->elem) {
        raiz->izq = insertar(raiz->izq, valor);
    } else {
        raiz->der = insertar(raiz->der, valor);
    }
    return raiz;
}


// Función para imprimir el árbol en recorrido en-orden (in-order)
void enOrden(AB raiz) {
    if (raiz != nullptr) {
        enOrden(raiz->izq);
        printf("%d ", raiz->elem);
        //std::cout << raiz->elem << " ";
        enOrden(raiz->der);
    }
}



// liberar memoria
void liberarArbol(AB raiz) {
    if (raiz == nullptr) {
        return;
    }
    
    liberarArbol(raiz->izq);
    liberarArbol(raiz->der);
    
    delete raiz;
}






// imprimir "lindo"
void imprimirArbol(AB &raiz, int nivel) {
    if (raiz == NULL) {
        printf("\n");
        return;
    }

    imprimirArbol(raiz->der, nivel + 1);

    for (int i = 0; i < nivel; i++) {
        printf("   ");
    }
    printf("%d\n", raiz->elem);

    imprimirArbol(raiz->izq, nivel + 1);
}

