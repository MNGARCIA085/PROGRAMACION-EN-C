/*
nota -> promedio de las 4 calificaciones más altas de un total de 5

ordeno el arreglo, me quedo con las n más altas y luego promedio

*/




#include <stdio.h>

// Función para ordenar un arreglo en orden descendente
void ordenarDescendente(int arreglo[], int longitud) {
    for (int i = 0; i < longitud - 1; i++) {
        for (int j = 0; j < longitud - i - 1; j++) {
            if (arreglo[j] < arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

// Función para calcular el promedio de las n calificaciones más altas
float promClase(int calificaciones[], int totalCalificaciones, int n) {
    // Ordenar las calificaciones en orden descendente
    ordenarDescendente(calificaciones, totalCalificaciones);

    // Calcular el promedio de las n calificaciones más altas
    float promedio = 0;

    // operador ternario; si es mayor que el total de calificaciones se corta a ese valor
    int limite = (n < totalCalificaciones) ? n : totalCalificaciones; // Evitar desbordamiento si n 
                                //es mayor que el total de calificaciones
    for (int i = 0; i < limite; i++) {
        promedio += calificaciones[i];
    }
    promedio /= limite;

    return promedio;
}

int main() {
    float prom;
    int cal1, cal2, cal3, cal4, cal5;
    printf("Ingrese las calificaciones: ");
    scanf("%d %d %d %d %d", &cal1, &cal2, &cal3, &cal4, &cal5);

    int calificaciones[] = {cal1, cal2, cal3, cal4, cal5};
    int totalCalificaiones = 5;
    int n = 4;

    prom = promClase(calificaciones, totalCalificaiones, n);
    
    printf("El promedio es %.2f\n", prom);
    return 0;
}
