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