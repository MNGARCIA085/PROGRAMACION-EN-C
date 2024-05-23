#include <stdio.h>
#include "auxiliares.h"


lista MergeSort(lista l, lista p){ // paso por valor; no comparto memoria con los params
    

    lista q = NULL;

    // intercalado
    while (l!= NULL && p!= NULL){
        

        if ( l-> elem < p -> elem){
            insFinal(q, l -> elem);
            l = l -> sig;
        }
        else {
            insFinal(q, p -> elem);
            p = p -> sig;
        }
    }

    // en este punto me pueden quedar elementos restantes en alguna de las dos

    // si quedan en l
    while ( l!= NULL){
        insFinal(q, l -> elem);
        l = l -> sig;
    }

    // si quedan en p
    while ( p!= NULL){
        insFinal(q, p -> elem);
        p = p -> sig;
    }


    return q;


}


int main() {
    // Crear la lista 1
    lista l1 = new nodo{1, NULL};
    l1->sig = new nodo{3, NULL};
    l1->sig = new nodo{4, NULL};
    l1->sig->sig = new nodo{5, NULL};

    // Crear la lista 2
    lista l2 = new nodo{2, NULL};
    l2->sig = new nodo{4, NULL};
    l2->sig->sig = new nodo{6, NULL};

    // Imprimir las listas originales
    printf("Lista 1: ");
    imprimirLista(l1);
    printf("Lista 2: ");
    imprimirLista(l2);

    // Ordenar y fusionar las listas
    lista result = MergeSort(l1, l2);

    // Imprimir la lista fusionada
    printf("Lista fusionada y ordenada: ");
    imprimirLista(result);

    // Liberar la memoria
    while (result != NULL) {
        lista temp = result;
        result = result->sig;
        delete temp;
    }

    return 0;
}


// g++ 2.5.mergeSort2.cpp auxiliares.cpp -o mergeSort2