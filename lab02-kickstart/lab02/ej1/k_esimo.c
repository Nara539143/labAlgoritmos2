#include <stdbool.h>
#include "k_esimo.h"
#include <stdio.h>
#define N 5 //tamaño del arreglo

// FUNCIONES INTERNAS DEL MÓDULO:
int partition(int a[], int izq, int der);
bool goes_before(int x, int y);
void swap(int a[], int i, int j);
void printf_array (int a[N], int length);

/**
 * @brief K-esimo elemento mas chico del arreglo a.
 *
 * Devuelve el elemento del arreglo `a` que quedaría en la celda `a[k]` si el
 * arreglo estuviera ordenado. La función puede modificar el arreglo.
 * Dicho de otra forma, devuelve el k-esimo elemento mas chico del arreglo a.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 * @param k Posicion dentro del arreglo si estuviera ordenado.
 */


int k_esimo_rec (int a[], int lft, int rgt, int k){
    int ppiv, res;
    if(rgt>lft){
        //printf("Antes de elegir ppiv\n");
        //printf_array(a,N);
        //printf("lft=%d, rgt=%d\n", lft, rgt);
        ppiv=partition(a,lft,rgt);
        //printf("Elegi con partition ppiv=%d\n", ppiv);
        if (k==ppiv){
            res=a[ppiv];
        }else if(k>ppiv){
            res=k_esimo_rec(a,ppiv+1,rgt,k);
        }else if(k<ppiv){
            res=k_esimo_rec(a,lft,ppiv-1,k);
        }
    }else if(rgt==lft){
        res=a[rgt];
    }
    return res;

}

int k_esimo(int a[], int length, int k) {
    return (k_esimo_rec(a, 0, (length-1), k));
}

int partition(int a[], int izq, int der) {
    int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    //printf("En partition\n");
    //printf_array(a,N);
    //printf("lft=%d, rgt=%d, i=%d, j=%d, ppiv=%d\n", izq, der, i, j, ppiv);
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i = i + 1;
            //printf_array(a,N);
            //printf("lft=%d, rgt=%d, i=%d, j=%d, ppiv=%d\n", izq, der, i, j, ppiv);
        } else if (goes_before(a[ppiv], a[j])) {
            j = j - 1;
            //printf_array(a,N);
            //printf("lft=%d, rgt=%d, i=%d, j=%d, ppiv=%d\n", izq, der, i, j, ppiv);
        } else {
            swap(a, i, j);
            //printf_array(a,N);
            //printf("lft=%d, rgt=%d, i=%d, j=%d, ppiv=%d\n", izq, der, i, j, ppiv);
        }
    }

    swap(a, ppiv, j);
    ppiv = j;
    //printf_array(a,N);
    //printf("lft=%d, rgt=%d, i=%d, j=%d, ppiv=%d\n", izq, der, i, j, ppiv);

    return ppiv;
}

bool goes_before(int x, int y) {
    return x <= y;
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

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