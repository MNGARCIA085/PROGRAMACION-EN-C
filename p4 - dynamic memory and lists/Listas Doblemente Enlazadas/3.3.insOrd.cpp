#include <iostream>
#include "auxiliar.h"


// Función para insertar un elemento de forma ordenada en una lista doblemente enlazada
void insOrd(lista& lista, int valor) {
    nodo_doble* nuevoNodo = new nodo_doble;
    nuevoNodo->elem = valor;
    nuevoNodo->ant = nullptr;
    nuevoNodo->sig = nullptr;

    // Caso especial: lista vacía o el nuevo nodo debe ir al principio
    if (lista == nullptr || lista->elem >= valor) {
        nuevoNodo->sig = lista;
        if (lista != nullptr) {
            lista->ant = nuevoNodo;
        }
        lista = nuevoNodo;
    } else {
        // Encontrar el lugar adecuado para el nuevo nodo
        nodo_doble* actual = lista;
        while (actual->sig != nullptr && actual->sig->elem < valor) {
            actual = actual->sig;
        }

        nuevoNodo->sig = actual->sig;
        if (actual->sig != nullptr) {
            actual->sig->ant = nuevoNodo;
        }
        actual->sig = nuevoNodo;
        nuevoNodo->ant = actual;
    }
}



// Función para liberar la memoria de la lista
void liberarMemoria(lista& lista) {
    nodo_doble* actual = lista;
    while (actual != nullptr) {
        nodo_doble* temp = actual;
        actual = actual->sig;
        delete temp;
    }
    lista = nullptr;
}

int main() {
    // Creamos una lista doblemente encadenada y la llenamos con algunos elementos de forma ordenada
    lista l = NULL;
    insOrd(l, 5);
    imprimirLista(l);

    insOrd(l, 3);
    imprimirLista(l);
    
    insOrd(l, 8);
    imprimirLista(l);

    insOrd(l, 1);
    imprimirLista(l);
    
    insOrd(l, 7);
    imprimirLista(l);


    imprimirListaDesdeElFinal(l);

    // Liberamos la memoria de la lista
    liberarMemoria(l);

    return 0;
}


// g++ 3.3.insOrd.cpp auxiliar.cpp -o insOrd