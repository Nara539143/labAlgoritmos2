#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

/* que determina si por un lado el valor value es mayor o igual a todos los elementos del 
arreglo arr (que tiene length elementos), por otro lado si es menor o igual a todos los 
elementos del arreglo, también indica si value se encuentra en arr y en caso de 
encontrarse indica en qué posición se lo encontró. Toda esta información es devuelta en
una estructura struct bound_data que tiene la siguiente definición:
Los cuatro campos de la estructura son los siguientes: valor de verdad que indica si el 
valor es mayor o igual a todos los elementos del arreglo (is_upperbound), valor de verdad
que indica si el valor es menor o igual a todos los elementos (is_lowerbound), valor de 
verdad que indica si el elemento existe en el arreglo (exists) y posición donde se 
encontró el elemento (where) */

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    for (unsigned int i=1; i<length; i++) {
        res.is_upperbound = res.is_upperbound && (value > arr[i]);
        res.is_lowerbound = res.is_lowerbound && (value < arr[i]);
        if((value=arr[i])){
            res.exists = true;
            res.where = i;
        }
        
    }

    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    //
    // TODO: COMPLETAR - Pedir entrada al usuario
    //
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    printf("%d", result.is_upperbound); // Imprime 1
    printf("%d", result.is_lowerbound); // Imprime 0
    printf("%u", result.exists);        // Imprime 1
    printf("%u", result.where);         // Imprime 2

    return EXIT_SUCCESS;
}

