#include <stdio.h>
#include "auxiliares.h"


lista MergeSort(lista l, lista p){ // paso por valor; no comparto memoria con los params
    lista res, dummy = new nodo;
    res = dummy;

    // intercalado
    while (l!= NULL && p!= NULL){
        
        res -> sig = new nodo; // se crea un nuevo nodo y se establece el puntero 'sig' del anterior a él
        res = res -> sig; // me muevo

        if ( l-> elem < p -> elem){
            res -> elem = l -> elem;
            l = l -> sig;
        }
        else {
            res -> elem = p-> elem;
            p = p -> sig;
        }
    }

    // en este punto me pueden quedar elementos restantes en alguna de las dos

    // si quedan en l
    while ( l!= NULL){
        // creo un nuevo nodo para res
        res -> sig = new nodo;
        res = res -> sig;
        res ->elem = l -> elem;
        // me muevo en l
        l = l -> sig;
    }

    // si quedan en p
    while ( p!= NULL){
        // creo un nuevo nodo para res
        res -> sig = new nodo;
        res = res -> sig;
        res ->elem = p -> elem;
        // me muevo en l
        p = p -> sig;
    }


    // para retornar apropiadamente;si no lo hago me retorna el último elemento solamente
    res -> sig = NULL; // el nodo ahora es el último de la lista
    res = dummy -> sig; // hago que apunte al primero de la lista
    delete dummy;

    // return
    return res;

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


// g++ 2.4.mergeSort.cpp auxiliares.cpp -o mergeSort