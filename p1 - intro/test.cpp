#include <stdio.h>
#include <stdlib.h> // Para qsort

#include <iostream>

// Definición de la estructura para una fecha
struct rep_fecha {
    unsigned int d; // Día
    unsigned int m; // Mes
    unsigned int a; // Año
};

// Función de comparación para qsort
int compararFechas(const void *fecha1, const void *fecha2) {
    const struct rep_fecha *f1 = (const struct rep_fecha *)fecha1;
    const struct rep_fecha *f2 = (const struct rep_fecha *)fecha2;

    // Comparación por año
    if (f1->a != f2->a) {
        return f1->a - f2->a;
    }
    // Comparación por mes
    if (f1->m != f2->m) {
        return f1->m - f2->m;
    }
    // Comparación por día
    return f1->d - f2->d;
}







int main() {
    



    // con new
    // Crear un arreglo dinámico de punteros a rep_fecha
    rep_fecha **arreglo = new rep_fecha*[3];

    // Agregar valores a los elementos del arreglo utilizando new
    arreglo[0] = new rep_fecha{10, 10, 2022};
    arreglo[1] = new rep_fecha{15, 5, 2022};
    arreglo[2] = new rep_fecha{20, 11, 1992};

    // Imprimir los valores de los elementos del arreglo
    std::cout << "Fechas:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << arreglo[i]->d << "/" << arreglo[i]->m << "/" << arreglo[i]->a << std::endl;
    }

    // Liberar la memoria asignada para cada elemento del arreglo
    for (int i = 0; i < 3; ++i) {
        delete arreglo[i];
    }

    // Liberar la memoria asignada para el arreglo
    delete[] arreglo;


    return 0;
}
