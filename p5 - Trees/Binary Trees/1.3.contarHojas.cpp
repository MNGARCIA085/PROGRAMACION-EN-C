#include "auxiliares.h"

/**
 * árbol vacío: 0
 * árbol no vacío: AB(I, r, D): si el izquierdo y el derecho son vacíos quiere decir
 *      que el nodo es hoja, entonces sumo 1 (en otro caso no sumo); y a esto le debo agregar la suma de las
 *      hojas del izquierdo y del derecho
*/

int contarHojas(AB a){
    if (a==NULL){
        return 0;
    }
    else {
        if ( a->izq == NULL && a->der == NULL){
            return 1;
        }
        else {
            return contarHojas(a->izq) + contarHojas(a->der);
        }

    }
}



// test
int main() {
    
    AB raiz = NULL;
    uint valores[] = {5, 3, 7, 2, 4, 6, 8, 12};
    
    // Insertar valores en el árbol binario
    for (uint valor : valores) {
        raiz = insertar(raiz, valor);
    }

    // pruebo la función
    int cant = contarHojas(raiz);
    
    // Imprimir el árbol en recorrido en-orden
    enOrden(raiz);
    printf("\n%d hojas \n",  cant);

    // Liberar la memoria del árbol
    liberarArbol(raiz);
    

    return 0;
}


// g++ 1.3.contarHojas.cpp auxiliares.cpp -o contarHojas