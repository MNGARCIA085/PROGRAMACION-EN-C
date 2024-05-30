#include "auxiliares.h"
#include <iostream>

/**
 * Devuelve un árbol que sólo contiene una hoja
*/

AG arbolHoja(int x){
    AG arbol = new nodoAG;
    arbol -> dato = x;
    arbol -> pH = NULL;
    arbol -> sH = NULL;
}