#include "auxiliar.h"
#include <iostream>

int main() {
    lista head = NULL; // Inicialización de la lista como vacía

    // Inserción de algunos elementos
    insertarAlInicio(head, 10);
    insertarAlInicio(head, 20);
    insertarAlInicio(head, 30);

    // Impresión de la lista desde el principio hasta el final
    printf("Lista desde el inicio: ");
    imprimirLista(head);

    // Impresión de la lista desde el final hasta el principio
    printf("Lista desde el final: ");
    imprimirListaDesdeElFinal(head);


    // Liberar la memoria
    nodo_doble* temp;
    while (head != NULL) {
        temp = head;
        head = head->sig;
        delete temp;  // Usar delete en lugar de free para liberar la memoria en C++
    }

    return 0;
}



// g++ auxiliar_test.cpp auxiliar.cpp -o auxiliares


