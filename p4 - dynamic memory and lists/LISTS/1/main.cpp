

#include <stdio.h>
#include <stdlib.h>


struct nodo {
    int elem;
    nodo *sig; // puntero a un nodo
};

typedef nodo *lista; // la lista se define como un puntero a un nodo


// funciones auxiliares




// imprimir lista (por valor)
void imprimirLista(lista l) {



    lista temp = l;
    while (temp != NULL) {
        printf("%d ", temp->elem);
        //printf("%x ", temp->sig);
        temp = temp->sig;
    }
    printf("\n");
}


// crea una lista con ordenada con enteros del 1 al n (para n=10 da 1 2 3...10)
void crearLista(lista &l, int n) { // pasaje por referencia
    l = NULL;
    for (int i = n; i > 0; --i) {
        nodo *nuevo = new nodo;
        nuevo->elem = i;
        nuevo->sig = l;
        // que l apunte al nuevo
        l = nuevo;
    }
}



// lista vacía: 
bool isEmpty (lista p){
    return (p == NULL);
}


// crear una lista con elementos arbitrarios
void crearLista(lista &l, int elementos[], int n) {
  if (n <= 0) {
    printf("Error: La cantidad de elementos debe ser mayor que 0\n");
    return;
  }

  for (int i = 0; i < n; i++) {
    nodo *nuevo = new nodo;
    nuevo->elem = elementos[i];
    nuevo->sig = NULL;

    if (l == NULL) {
      l = nuevo;
    } else {
      nodo *aux = l;
      while (aux->sig != NULL) {
        aux = aux->sig;
      }
      aux->sig = nuevo;
    }
  }
}



// tmb, contempla el caso donde la lista es vacía inicialmente.
void insInicio(lista &l, int x) {
  nodo *nuevo = new nodo; // Crear nuevo nodo
  nuevo->elem = x; // Asignar valor al elemento del nodo
  nuevo->sig = l; // Apuntar el puntero `sig` del nuevo nodo a la cabeza de la lista actual
  l = nuevo; // Actualizar la cabeza de la lista para que apunte al nuevo nodo
}





// inserta en el medio de forma ordenada
void insOrd(lista &l, int x) {
  if (isEmpty(l)) { // Si la lista está vacía, se inserta al inicio
    insInicio(l, x);
    return;
  }

  nodo *nuevo = new nodo;
  nuevo->elem = x;

  nodo *anterior = NULL;
  nodo *actual = l;

  while (actual != NULL && actual->elem < x) {
    anterior = actual;
    actual = actual->sig;
  }

  if (anterior == NULL) { // Insertar al inicio
    nuevo->sig = l;
    l = nuevo;
  } else { // Insertar en el medio
    nuevo->sig = anterior->sig;
    anterior->sig = nuevo;
  }
}




// insOrd + simple
void insOrd2(lista &l, int x) {
    nodo *nuevo = new nodo;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    nuevo -> elem = x;
    // caso 1: insertar al inicio (lista vacía o x que va al principio)
    lista lpos = l;
    while ( lpos -> sig != NULL && lpos -> sig ->elem < x){
        lpos = lpos -> sig;
    }
    nuevo -> sig = lpos -> sig;
    lpos -> sig = nuevo;

}




// MAIN


int main(){

    lista l1 = NULL;
    crearLista(l1, 3);
    imprimirLista(l1);



    lista l2 = NULL;


    //
    int elementos[] = {10, 20, 30, 40, 50};
    int n = sizeof(elementos) / sizeof(elementos[0]); // Obtener cantidad de elementos del arreglo
    lista l = NULL; // Lista inicialmente vacía
    crearLista(l, elementos, n); // Crear lista con elementos del arreglo


    imprimirLista(l);


    //
    //insInicio(l, 8);
    //imprimirLista(l);

    //
    insOrd2(l, 25);
    imprimirLista(l);





}