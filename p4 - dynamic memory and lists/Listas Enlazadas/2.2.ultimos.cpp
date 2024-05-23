#include <stdio.h>
#include "auxiliares.h"

// eliminar los p primeros elementos de l


lista lastElements(lista l, int p){

    //
    if (l==NULL){
        return l;
    }

    // nueva lista que va a guardar los p últimos elementos de l
    lista q  = NULL;
    int contador = 1;

    while ( l != NULL ){
        if ( (contador > p) ){
            insFinal(q, l-> elem);
        }
        l = l -> sig;
        contador++;
    }
    return q;
}


int main(){

    // no vacía, primeros 3
    lista l1 = NULL;
    crearLista(l1, 7);
    lista aux = lastElements(l1, 3);
    printf("Lista original: ");
    imprimirLista(l1);
    printf("Ultimos elementos: ");
    imprimirLista(aux);


    
    // quito más elementos de los que tiene la lista, no debe devolver nada
    lista aux3 = lastElements(l1, 14);
    printf("Lista original: ");
    imprimirLista(l1);
    printf("Ultimos elementos: ");
    imprimirLista(aux3);

    // vacía
    lista l2 = NULL;
    lista aux2 = lastElements(l2, 3);
    printf("Lista vacía: ");
    imprimirLista(l2);
    imprimirLista(aux2);




}

// g++ 2.2.ultimos.cpp auxiliares.cpp -o ultimos