#include <stdio.h>
#include "auxiliares.h"

// intercala los elementos de l y p (listas no vacías)



lista intercalar(lista l, lista p){
    /**
     * pre-condición: listas no vacías
    */
    

    // nueva lista que va a guardar los p últimos elementos intercalados
    lista q  = NULL;


    while ( (l != NULL) && (p != NULL) ){
        insFinal(q, l-> elem);
        insFinal(q, p -> elem);
        l = l -> sig;
        p = p -> sig;
    }
    
    // si quedan elementos en l
    while (l != NULL) {
        insFinal(q, l->elem);
        l = l->sig;
    }

    // si quedan elementos en p
    while (p != NULL) {
        insFinal(q, p->elem);
        p = p->sig;
    }

    return q;
}


int main(){

    // 
    lista l1 = NULL;
    crearLista(l1, 7);
    lista l2 = NULL;
    crearLista(l2, 3);

    lista aux = intercalar(l1, l2);
    imprimirLista(l1);
    imprimirLista(l2);
    imprimirLista(aux);



}

// g++ 2.3.intercalar.cpp auxiliares.cpp -o intercalar