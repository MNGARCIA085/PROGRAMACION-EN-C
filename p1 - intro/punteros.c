#include <stdio.h>

int main()
{ 
    int * p; // p es un puntero a un entero
    int i; // i es un entero 
    p=&i; // p apunta a la dirección de i
    *p = 10; // i toma el valor de 10


    printf("El valor de la variable i es: %d\n", i); // Imprimir el valor de i
    printf("La dirección de memoria de la variable i es: %p\n", (void *)&i); 
            // Imprimir la dirección de memoria de i
    printf("La dirección de memoria almacenada en el puntero p es: %p\n", (void *)p); 
                // Imprimir la dirección de memoria almacenada en el puntero p

    int*p2; p2=p; //p2 apunt a la dirección de i
    p = NULL; // se deja en NULL el puntero
    p = new int; // se pide memoria
    delete p;
    return 0;
}



/**
g++ -c holamundo.cpp
g++ holamundo.o -o nombre_ejecutable
g++ holamundo.cpp programa.cpp -o nombre_ejecutable
 * 
*/


