#include <stdio.h>
#include "auxiliares.h"

// Función para verificar si una lista está incluida en otra lista
// si l2 está incluida en l1; el largo de l1 debe ser mayor o igual que el de l2
bool isIncluded(lista l1, lista l2) { // pasaje por valor
    if (l1 == NULL || l2 == NULL) {
        return false;
    }

    lista temp1 = l1;
    lista temp2 = l2;

    while (temp1 != NULL && temp2 != NULL && l1 != NULL) {

        if (temp1->elem == temp2->elem) {
            temp1 = temp1->sig;
            temp2 = temp2->sig;
        } else {
            temp1 = l1; // Reiniciar temp1 al comienzo de l1
            l1 = l1->sig;
            temp2 = l2; // Reiniciar temp2 al comienzo de l2; en este loop l2 NO cambia
        }
    }

    // Si temp2 llegó al final de la lista l2, entonces l2 está incluida en l1
    return temp2 == NULL;
}


int main(){

    // incluida al inicio
    lista l1 = NULL;
    crearLista(l1, 6);
    lista l2 = NULL;
    crearLista(l2, 3);
    bool aux = isIncluded(l1, l2);
    printf("%s\n", aux?"true":"false");

    // incluida en medio
    int elementos[] = {2, 3};
    int n = sizeof(elementos) / sizeof(elementos[0]); // Obtener cantidad de elementos del arreglo
    lista l3 = NULL; // Lista inicialmente vacía
    crearLista(l3, elementos, n); // Crear lista con elementos del arreglo
    bool aux2 = isIncluded(l1, l3);
    printf("%s\n", aux2?"true":"false");



    // no incluida
    int elementos2[] = {10, 20, 30, 40, 50};
    int n2 = sizeof(elementos2) / sizeof(elementos2[0]); // Obtener cantidad de elementos del arreglo
    lista l4 = NULL; // Lista inicialmente vacía
    crearLista(l4, elementos2, n); // Crear lista con elementos del arreglo
    bool aux3 = isIncluded(l1, l4);
    printf("%s\n", aux3?"true":"false");



     

}

// g++ 1.6.SubList.cpp auxiliares.cpp -o isSubList