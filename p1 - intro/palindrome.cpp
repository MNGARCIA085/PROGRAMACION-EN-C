#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Función para eliminar los espacios y convertir todos los caracteres a minúsculas
void limpiarFrase(char *frase) {
    int indice = 0;
    for (int i = 0; frase[i]; i++) {
        if (isalpha(frase[i])) { // que sea una letra del alfabeto
            frase[indice++] = tolower(frase[i]);
        }
    }
    frase[indice] = '\0'; // Agregar el carácter nulo al final de la cadena
}

// Función para verificar si una frase es un palíndromo
int esPalindromo(char *frase) { // puntero a una cadena de caracteres
    int longitud = strlen(frase);
    for (int i = 0; i < longitud / 2; i++) {
        if (frase[i] != frase[longitud - i - 1]) {
            return 0; // No es un palíndromo
        }
    }
    return 1; // Es un palíndromo
}


// main
int main() {
    char frase[100];

    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin); // leer una línea de texto
    frase[strcspn(frase, "\n")] = '\0'; // Eliminar el salto de línea al final

    limpiarFrase(frase); // Limpiar la frase de espacios y convertir a minúsculas

    if (esPalindromo(frase)) {
        printf("La frase es un palíndromo.\n");
    } else {
        printf("La frase no es un palíndromo.\n");
    }

    return 0;
}


/**
 * char frase[100]: Esta declaración define un arreglo de caracteres de tamaño fijo de 100 elementos. 
 * Es decir, reserva espacio en memoria para almacenar 100 caracteres consecutivos. 
 * Este arreglo tiene una ubicación de memoria contigua y puede contener una cadena de hasta 99 caracteres 
 * más el carácter nulo '\0' al final. Este tipo de arreglo es estático, lo que significa que su 
 * tamaño se determina en tiempo de compilación y no puede cambiar durante la ejecución del programa.
 * 
 * 
 * Esta declaración define un puntero a un carácter o a una cadena de caracteres. 
 * No reserva espacio para almacenar la cadena en sí misma; en cambio, el puntero frase contendrá 
 * la dirección de memoria del primer carácter de la cadena. Este tipo de puntero es dinámico, 
 * lo que significa que puede apuntar a diferentes ubicaciones 
 * de memoria durante la ejecución del programa, y el tamaño de la cadena a la que apunta puede cambiar.
 * 
 * 
 Para usar char *frase, debes asignarle memoria antes de almacenar una cadena en ella. Esto se puede hacer 
 asignando memoria estáticamente (usando malloc, calloc, etc.) o asignando memoria a una cadena literal.
En resumen, char frase[100] es un arreglo de caracteres estático con tamaño fijo, mientras 
que char *frase es un puntero a un carácter o a una cadena de caracteres, que puede ser dinámico 
y apuntar a diferentes ubicaciones de memoria.
*/