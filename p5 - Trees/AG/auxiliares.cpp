#include "auxiliares.h"
#include <iostream>


// Función para imprimir el árbol en preorden
void imprimirPreorden(AG raiz) {
    if (raiz == nullptr) return;
    printf("%d " ,raiz->dato);
    imprimirPreorden(raiz->pH);
    imprimirPreorden(raiz->sH);
}


// Función para crear un nuevo nodo
nodoAG* nuevoNodo(int dato) {
    nodoAG* nodo = new nodoAG();
    nodo->dato = dato;
    nodo->pH = nullptr;
    nodo->sH = nullptr;
    return nodo;
}

// Función para insertar un nuevo hijo en un nodo dado
void insertarHijo(AG& padre, int dato) {
    nodoAG* nuevo = nuevoNodo(dato);
    if (padre->pH == nullptr) {
        padre->pH = nuevo;
    } else {
        nodoAG* temp = padre->pH;
        while (temp->sH != nullptr) {
            temp = temp->sH;
        }
        temp->sH = nuevo;
    }
}

// liberar memoria
void liberarArbol(AG raiz) {
    if (raiz != nullptr) {
        liberarArbol(raiz->pH);
        liberarArbol(raiz->sH);
        delete(raiz);
    }
}


// los del ej. 5
AG arbolHoja(int x){
    AG arbol = new nodoAG;
    arbol -> dato = x;
    arbol -> pH = NULL;
    arbol -> sH = NULL;
    return arbol;
}