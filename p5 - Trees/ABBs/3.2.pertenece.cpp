#include "auxiliares.h"


bool pertenece (uint x, ABB t){
    while ( (t != NULL) && (t -> elem != x) ){
        if (t -> elem > x){
            t = t -> izq;
        } else {
            t = t -> der;
        }
    }
    // si no es NULL es porque lo encontró
    if (t != NULL){
        return true;
    } else {
        return false;
    }    
}




int main() {
    ABB arbol = NULL;

    // Insertar algunos elementos en el árbol.
    insertABB(5, arbol);
    insertABB(3, arbol);
    insertABB(8, arbol);
    insertABB(1, arbol);
    insertABB(4, arbol);
    insertABB(7, arbol);
    insertABB(9, arbol);


    // Imprimir los elementos del árbol en orden.
    printf("Elementos del árbol en orden: ");
    imprimirEnOrden(arbol);

    printf("\n");

    // está
    bool esta = pertenece(8, arbol);
    printf("%s\n", esta ? "true" : "false");

    // no está
    bool noesta = pertenece(17, arbol);
    printf("%s\n", noesta ? "true" : "false");

    // libero memoria
    liberarMemoria(arbol);





    return 0;
}

// g++ 3.2.pertenece.cpp auxiliares.cpp -o pertenece
