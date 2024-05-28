#include <iostream>

typedef unsigned int uint ;

struct EstInfo {
    uint nota ; // dato
    int ci ; // clave
};

struct nodoABB {
    EstInfo info ;
    nodoABB * izq , * der ;
};

typedef nodoABB * ABB ;


/**
 * La idea es recorrer el árbol, si la nota cumple la condición
 * mantengo el nodo, en caso contrario lo elimino.
 * Para eliminarlo, cuando es una hoja es fácil, cuando no debo tener cuidado:
 * hay que remplazar el nodo por el mayor del izquierdo o el menor del derecho
 * para que siga siendo un ABB
*/



ABB filtrado(ABB a, uint cota){
    ABB result;
    // paso base
    if ( a == NULL ){
        result = NULL;
    } else { // paso recursivo
        ABB fizq = filtrado(a->izq, cota); 
        ABB fder = filtrado(a->der, cota);

        EstInfo raiz = a -> info;

        // mantengo el nodo
        if ( raiz.nota > cota ){
            result = new nodoABB;
            result -> info = raiz;
            result -> izq = fizq;
            result -> der = fder;
        // debo eliminar el nodo
        } else if ( fizq == NULL ) {
            result = fder;
        } else if ( fder = NULL ){
            result = fizq;
        } else { // acá borro un nodo; voy a eliminar el mayor del izquierdo (*)
            ABB mayor = maxABB(fizq); // fn. auxiliar
            result = new nodoABB;
            result -> info = mayor -> info;
            result -> izq = fizq;
            result -> der = fder;
            removerABB(fizq); // Remover el mayor nodo del subárbol izquierdo (confirmar!!)

        }
    }

}

/**
 * Si ambos subárboles existen, encontramos el mayor nodo del subárbol izquierdo (maxABB(fizq)), 
 * lo utilizamos para reemplazar la raíz actual y luego lo eliminamos del subárbol izquierdo (removerABB(fizq)).
*/