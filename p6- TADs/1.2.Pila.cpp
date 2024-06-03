#include <iostream>


/**
se deben implementar en O(1); para ello, 
al tener que incluir la operación insFinal, debo
cambiar la definición de la estructura; sino tendría siempre
que recorrer la lista hasta el final; agregando un puntero
al inicio y al final es que puedo resolver lo pedido
*/


struct nodo{
    int elem;
    nodo *sig;
};

struct cabezal {
    nodo *ini, *fin;
};

typedef cabezal * lEnt; // ahora, son 2 punteros


// cambiamos la definición de NULL
lEnt null(){
    lEnt l = new cabezal;
    l -> ini = NULL;
    l -> fin = NULL;
    return l;
}


// inserta al inicio
void insertar(int x, lEnt &l){
    nodo *nuevo = new nodo;
    nuevo -> elem = x;
    nuevo -> sig = l -> ini;
    l -> ini = nuevo;

    if ( l -> fin == NULL){
        l -> fin = nuevo;
    }
}



// primer elemento; pre-cond: no es vacía
int primero(lEnt l){
    return l -> ini -> elem;
};



// insertar al final
void insFinal(int x, lEnt &l){
    nodo *nuevo = new nodo;
    nuevo -> elem = x;
    nuevo -> sig = NULL;
    // la inserción cambia si es o no vacía
    // dado que tengo 2 punteros
    if ( l -> fin != NULL){
        l -> fin -> sig = nuevo;
    }
    else { // es vacía; entonces l -> ini = NULL
        l -> ini = nuevo;
    }
    l -> fin = nuevo;

}




// Función para imprimir la lista enlazada
void imprimirLista(lEnt lista) {
    if (lista == NULL) {
        printf("La lista es NULL.\n");
        return;
    }
    struct nodo *actual = lista->ini;
    if (actual == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    while (actual != NULL) {
        printf("%d ", actual->elem);
        actual = actual->sig;
    }
    printf("\n");
}




// main para test
int main(){
    lEnt l = null();



    insFinal(7, l);
    imprimirLista(l);

    insertar(3, l);
    insertar(4, l);
    imprimirLista(l);

    insFinal(25, l);
    imprimirLista(l);

    int first = primero(l);
    printf("%d \n", first);




}



// g++ 1.2.Pila.cpp -o pila2








