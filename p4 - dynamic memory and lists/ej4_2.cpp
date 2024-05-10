/**
 * Remover todas las apariciones de x en una lista l
 * 
 * Debemos usar 2 punteros auxiliares, para que una vez que 
 * borre no deba volver a recorrer desde el principio
*/

#include <stdio.h>

struct nodo_doble {
    int elem;
    nodo_doble *sig;
    nodo_doble * ant;
};

typedef nodo_doble * lista;



// remover todas
void removeAll(int x, lista &l){

    lista lpos, aborrar = l; // punteros auxiliares

    while (lpos != NULL){
        if ( lpos -> elem == x){
            // borro
            aborrar = lpos;
            // chequeo de NULL
            if ( lpos -> ant != NULL){
                lpos -> ant -> sig = lpos -> sig;
            }
            else { // caso en qie es el primero (l->ant es NULL)
                l = lpos -> sig;
            }
            if (lpos -> sig != NULL){
                lpos -> sig -> ant = lpos -> ant;
            }

            lpos = lpos -> sig;
            delete aborrar;

        }
        else {
            lpos = lpos -> sig;
        }
    }

}



//creart lista doblemente anidada
void crearLista(lista &l, int n) {
    l = NULL;
    nodo_doble *anterior = NULL;
    for (int i = 0; i < n; ++i) {
        nodo_doble *nuevo = new nodo_doble;
        nuevo->elem = i;
        nuevo->sig = l;
        if (anterior != NULL) {
            anterior->ant = nuevo;
        }
        anterior = nuevo;
        l = nuevo;
    }
}


// Función para imprimir una lista
void imprimirLista(const lista l) {
    lista temp = l;
    while (temp != NULL) {
        printf("%d ", temp->elem);
        temp = temp->sig;
    }
    printf("\n");
}


// Main para probar
int main() {

    int x = 7;  // Elemento a eliminar
    int n = 10;  // Tamaño de la lista
    lista l;
    crearLista(l, n);

    imprimirLista(l);

    // Eliminar todas las apariciones de x
    removeAll(x, l);

    // Imprimir la lista después de eliminar todas las apariciones del valor x
    //printf("Lista después de eliminar todas las apariciones del valor x: ");
    imprimirLista(l);

    return 0;
}