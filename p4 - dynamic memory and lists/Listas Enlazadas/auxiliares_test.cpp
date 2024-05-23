#include "auxiliares.h"

// pruebo las funciones auxiliares


int main(){

    // crear lista con elementos del 1 al 10
    lista l1 = NULL;
    crearLista(l1, 3);
    printf("Lista con enteros del 1 al n (3 en este ejemplo): ");
    imprimirLista(l1);
    printf("\n");

    // crear una lista con elementos arbitrarios
    printf("Lista con enteros arbitrarios: ");
    int elementos[] = {10, 20, 98, 30, 40, 50};
    int n = sizeof(elementos) / sizeof(elementos[0]); // Obtener cantidad de elementos del arreglo
    lista l = NULL; // Lista inicialmente vacía
    crearLista(l, elementos, n); // Crear lista con elementos del arreglo
    imprimirLista(l);


    // longitud


}


// g++ auxiliares_test.cpp auxiliares.cpp -o auxiliares
