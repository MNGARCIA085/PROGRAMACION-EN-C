#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int elem;
    nodo *sig; // puntero a un nodo
};

typedef nodo *lista; // la lista se define como un puntero a un nodo


/**
 * nodo *otro = new nodo;
 * lista nuevo = new nodo;
 * 
 * 
 * otro -> elem = 11; le asigno el valor 11 a elem
 * otro -> sig = nuevo;
 * 
 * nuevo -> elem = 6;
 * nuevo -> sig = NULL;
 * 
 * la memoria solicitada dinámicamente debe liberarse cuando ya no se necesite
 * 
 * delete ( otro -> sig);
 * otro -> sig = NULL; no obligatorio pero recomendado
 * nuevo = otro
 * 
*/


// imprime una lista
void imprimirLista(lista l){
    lista temp = l;
    printf("Lista resultante: ");
    while (temp != NULL) {
        printf("%d ", temp->elem);
        temp = temp->sig;
    }
    printf("\n");
}


// último elemento de una lista de enteros
// pre-condición: lista no vacía
int lastElement(lista l){
    lista temp = l;
    while (temp-> sig != NULL){
        temp = temp -> sig;
    }
    int ult = temp -> elem;
    return ult;
}


// promedio de los elementos de un arreglo
// pre-condición: lista no vacía
float avgList(lista l){
    lista temp = l;
    float suma = 0.0; // suma acumulada
    int contador = 0; // cant. de elementos
    while ( temp != NULL){
        suma += (temp -> elem);
        contador++;
        temp = temp -> sig;
    }
    return suma/contador;
}



// inserta en una lista ordenada
void insOrd(int x, lista &l){ //&l: pasaje por referencia
    lista nuevo = new nodo; // creo un nuevo elemento para la lista
    nuevo -> elem = x; // al valor de elem del nuevo elemento le pongo el valor x
    if ( l == NULL || l -> elem >= x ){ // si la lista es vacía o x es menor que l.elem (x iría al principio)
        nuevo -> sig = l; // el siguiente de nuevo va a l
        l = nuevo; // l apunta a nuevo
    }
    else {
        lista lpos = l;
        while ( lpos -> sig != NULL && lpos -> sig-> elem < x){ // mientras no llegue al finy los elems. sean menor a x
            lpos = lpos -> sig; // recorro la lista
        };
        // inserto
        nuevo -> sig = lpos -> sig;
        lpos -> sig = nuevo;
    }
};



// insertar recursivo
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


// removar todas las apariciones de x en l; l no es vacía
void remove(int x, lista &l){
    // si el elemento se encuentra varias veces al inicio
    while (l != NULL && l->elem == x) {
        nodo* temp = l;
        l = l->sig;
        delete temp;
    }
    
    if (l == NULL)
        return;

    nodo* prev = l;
    nodo* current = l->sig;

    while (current != NULL) {
        if (current->elem == x) {
            prev->sig = current->sig;
            delete current;
            current = prev->sig;
        } else {
            prev = current;
            current = current->sig;
        }
    }
}



// Función para verificar si una lista está incluida en otra lista
// si l2 está incluida en l1; el largo de l1 debe ser mayor o igual que el de l2
bool isIncluded(lista l1, lista l2) { // pasaje por valor
    if (l1 == NULL || l2 == NULL) {
        return false;
    }

    lista temp1 = l1;
    lista temp2 = l2;

    while (temp1 != NULL && temp2 != NULL && l1 != NULL) {

        printf("pos. de l2 %x", &l2);

        if (temp1->elem == temp2->elem) {
            temp1 = temp1->sig;
            temp2 = temp2->sig;
        } else {
            temp1 = l1; // Reiniciar temp1 al comienzo de l1
            l1 = l1->sig;
            temp2 = l2; // Reiniciar temp2 al comienzo de l2; en este loop l2 NO cambia
        }
    }

    // Si temp2 llegó al final de la lista l2, entonces l2 está incluida en l1
    return temp2 == NULL;
}

    


// PROGRAMA PRINCIPAL
int main() {
    // Inicialización de la lista como vacía
    lista l = NULL;

    // Insertar elementos en orden
    
    /**
    insOrd(1, l);
    insOrd(3, l);
    insOrd(2, l);
    insOrd(3, l);
    insOrd(3, l);
    */
    
    insOrd(3, l);
    insOrd(17, l);
    

    // Imprimir la lista resultante
    imprimirLista(l);


    // lista no vacía creada a mano
    // Crear los nodos
    nodo* nodo1 = new nodo;
    nodo* nodo2 = new nodo;
    nodo* nodo3 = new nodo;

    // Asignar valores a los elementos de los nodos
    nodo1->elem = 10;
    nodo2->elem = 20;
    nodo3->elem = 30;

    // Establecer las relaciones entre los nodos
    nodo1->sig = nodo2;
    nodo2->sig = nodo3;
    nodo3->sig = NULL; // Este es el último nodo, por lo que su puntero siguiente debe ser NULL

    // Ahora `nodo1` es el primer nodo de la lista
    lista l2 = nodo1;

    // pruebo el insertar
    insOrd(35, l2); // 35 debería ir al final
    insOrd(17,l2); 

    // Imprimir la lista resultante
    imprimirLista(l2);


    // fn. recursiva
    insOrdRecursive(23, l2);
    imprimirLista(l2);

    // último
    int last = lastElement(l2);
    printf("Last element %2d", last);
    printf("\n");

    // promedio
    float avg = avgList(l2);
    printf("Average of l2: %2f", avg);
    printf("\n");


    // remover
    int elem = 3;
    remove(elem, l);
    imprimirLista(l);


    // lista incluida en otra
    lista l3 = NULL;
    insOrd(5, l3);
    insOrd(7, l3);

    lista l4 = NULL;
    insOrd(5, l4);
    insOrd(7, l4);
    insOrd(5, l4);
    insOrd(9, l4);

    bool aux = isIncluded(l4, l3);
    if (aux) {
        printf("El booleano es verdadero.\n");
    } else {
        printf("El booleano es falso.\n");
    }


    return 0;
}


