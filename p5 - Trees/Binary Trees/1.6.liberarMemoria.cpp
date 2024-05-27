#include "auxiliares.h"


// liberar memoria
void liberarMemoria(AB raiz) {
    if (raiz == nullptr) {
        return;
    }
    
    liberarMemoria(raiz->izq);
    liberarMemoria(raiz->der);
    
    delete raiz;
}



