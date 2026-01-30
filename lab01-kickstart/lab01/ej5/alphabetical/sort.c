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
    printf("LINEA 17 sort.c\n");

    while(i<=j){
        printf("LINEA 20 sort.c\n");
        if(goes_before(a[i], a[ppiv])){
            ++i;
        }else if(goes_before(a[ppiv], a[j])){
            --j;
        }else if (fstring_less(a[ppiv], a[i]) && fstring_less(a[j], a[ppiv])){
            swap(a,i,j);
            ++i;
            --j;
        }
        printf("LINEA 30 sort.c\n");
    }
    swap(a,ppiv,j);
    ppiv=j;
    printf("LINEA 34 sort.c\n");
    return ppiv;
}

/*
do i  ≤ j → if 	a[i]  ≤ a[ppiv] 	→ i:=i+1
			a[j] ≥ a[ppiv]	→ j:=j-1
			a[i] > a[ppiv] ∧ a[j] < a[ppiv] → 	swap(a,i,j)
								i:=i+1
								j:=j-1
		      fi


*/

static void quick_sort_rec(fixstring a[], int izq, int der, unsigned int length) {
    int ppiv;
    printf("LINEA 51 sort.c\n");
    printf("LINEA 52Cder=%d, izq=%d\n", der, izq);
    if((der)>(izq)){
    printf("LINEA 54 der=%d, izq=%d\n", der, izq);
        //imprimo el y los arreglo antes de la llamada a partition (modifico los parametros de la funcion para tener el length)
        printf("El arreglo antes de la llamada a partition es: ");
        array_dump(a, length);
        printf("izq=%d\tder=%d\n", izq, der); //no puedo imprimir ppiv porque no esta inicializada 

        ppiv=partition(a,izq,der);
        printf("LINEA 61 sort.c\n");

        //imprimo el y los arreglo despues de la llamada a partition
        printf("El arreglo despues de la llamada a partition es: ");
        array_dump(a, length);
        printf("izq=%d\tder=%d\tppiv=%d\n", izq, der, ppiv); 

        quick_sort_rec(a, izq, ppiv-1, length);
        quick_sort_rec(a, ppiv+1, der, length);
    }

}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, length);
}



/*
OBSERVACION IMPORTANTE: unsigned int es peligroso para limites, ya que el -1 de unsigned int es el maximo valor posible, por 
lo que no corta nunca, por eso se me estaba generando un segmentation fault, conviene mas usar int para limites
*/