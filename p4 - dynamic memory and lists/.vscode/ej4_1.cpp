/**
 * insertar un elemento al inicio de una lista doblemente encadenada
*/


#include <stdio.h>

struct nodo_doble {
    int elem;
    nodo_doble *sig;
    nodo_doble * ant;
};

typedef nodo_doble * lista;


// Función para imprimir una lista
void imprimirLista(const lista l) {
    lista temp = l;
    while (temp != NULL) {
        printf("%d ", temp->elem);
        temp = temp->sig;
    }
    printf("\n");
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

// insertar al inicio
void cons(int x, lista &l){
    lista nuevo = new nodo_doble;
    nuevo -> elem = x;
    nuevo -> sig = l; // lo inserto primero
    nuevo -> ant = NULL; // es NULL porque va a ser el primero

    // cuidado por si la lista l es vacía
    if (l != NULL){
        l -> ant = nuevo;
    }

    l = nuevo;    
}


// Main para probar
int main() {

    int x = 7;  // Elemento a eliminar
    int n = 10;  // Tamaño de la lista
    lista l;
    crearLista(l, n);

    imprimirLista(l);

    // Eliminar todas las apariciones de x
    cons(x, l);


    imprimirLista(l);

    return 0;
}