#include <stdio.h>
#include "auxiliares.h"

// devuelve llos primeros p elementos de una lista; pasaje por valor
lista firstElements(lista l, int p){

    // si p es menor que el largo de l ver qué hacer (dar toda la lista es mi elección)
    if (len(l) < p){
        return l;
    }



    // nueva lista que va a guardar los p primeros elementos de l
    lista q  = NULL;
    int contador = 0;

    while ( (l != NULL) && (contador <= p) ){
        insFinal(q, l->elem); // primero inserta el 1, el 2 debe ir después.....
        l = l -> sig;
        contador++;
    }

    return q;
}


int main(){

    // no vacía, primeros 3
    lista l1 = NULL;
    crearLista(l1, 7);
    lista aux = firstElements(l1, 3);
    printf("Lista original: ");
    imprimirLista(l1);
    printf("Primeros elementos: ");
    imprimirLista(aux);


    
    // no vacía, quiero más elementos de los que tiene la lista
    lista aux3 = firstElements(l1, 14);
    printf("Lista original: ");
    imprimirLista(l1);
    printf("Primeros elementos: ");
    imprimirLista(aux3);

    // vacía
    lista l2 = NULL;
    lista aux2 = firstElements(l2, 3);
    printf("Lista vacía: ");
    imprimirLista(l2);
    imprimirLista(aux2);




}

// g++ 2.1.primeros.cpp auxiliares.cpp -o primeros