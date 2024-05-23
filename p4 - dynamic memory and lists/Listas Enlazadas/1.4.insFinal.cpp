#include <stdio.h>
#include "auxiliares.h"

// devuelve el último elemento de una lista no vacía; pasaje por valor
void insFinal(lista &l, int x){

    // nuevo nodo
    nodo *nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig = NULL; // porque va al final

    // si está vacía
    if (isEmpty(l)){
        l = nuevo; 
        return;
    }

    // si no está vacía

    // recorro la lista con un puntero auxiliar, para que l me quede al inicio
    lista temp = l;
    while (temp-> sig != NULL){
        temp = temp -> sig;
    }
    
    // inserto
    temp -> sig = nuevo;
    
}


int main(){

    // no vacía
    lista l1 = NULL;
    crearLista(l1, 2);
    imprimirLista(l1);

    // insertar
    insFinal(l1, 7);
    imprimirLista(l1);


    // sobre una lista vacía
    lista l2 = NULL;
    insFinal(l2, 5);
    imprimirLista(l2);
    

}

// g++ 1.4.insFinal.cpp auxiliares.cpp -o insFinal