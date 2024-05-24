#include "auxiliar.h"



// Función para remover todos los elementos x de una lista doblemente encadenada
void removerTodos(lista& l, int x) {
    
    nodo_doble* actual = l; // ó lista actual = l;
    

    while (actual != NULL) {
        // Guardamos una referencia al nodo actual antes de avanzar al siguiente
        nodo_doble* siguiente = actual->sig;

        if (actual->elem == x) {
            // Caso especial: si el nodo a eliminar es el primero
            if (actual->ant == NULL) {
                l = siguiente;
            } else {
                actual->ant->sig = siguiente;
            }

            // si no es el último acomodo el anterior
            if (siguiente != NULL) {
                siguiente->ant = actual->ant;
            }

            // Eliminamos el nodo actual
            delete actual;
        }

        // Avanzamos al siguiente nodo
        actual = siguiente;
    }
}





//
int main() {
    // Crear una lista con elementos repetidos
    lista head = NULL;
    insertarAlInicio(head, 10);
    insertarAlInicio(head, 20);
    insertarAlInicio(head, 30);
    insertarAlInicio(head, 40);
    insertarAlInicio(head, 40);

    // Imprimir la lista antes de remover los elementos
    printf("Lista antes de remover los elementos repetidos: ");
    imprimirLista(head);

    // Remover todas las ocurrencias del elemento 20
    removerTodos(head, 40);

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


// g++ 3.5.removerTodos.cpp auxiliar.cpp -o removerTodos