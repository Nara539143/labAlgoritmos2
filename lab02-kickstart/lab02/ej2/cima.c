#include <stdio.h>
#include <stdbool.h>
#include "cima.h"
#define N 5 //tam arreglo

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */

bool tiene_cima(int a[], int length) {
    int i=0;
	while(i<(length-1) && a[i] <= a[i+1]){
		++i;
	}
	while(i<(length-1) && a[i] >= a[i+1]){
		++i;
	}
	return (i==(length-1));

}

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
int cima(int a[], int length) {
	int i=0;
	while(i<(length-1) && a[i] <= a[i+1]){
		//printf("%d) \ti=%d, array= ", i+1, i);
		//printf_array (a, length);
		++i;
	}
	return (a[i]);
}

/*
fun tiene_cima (array a of Int, length:int) ret res:bool
	int i=0
	while(i<(length-1) && a[i]  ≤ a[i+1]){
		++i;
	}
	while(i<(length-1) && a[i]   ≤ a[i+1]){
		++i;
	}
	res = (i==length);
}

fun encontrar_cima (array a of Int, length:int) ret res:int
	int i=0
	while(i<(length-1) && a[i]  ≤ a[i+1]){
		++i;
	}
	res = a[i];
}

*/

void printf_array (int a[N], int length){
    printf("[");
    for (int i=0; i<length; ++i){
        if(i!=(length-1)){
            printf("%d, ", a[i]);
        }else{
            printf("%d]\n", a[i]);
        }
    }
}
