// auxiliares.h
#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <iostream>

typedef unsigned int uint ;

struct nodoABB {
    uint elem ;
    nodoABB * izq , * der ;
};

typedef nodoABB * ABB ;


// Declaración de funciones
//void insertarABB(uint elem, ABB& t);
void imprimirEnOrden(ABB t);

// inserto en un ABB
void insertABB(uint elem, ABB &t);

// encontrar el máximo
ABB maximoABB(ABB t);

// mínimo
ABB encontrarMinABB(ABB t);

// liberar memoria
void liberarMemoria(ABB t);

#endif // AUXILIARES_H