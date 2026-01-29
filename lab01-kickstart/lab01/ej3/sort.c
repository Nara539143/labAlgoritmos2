#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int i, j, ppiv;
    ppiv=izq;
    i=izq+1;
    j=der;

    while(i<=j){
        if(!goes_before(a[ppiv], a[i])){
            ++i;
        }else if(!goes_before(a[j], a[ppiv])){
            --j;
        }else{
            swap(a,i,j);
            ++i;
            --j;
        }
    }
    swap(a,ppiv,j);
    ppiv=j;
    return ppiv;
}

/*
CODIGO DE QUICK SORT DE PARTITION DEL TEORICO

proc partition (in/out a:array[1..n] of T, in lft,rgt: nat, out ppiv:nat)
	var i,j: nat
	ppiv:=lft
	i:=lft+1
	j:=rgt
	do i  ≤ j → if 	a[i]  ≤ a[ppiv] 	→ i:=i+1
			a[j] ≥ a[ppiv]	→ j:=j-1
			a[i] > a[ppiv] ∧ a[j] < a[ppiv] → 	swap(a,i,j)
								i:=i+1
								j:=j-1
		      fi
	od
	swap(a,ppiv,j)
	ppiv:=j
end proc

observacion: a<b <=>    goes_before(a,b)
             a<=b <=>   !goes_before(b,a)
             a>b <=>    goes_before(b,a)
             a>=b <=>   !goes_before(a,b)

             ppiv lo tengo que retornar, osea, debo crear la variable y luego retornarla


*/


    /* Needs implementation */

    /* PRECONDITION: 
       0 <= izq < der < length of the array

     Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */

//copio la implementacion hecha en el ejercicio 2
//adapto para imprimir el arreglo antes y despues de cada llamada a partition
static void quick_sort_rec(int a[], unsigned int izq, unsigned int der, unsigned int length) {
    unsigned int ppiv;
    if(der>izq){

        //imprimo el y los arreglo antes de la llamada a partition (modifico los parametros de la funcion para tener el length)
        printf("El arreglo antes de la llamada a partition es: ");
        array_dump(a, length);
        printf("izq=%d\tder=%d\n", izq, der); //no puedo imprimir ppiv porque no esta inicializada

        ppiv=partition(a,izq,der);

        //imprimo el y los arreglo despues de la llamada a partition
        printf("El arreglo despues de la llamada a partition es: ");
        array_dump(a, length);
        printf("izq=%d\tder=%d\tppiv=%d\n", izq, der, ppiv);

        quick_sort_rec(a,izq,ppiv-1, length);
        quick_sort_rec(a,ppiv+1,der, length);
    }

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, length);
}

