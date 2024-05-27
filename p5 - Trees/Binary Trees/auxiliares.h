// arbolBinario.h

#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <iostream>


//typedef unsigned int uint

struct nodoAB {
    uint elem;
    nodoAB* izq;
    nodoAB* der;
};

typedef nodoAB* AB;



AB crearNodo(uint valor);

AB insertar(AB raiz, uint valor);

void enOrden(AB raiz);

void liberarArbol(AB raiz);


void imprimirArbol(AB &raiz, int nivel);

#endif // ARBOLBINARIO_H
