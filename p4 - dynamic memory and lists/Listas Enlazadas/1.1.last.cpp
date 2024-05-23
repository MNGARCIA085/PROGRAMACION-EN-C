#include <stdio.h>
#include "auxiliares.h"

// devuelve el último elemento de una lista no vacía; pasaje por valor
int lastElement(lista l){
    if (isEmpty(l)){
        return -1;
    }
    else {
        lista temp = l; // uso temp para no modificar el puntero de l (aunque por valor no debería importar?)
        while (temp-> sig != NULL){
            temp = temp -> sig;
        }
        return temp -> elem;
    }
}


int main(){

    // no vacía
    lista l1 = NULL;
    crearLista(l1, 5);
    int last1 = lastElement(l1);
    if (last1 != -1){
        printf("El último elemento es %d\n", last1);
    } else {
        printf("Lista vacía\n");
    }; 

    // vacía
    lista l2 = NULL;
    int last2 = lastElement(l2);
    if (last2 != -1){
        printf("El último elemento es %d\n", last2);
    } else {
        printf("Lista vacía\n");
    } 

}

// g++ 1.1.last.cpp auxiliares.cpp -o last