#include <stdio.h>
#include "auxiliares.h"


// inserta en el medio de forma ordenada; pasaje por referencia
void insOrd(lista &l, int x) {

  // Si la lista está vacía, se inserta al inicio
  if (isEmpty(l)) { 
    insInicio(l, x);
    return;
  }

  // nodo a insertar
  nodo *nuevo = new nodo;
  nuevo->elem = x;

  // punteros auxiliares
  nodo *anterior = NULL;
  nodo *actual = l;

  // recorro hasta encontrar la posición donde insertar
  while (actual != NULL && actual->elem < x) {
    anterior = actual;
    actual = actual->sig;
  }


  // inserto
  if (anterior == NULL) { // Insertar al inicio
    nuevo->sig = l;
    l = nuevo;
  } else { // Insertar en el medio
    nuevo->sig = actual; // anterior -> sig
    anterior->sig = nuevo;
  }
}




/**
 * 
 * // insertar recursivo
    void insOrdRecursive(int x, lista &l){
    // caso base
    if ( l== NULL || l->elem >=x ){
        lista nuevo = new nodo;
        nuevo -> elem = x;
        nuevo -> sig = l;
        l = nuevo;
    }
    else {
        insOrdRecursive(x, l-> sig);
    }
}
*/



int main(){

    // lista arbitraria de elementos ordenados
    int elementos[] = {10, 20, 30, 40, 50};
    int n = sizeof(elementos) / sizeof(elementos[0]); // Obtener cantidad de elementos del arreglo
    lista l = NULL; // Lista inicialmente vacía
    crearLista(l, elementos, n); // Crear lista con elementos del arreglo
    imprimirLista(l);

    // inserto
    insOrd(l, 25);
    imprimirLista(l);

}


// g++ 1.3.insOrd.cpp auxiliares.cpp -o insOrd