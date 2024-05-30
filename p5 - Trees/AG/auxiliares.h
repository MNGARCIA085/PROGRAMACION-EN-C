#ifndef NODOAG_H
#define NODOAG_H


// Definición de la estructura nodoAG
struct nodoAG {
    int dato;           // Dato almacenado en el nodo
    nodoAG *pH;         // Puntero al primer hijo
    nodoAG *sH;         // Puntero al siguiente hermano
};

// Definición del tipo AG como un puntero a nodoAG
typedef nodoAG *AG;


// Función para crear un nuevo nodo
nodoAG* nuevoNodo(int dato);


// imprimir pre-orden
void imprimirPreorden(AG raiz);


// Función para insertar un valor en el árbol binario
void insertarHijo(AG& padre, int dato);



// Función para liberar la memoria del árbol
void liberarArbol(AG raiz);

#endif // AUXILIARES_H