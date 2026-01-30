#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], int izq, int der) {
    int i, j, ppiv;
    ppiv=izq;
    i=izq+1;
    j=der;

    while(i<=j){
        if(goes_before(a[i], a[ppiv])){
            ++i;
        }else if(goes_before(a[ppiv], a[j])){
            --j;
        }else {
            swap(a,i,j);
            ++i;
            --j;
        }
    }
    swap(a,ppiv,j);
    ppiv=j;
    return ppiv;
}

static void quick_sort_rec(fixstring a[], int izq, int der) {
    int ppiv;
    if((der)>(izq)){
        /*imprimo el y los arreglo antes de la llamada a partition (modifico los parametros de la funcion para tener el length)
        printf("El arreglo antes de la llamada a partition es: ");
        array_dump(a, length);
        printf("izq=%d\tder=%d\n", izq, der); //no puedo imprimir ppiv porque no esta inicializada */

        ppiv=partition(a,izq,der);

        /*imprimo el y los arreglo despues de la llamada a partition
        printf("El arreglo despues de la llamada a partition es: ");
        array_dump(a, length);
        printf("izq=%d\tder=%d\tppiv=%d\n", izq, der, ppiv); */

        quick_sort_rec(a, izq, ppiv-1);
        quick_sort_rec(a, ppiv+1, der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


