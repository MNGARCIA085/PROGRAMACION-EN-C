#include <stdio.h>
#include <stdlib.h> // Para malloc y realloc

// Definición de la estructura para un punto en 2D
typedef struct rep_punto {
    int coordX;
    int coordY;
} Punto;

// Definición de la estructura para una colección de puntos
typedef struct rep_colPuntos {
    int capacidad;
    int cantidad;
    Punto *arregloPuntos;
} ColPuntos;

// Función para insertar un punto de forma ordenada en la colección
void insertarPuntoOrdenado(ColPuntos *colPuntos, Punto nuevoPunto) {
    // Verificar si la colección está llena
    if (colPuntos->cantidad >= colPuntos->capacidad) {
        printf("La colección está llena. La inserción no tiene efecto.\n");
        return;
    }

    int i = colPuntos->cantidad - 1; // Índice del último punto en la colección

    // Desplazar los puntos existentes para hacer espacio para el nuevo punto
    while (i >= 0 && (colPuntos->arregloPuntos[i].coordX > nuevoPunto.coordX ||
                      (colPuntos->arregloPuntos[i].coordX == nuevoPunto.coordX &&
                       colPuntos->arregloPuntos[i].coordY > nuevoPunto.coordY))) {
        colPuntos->arregloPuntos[i + 1] = colPuntos->arregloPuntos[i];
        i--;
    }

    // Insertar el nuevo punto en la posición correcta
    colPuntos->arregloPuntos[i + 1] = nuevoPunto;
    colPuntos->cantidad++;
}

int main() {
    // Crear una instancia de ColPuntos
    ColPuntos colPuntos;
    colPuntos.capacidad = 10; // Capacidad inicial
    colPuntos.cantidad = 0;
    colPuntos.arregloPuntos = malloc(colPuntos.capacidad * sizeof(Punto));

    // Insertar algunos puntos de forma ordenada en la colección
    insertarPuntoOrdenado(&colPuntos, (Punto){3, 2});
    insertarPuntoOrdenado(&colPuntos, (Punto){1, 5});
    insertarPuntoOrdenado(&colPuntos, (Punto){2, 3});

    // Imprimir la colección de puntos ordenada
    printf("Colección de puntos ordenada:\n");
    for (int i = 0; i < colPuntos.cantidad; i++) {
        printf("(%d, %d)\n", colPuntos.arregloPuntos[i].coordX, colPuntos.arregloPuntos[i].coordY);
    }

    // Liberar la memoria asignada
    free(colPuntos.arregloPuntos);

    return 0;
}
