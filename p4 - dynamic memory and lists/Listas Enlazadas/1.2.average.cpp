#include <stdio.h>
#include "auxiliares.h"

// devuelve el último elemento de una lista no vacía; pasaje por valor
float average(lista l){
    if (isEmpty(l)){
        return -1;
    }
    else {
        lista temp = l; // uso temp para no modificar el puntero de l (aunque por valor no debería importar?)
        float suma = 0.0;
        int contador = 0;
        while (temp != NULL){
            contador++;
            suma += temp -> elem; 
            temp = temp -> sig;
        }
        return suma/contador;
    }
}


int main(){

    // no vacía
    lista l1 = NULL;
    crearLista(l1, 6);
    imprimirLista(l1);
    float prom1 = average(l1);
    if (prom1 != -1){
        printf("El promedio es %f\n", prom1);
    } else {
        printf("Lista vacía\n");
    }; 

    // vacía
    lista l2 = NULL;
    imprimirLista(l2);
    float prom2 = average(l2);
    if (prom2 != -1){
        printf("El promedio es %f\n", prom2);
    } else {
        printf("Lista vacía\n");
    } 

}

// g++ 1.2.average.cpp auxiliares.cpp -o average