#include "auxiliares.h"


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


// es una lista vacía?
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


// insertar al final
void insFinal(lista &l, int x){

    // nuevo nodo
    nodo *nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig = NULL; // porque va al final

    // si está vacía
    if (isEmpty(l)){
        l = nuevo; 
        return;
    }

    // si no está vacía

    // recorro la lista con un puntero auxiliar, para que l me quede al inicio
    lista temp = l;
    while (temp-> sig != NULL){
        temp = temp -> sig;
    }
    
    // inserto
    temp -> sig = nuevo;
    
}



// largo de una lista, cuento la cantidad de elementos
int len(lista l){

  if (l == NULL){
    return 0;
  }

  int contador = 1; // no es null entonces tiene un primero
  while ( l-> sig != NULL){
    contador++;
    l = l-> sig;
  }

  return contador;

}







