#include "auxiliares.h"
#include <iostream>

/**
 * Dados un árbol y dos enteros v y w, inserta a v como el primer hijo de w en el árbol (hijo más
*  a la izquierda) si w pertenece al árbol y v no pertenece al árbol. 
*  En caso contrario la operación no tiene efecto.
*/


AG buscar(int x, AG t){
    if ( t == NULL ){
        return NULL;
    }
    else if ( t -> dato == x){
        return t;
    }
    else {
        AG buscar_hijos = buscar(x, t -> pH);
        AG buscar_hermanos = buscar(x, t -> sH);
        // busco en los hijos (hacia abajo) y si no está busco en los hermanos (costado)
        if ( buscar_hijos != NULL){
            return buscar_hijos;
        }
        else {
            return buscar_hermanos;
        }
    }
}

// insertar
void insertar(int v, int w, AG & t){
    // chequeos para saber si están
    AG nodo_v = buscar(v, t);
    AG nodo_w = buscar(w, t);

    //
    if ( nodo_v == NULL && nodo_w != NULL){ // que v no esté y w si
        AG nodo_v = new nodoAG; // ver si debería cambiar el nombre
        nodo_v -> dato = v;
        nodo_v -> pH = NULL;
        nodo_v -> sH = nodo_w -> pH;
        nodo_w -> pH = nodo_v;
    }

}


// main para chequear
int main() {

    // árbol de prueba
    AG arbol = nuevoNodo(1);


    imprimirPreorden(arbol);
    printf("\n");

    insertar(2, 1, arbol);
    insertar(7, 2, arbol);
    insertar(9, 7, arbol);
    insertar(25, 17, arbol); // no debería hacer nada

    imprimirPreorden(arbol);


    liberarArbol(arbol);

    return 0;
}

// g++ 5.4.insertar.cpp auxiliares.cpp -o insertar