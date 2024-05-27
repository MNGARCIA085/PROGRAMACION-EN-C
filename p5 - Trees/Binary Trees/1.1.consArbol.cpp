#include "auxiliares.h"

// Función para construir un árbol no vacío a partir de un valor y dos árboles
AB consArbol(int valor, AB izquierda, AB derecha) {
    nodoAB* nuevoNodo = crearNodo(valor);
    nuevoNodo->izq = izquierda;
    nuevoNodo->der = derecha;
    return nuevoNodo;
}


int main() {
    
    // Construir árboles para prueba
    AB izquierda = crearNodo(2);
    AB derecha = crearNodo(3);

    // pruebo la función
    AB arbol = consArbol(1, izquierda, derecha);
    
    // Imprimir el árbol en recorrido en-orden
    printf("Recorrido en-orden del árbol construido: ");
    enOrden(arbol);

    // Liberar la memoria del árbol
    liberarArbol(arbol);
    

    return 0;
}


// g++ 1.1.consArbol.cpp auxiliares.cpp -o consArbol