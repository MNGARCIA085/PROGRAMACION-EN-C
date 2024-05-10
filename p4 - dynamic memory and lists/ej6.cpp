

#include <stdio.h>

struct nodo {
    int elem ;
    nodo * sig ;
};
struct cabezal {
    nodo * primero ; // primer nodo de la lista
    nodo * actual ;
};


typedef cabezal * lista ;

/**
 * tenemos 2 implementaciones de null con sus ventajas
 * y desventajas
*/


// primera implementación
lista null_v0 (){
    cabezal *l = new cabezal;
    l -> primero = NULL;
    l -> actual = NULL;

    return l;
}


// la que usaremos
lista null(){
    return NULL;
}

// coloca la posición actual al inicio
void start(lista &l){
    l -> actual = l -> primero;
}

// next: devuelve el siguiente (si llega al final vuelve a empezar)
void next (lista &l){
    if ( l -> actual -> sig == NULL){ // si es el último
        l -> actual = l-> primero;
    }
    else {
        l -> actual = l -> actual -> sig;
    }
}

// retorna el elemento actual
int element (lista l){
    return l -> actual -> elem;
}

// insertar
/**
 * dados un entero x y una lista l, inserta el elemento x luego de la posición actual en la lista.
La posición actual pasa a ser el elemento (nodo) recién insertado. Si la lista l está vacía, el resultado
es la lista unitaria que contiene a x, siendo este elemento la posición actual en la lista resultado.
 * 
*/

void insertar(int x, lista &l){
    nodo *nuevo = new nodo;
    nuevo -> elem  = x;

    if (l == NULL){ // lista vacía
        l = new cabezal;
        l -> primero = nuevo;
        nuevo -> sig = NULL;
    }
    else {
        nuevo -> sig = l -> actual -> sig;
        l -> actual -> sig = nuevo;
    }

    l -> actual = nuevo;

}




// main para pruebas
int main() {
  // Crear una lista vacía
  lista l = null();

  // Insertar algunos elementos
  insertar(10, l);
  insertar(20, l);
  insertar(30, l);
  insertar(40, l);

  // llevo el puntero al inicio, sino lo sigueinte imprime sólo 40
  start(l);

  while (l->actual != NULL) {
    printf(" %d", l->actual->elem);
    l -> actual = l -> actual -> sig;
  }

   // veamos el primero
   printf("\n");
   printf("%d", l->primero->elem);
   printf("\n");



   // ahora, voy a mover actual e insertar luego

   start(l);
   next(l);

   insertar(70,l);

   // vuelvo al inicio
   start(l);
    // imprimo
   while (l->actual != NULL) {
        printf(" %d", l->actual->elem);
        l -> actual = l -> actual -> sig;
   }

   // veamos el primero
   printf("\n");
   printf("%d", l->primero->elem);


  

  return 0;
}


