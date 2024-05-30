#include "auxiliares.h"
#include <iostream>

/**
 * Dado un árbol t y un entero x devuelve True si x pertenece al árbol
*/

bool pertenece(AG t, int x){
    if ( t == NULL ){
        return false;
    }
    else if ( t -> dato == x){
        return true;
    }
    else {
        return ( pertenece(t->pH, x)  || pertenece (t->sH, x) );
    }
}