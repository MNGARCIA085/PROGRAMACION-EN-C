#include <iostream>


/**
se deben implementar en O(1)
*/


struct nodo{
    int elem;
    nodo *sig;
};

typedef nodo * lEnt; // lista de enteros es un puntero a un nodo


// inserta al inicio
void insertar(int x, lEnt &l){
    lEnt nuevo = new nodo;
    nuevo -> elem = x;
    nuevo -> sig = l;
    l = nuevo;
}

// es vacía ?
bool esVacia(lEnt l){
    return l == NULL;
};


// primer elemento; pre-cond: no es vacía
int primero(lEnt l){
    return l -> elem;
};

// resto de la lista, sin el primer elemento (es como borrar el primer elemento)
void resto(lEnt &l){
    lEnt aBorrar = l;
    l = l -> sig;
    delete aBorrar;
};


// imprimir;
void imprimirLista(lEnt l){
    lEnt aux = l;
    while (aux != NULL){
        printf("%d ", aux -> elem);
        aux = aux -> sig;
    }
    printf("\n");
}


// main para test
int main(){
    lEnt l;

    bool vacia = esVacia(l);
    printf("%s\n", vacia ? "TRUE" : "FALSE");

    insertar(7, l);
    imprimirLista(l);

    insertar(3, l);
    insertar(4, l);
    imprimirLista(l);

    int first = primero(l);
    printf("%d \n", first);


    bool novacia = esVacia(l);
    printf("%s\n", novacia ? "TRUE" : "FALSE");

    // resto
    resto(l);
    imprimirLista(l);

}



// g++ 1.1.Pila.cpp -o pila








