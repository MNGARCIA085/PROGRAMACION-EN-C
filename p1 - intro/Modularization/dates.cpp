#include <stdio.h>

// Definición de la estructura para una fecha
struct rep_fecha {
    unsigned int d; // Día
    unsigned int m; // Mes
    unsigned int a; // Año
};

int main() {
    // Crear una instancia de Fecha e inicializarla
    struct rep_fecha miFecha = {15, 4, 2022};

    // Acceder a los campos de la fecha e imprimirlos
    printf("Día: %u\n", miFecha.d);
    printf("Mes: %u\n", miFecha.m);
    printf("Año: %u\n", miFecha.a);


    

    return 0;
}
