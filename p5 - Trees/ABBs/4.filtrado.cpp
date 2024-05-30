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




/**
 * Funciones auxiliares
*/



// máximo de un árbol
ABB maxABB(ABB t) {
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



// elimina el máximo de un nodo

// Función para remover la raíz del árbol y mantener la estructura del ABB
void removerABB(ABB& nodo) {
  if (nodo == NULL) {
    return;
  }

  // Caso 1: El nodo máximo no tiene hijo derecho
  if (nodo->der == NULL) {
    nodo = nodo->izq;
    return;
  }

  // Caso 2: El nodo máximo tiene hijo derecho
  nodoABB* padre_maximo = nodo;
  nodoABB* nodo_maximo = nodo->der;

  while (nodo_maximo->der != NULL) {
    padre_maximo = nodo_maximo;
    nodo_maximo = nodo_maximo->der;
  }

  // Reemplazar el valor del nodo máximo con el valor del predecesor máximo
  padre_maximo->der = nodo_maximo->izq;

  // Eliminar el nodo máximo
  delete nodo_maximo;
}


// imprimir 
void imprimirABB(ABB arbol) {
    if (arbol != NULL) {
        imprimirABB(arbol->izq);
        std::cout << "Nota: " << arbol->info.nota << ", CI: " << arbol->info.ci << std::endl;
        imprimirABB(arbol->der);
    }
}





// liberar memoria
// liberar memoria
void liberarMemoria(ABB raiz) {
    if (raiz == NULL) {
        return;
    }
    
    liberarMemoria(raiz->izq);
    liberarMemoria(raiz->der);
    
    delete raiz;
}






// 
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
    return result;
}

/**
 * Si ambos subárboles existen, encontramos el mayor nodo del subárbol izquierdo (maxABB(fizq)), 
 * lo utilizamos para reemplazar la raíz actual y luego lo eliminamos del subárbol izquierdo (removerABB(fizq)).
*/




int main() {
    // Crear un árbol de ejemplo
    ABB arbol = new nodoABB;
    arbol->info.nota = 10;
    arbol->info.ci = 1234;
    arbol->izq = new nodoABB;
    arbol->izq->info.nota = 5;
    arbol->izq->info.ci = 5678;
    arbol->izq->izq = NULL;
    arbol->izq->der = NULL;
    arbol->der = new nodoABB;
    arbol->der->info.nota = 15;
    arbol->der->info.ci = 9012;
    arbol->der->izq = NULL;
    arbol->der->der = NULL;

    // Imprimir el árbol antes de aplicar el filtrado
    std::cout << "Árbol original:" << std::endl;
    imprimirABB(arbol);
    std::cout << std::endl;

    // Filtrar el árbol manteniendo solo nodos con notas mayores a 8
    uint cota = 8;
    ABB arbolFiltrado = filtrado(arbol, cota);

    // Imprimir el árbol después del filtrado
    std::cout << "Árbol filtrado (notas mayores a " << cota << "):" << std::endl;
    imprimirABB(arbolFiltrado);

    // Liberar memoria (puedes omitir esta parte si no estás probando en un entorno con gestión automática de memoria)
    // Aquí deberías tener funciones para liberar la memoria del árbol, como liberarABB() o similar

    liberarMemoria(arbol);

    

    return 0;
}



// g++ 4.filtrado.cpp -o filtrado