#include "auxiliar.h"

// insertar al inicio
void insertarInicio(lista &l, int elem) {
    // nuevo nodo doble
    nodo_doble *nuevo = new nodo_doble;
    nuevo->elem = elem;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    
    if (l == NULL) {
        l = nuevo;
    } else {
        nuevo->sig = l;
        l->ant = nuevo;
        l = nuevo; // sino queda en el último; esto hace que l apunte al primero
            // la lista es un puntero al primer elemento
    }
}


// main de prueba
int main() {
    lista head = NULL; // Inicialización de la lista como vacía

    // Inserción de algunos elementos
    insertarAlInicio(head, 10);
    insertarAlInicio(head, 20);
    insertarAlInicio(head, 30);
    insertarAlInicio(head, 40);

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


// g++ 3.2.insInicio.cpp auxiliar.cpp -o insInicio