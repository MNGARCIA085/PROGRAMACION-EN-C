
#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo doblemente encadenado
struct nodo_doble {
    int elem;
    nodo_doble* sig;
    nodo_doble* ant;
};

typedef nodo_doble* lista;

// Declaraciones de funciones
void imprimirLista(lista l);
void imprimirListaDesdeElFinal(lista l);
nodo_doble* crearNodo(int elem);
void insertarAlInicio(lista& l, int elem);
bool isEmpty(lista l);

#endif // LISTA_DOBLE_H
