#include <stdio.h>
#include "pair.h"


//DESC: Creates a new pair with components (x, y)
pair_t pair_new(int x, int y){
    pair_t res;
    (res.values)[0] = x;
    (res.values)[1] = y;
    return res;
}


//DESC: Returns the first component of p
int pair_first(pair_t p){
    return (p.values)[0];
}

//DESC: Returns the second component of p
int pair_second(pair_t p){
    return (p.values)[1];
}


//DESC: Return a NEW pair with the components of p reversed
pair_t pair_swapped(pair_t p){
    pair_t swapped;
    (swapped.values)[0]=(p.values)[1];
    (swapped.values)[1]=(p.values)[0];
    return swapped;
}


//DESC: Free memory if its necessary
void pair_destroy(pair_t p){
    (void)p;
}

/*
Copiar el archivo main.c del apartado anterior al directorio pair_b-array y compilar. 
¿Por qué falla?
Porque el main no respeta la abstraccion, deberia haber impreso usando las funciones pair_first y pair_second

Hacer las modificaciones necesarias en main.c para que compile.
voy a modificarlo para que respete la abstraccion

¿El diseño del TAD logra encapsulamiento? ¿Por qué sí? ¿Por qué no?
Si logra, el error estaba en la implementacion del main
*/