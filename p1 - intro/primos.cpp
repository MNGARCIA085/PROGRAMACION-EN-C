#include <stdio.h>

// Función para verificar si un número es primo
// en C 0 es false y cualquier otra cosa true
int esPrimo(int numero) {
    // Los números menores o iguales a 1 no son primos
    if (numero <= 1) {
        return 0;
    }

    // Iteramos desde 2 hasta la raíz cuadrada del número
    for (int i = 2; i * i <= numero; i++) {
        // Si el número es divisible por 'i', entonces no es primo
        if (numero % i == 0) {
            return 0;
        }
    }

    // Si el bucle termina sin encontrar divisores, entonces es primo
    return 1;
}

int main() {
    int A, B;

    printf("Ingrese el valor de A: ");
    scanf("%d", &A);

    printf("Ingrese el valor de B: ");
    scanf("%d", &B);

    printf("Números primos entre %d y %d:\n", A, B);

    // Verificar si cada número en el rango es primo y imprimirlo si lo es
    for (int i = A; i <= B; i++) {
        if (esPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
