



#include <stdio.h>


struct nodo {
    int elem;
    nodo *ant, *sig;
};

typedef nodo * lista;

void crearLista(lista &l, int n) {
    l = NULL;
    nodo *anterior = NULL;
    for (int i = 0; i < n; ++i) {
        nodo *nuevo = new nodo;
        nuevo->elem = i;
        nuevo->sig = l;
        if (anterior != NULL) {
            anterior->ant = nuevo;
        }
        anterior = nuevo;
        l = nuevo;
    }
}


void mostrarLista(lista l) {

    if (l == NULL) {
        //cout << "Lista vacía" << endl;
        return;
    }

    //cout << "Lista (hacia adelante): ";
    while (l != NULL) {
        //cout << l->elem << " ";
        printf("%d", l->elem);
        l = l->sig;
    }

    //cout << endl;

    //cout << "Lista (hacia atrás): ";
    nodo *aux = l;
    while (aux != NULL) {
        //cout << aux->elem << " ";
        printf("aux%d", aux->elem);
        aux = aux->ant;
    }
    //cout << endl;


    printf("\n");

}


void removeAll(int x, lista &l) {
    lista lpos, aborrar = l; // punteros auxiliares

    while (lpos != NULL) {
        if (lpos->elem == x) {
            aborrar = lpos;

            if (lpos->ant != NULL) {
                lpos->ant->sig = lpos->sig;
            } else {
                l = lpos->sig;
            }

            if (lpos->sig != NULL) {
                lpos->sig->ant = lpos->ant;
            }

            delete aborrar;
        } else {
            lpos = lpos->sig;
        }
    }
}



int main() {
    int x = 3;  // Elemento a eliminar
    int n = 10;  // Tamaño de la lista

    lista l;

    crearLista(l, n);
    mostrarLista(l);

    removeAll(x, l);
    mostrarLista(l);

    return 0;
}
