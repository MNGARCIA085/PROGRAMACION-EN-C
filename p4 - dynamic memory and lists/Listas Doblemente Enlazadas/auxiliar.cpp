
#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"

// imprimir lista (por valor)
void imprimirLista(lista l) {
    lista temp = l;
    while (temp != NULL) {
        printf("%d ", temp->elem);
        temp = temp->sig;
    }
    printf("\n");
}

// Función para imprimir la lista desde el final hasta el principio
void imprimirListaDesdeElFinal(lista l) {
    nodo_doble* temp = l;
    // Ir al último nodo
    while (temp != NULL && temp->sig != NULL) {
        temp = temp->sig;
    }
    // Imprimir desde el último nodo hacia el principio
    while (temp != NULL) {
        printf("%d -> ", temp->elem);
        temp = temp->ant;
    }
    printf("NULL\n");
}


// Función para crear un nuevo nodo
struct nodo_doble* crearNodo(int elem) {
    nodo_doble *nuevo = new nodo_doble;
    nuevo->elem = elem;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    return nuevo;
}

// Función para insertar un nodo al principio de la lista
void insertarAlInicio(lista &l, int elem) {
    struct nodo_doble* nuevoNodo = crearNodo(elem);
    if (l == NULL) {
        l = nuevoNodo;
    } else {
        nuevoNodo->sig = l;
        l->ant = nuevoNodo;
        l = nuevoNodo; // sino queda en el último; esto hace que l apunte al primero
            // la lista es un puntero al primer elemento
    }
}



// está vacía ?
bool isEmpty(lista l){
  return l == NULL;
}




//https://conclase.net/c/edd/cap5
















