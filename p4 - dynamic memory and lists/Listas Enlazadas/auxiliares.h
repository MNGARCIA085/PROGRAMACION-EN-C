#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int elem;
    nodo *sig; // puntero a un nodo
};

typedef nodo* lista; // la lista se define como un puntero a un nodo

// Función para imprimir la lista
void imprimirLista(lista l);

// Función para crear una lista con enteros del 1 al n
void crearLista(lista &l, int n);

// Función para verificar si una lista está vacía
bool isEmpty(lista p);

// Sobrecarga de la función para crear una lista con elementos arbitrarios
void crearLista(lista &l, int elementos[], int n);

// Función para insertar un elemento al inicio de la lista
void insInicio(lista &l, int x);


// insertar al final
void insFinal(lista &l, int x);


// largo de una lista
int len(lista l);

#endif // LISTA_H
