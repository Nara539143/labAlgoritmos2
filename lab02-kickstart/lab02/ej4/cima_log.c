#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

//FUNCIONES
int cima_log(int a[], int length);
int cima_log_rec(int a[], int izq, int der, int length);

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
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



int cima_log(int a[], int length) {
    int res = cima_log_rec(a, 0, (length-1), length);
    return res;
}

int cima_log_rec(int a[], int izq, int der, int length){
    int res, mid;
    if(izq==der){
        res=a[izq];
    }else if((izq+1==der) && (a[izq]<a[der])){
        res=a[der];
    }else if ((izq+1==der) && (a[izq]>=a[der])){
        res = a[izq];
    }else{
        mid=(izq+der) / 2;
        //printf("mid=%d\n izq=%d, der=%d, array= ", mid, izq, der);
        //printf_array (a, length);
        if((a[mid-1]<=a[mid]) && (a[mid]<=a[mid+1])){
            res = cima_log_rec(a, mid+1, der, length);
        }else if((a[mid-1]>=a[mid])&&(a[mid]>=a[mid+1])){
            res = cima_log_rec(a, izq, mid-1, length);
        }else{
            res=a[mid];
        }
    }
    return res;
}

