#include <stdio.h>
#include "auxiliares.h"

// removar todas las apariciones de x en l; l no es vacía
void remove(int x, lista &l){
    // si el elemento se encuentra varias veces al inicio
    while (l != NULL && l->elem == x) {
        nodo* temp = l;
        l = l->sig;
        delete temp;
    }
    
    if (l == NULL)
        return;

    nodo* prev = l;
    nodo* current = l->sig;

    while (current != NULL) {
        if (current->elem == x) {
            prev->sig = current->sig;
            delete current;
            current = prev->sig;
        } else {
            prev = current;
            current = current->sig;
        }
    }
}

int main(){

    // no vacía
    lista l1 = NULL;
    crearLista(l1, 6);
    imprimirLista(l1);
    remove(3, l1);
    imprimirLista(l1);


    // lista vacía
    lista l2 = NULL;
    remove(7, l2);
    imprimirLista(l2);



    // elemento que no es parte de la lista
    lista l3 = NULL;
    crearLista(l3, 5);
    imprimirLista(l3);
    remove(23, l3);
    imprimirLista(l3);


}

// g++ 1.5.removeAll.cpp auxiliares.cpp -o remove