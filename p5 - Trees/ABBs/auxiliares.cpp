#include "auxiliares.h"


// imprimir en orden
void imprimirEnOrden(ABB t) {
    if (t != NULL) {
        imprimirEnOrden(t->izq);
        printf("%d ", t->elem);
        imprimirEnOrden(t->der);
    }
}


// insertar
void insertABB(uint elem, ABB& t) {
    if (t == NULL) {
        t = new nodoABB;
        t->elem = elem;
        t->izq = t->der = NULL;
    } else if (elem < t->elem) {
        insertABB(elem, t->izq);
    } else if (elem > t->elem) {
        insertABB(elem, t->der);
    }
}



// máximo, retorna un árbol
ABB maximoABB(ABB t) {
    if (t == NULL) {
        return NULL;
    } else {
        // Recorre hacia la derecha hasta encontrar el nodo más a la derecha
        while (t->der != NULL) {
            t = t->der;
        }
        return t;
    }
}


// mínimo
ABB encontrarMinABB(ABB t) {
    if (t == NULL) {
        return NULL;
    } else if (t->izq == NULL) {
        return t;
    } else {
        return encontrarMinABB(t->izq);
    }
}



// liberar memoria
void liberarMemoria(ABB raiz) {
    if (raiz == NULL) {
        return;
    }
    
    liberarMemoria(raiz->izq);
    liberarMemoria(raiz->der);
    
    delete raiz;
}