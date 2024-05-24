#include "auxiliar.h"







// Función para borrar el último elemento de una lista doblemente enlazada
void removerUltimo(lista& l) {
    if (l == nullptr) {
        // La lista está vacía, no hay nada que borrar
        return;
    }

    // Si la lista tiene un solo elemento
    if (l->sig == nullptr) {
        delete l;
        l = nullptr;
        return;
    }


    // hago que el penúltimo apunte a null y borro el actual

    nodo_doble* actual = l;
    while (actual->sig != nullptr) {
        actual = actual->sig;
    }

    // al salir del while estoy parado en el último
    if (actual->ant != nullptr) {
        actual->ant->sig = nullptr;
    } else {
        // Si el elemento a borrar es el primero de la lista
        l = nullptr;
    }

    delete actual;
}




//
int main() {
    // Crear una lista con elementos repetidos
    lista head = NULL;
    insertarAlInicio(head, 10);
    insertarAlInicio(head, 20);
    insertarAlInicio(head, 30);
    insertarAlInicio(head, 40);


    // Imprimir la lista antes de remover el último
    printf("Lista antes de remover los elementos repetidos: ");
    imprimirLista(head);

    // quitar el último
    removerUltimo(head);

    // Imprimir la lista después de remover los elementos
    printf("Lista después de remover los elementos repetidos: ");
    imprimirLista(head);

    imprimirListaDesdeElFinal(head);

    // Liberar la memoria
    nodo_doble* temp;
    while (head != NULL) {
        temp = head;
        head = head->sig;
        delete temp;
    }

    return 0;
}


// g++ 3.6.removerUltimo.cpp auxiliar.cpp -o removerUltimo