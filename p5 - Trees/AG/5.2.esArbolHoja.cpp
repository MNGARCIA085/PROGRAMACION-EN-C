#include "auxiliares.h"
#include <iostream>

/**
 * Dice si el árbol es sólo una hoja
*/

bool esArbolHoja(AG t){
    // que no sea vacío y que no tenga hijos
    return (  (t != NULL) && ( t -> pH == NULL) );
}

// observe que no hace falta chequear los hermanos