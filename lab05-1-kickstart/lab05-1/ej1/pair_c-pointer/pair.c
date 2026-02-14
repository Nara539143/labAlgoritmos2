#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pair.h"

//typedef struct s_pair_t * pair_t; //pair_t es un puntero a un struct (fst,snd)


//DESC: Creates a new pair with components (x, y)
pair_t pair_new(int x, int y){
    pair_t res;
    res = malloc(sizeof(struct s_pair_t));
    if(res==NULL){
        fprintf(stderr, "Error al reservar memoria\n"); 
        return (NULL);
    }
    res -> fst = x;
    res -> snd = y;
    return res;
}


//DESC: Returns the first component of p
//PRE: p != NULL
int pair_first(pair_t p){
    assert(p!=NULL);
    return (p -> fst);
    
}


//DESC: Returns the second component of p
//PRE: p != NULL
int pair_second(pair_t p){
    assert(p!=NULL);
    return (p -> snd);
}

//DESC: Return a NEW pair with the components of p reversed
//PRE: p != NULL
pair_t pair_swapped(pair_t p){
    assert(p!=NULL);
    pair_t res;
    res = malloc(sizeof(struct s_pair_t));
    if(res==NULL){
        fprintf(stderr, "Error al reservar memoria\n"); 
        return (NULL);
    }
    res -> fst = p -> snd;
    res -> snd = p -> fst;
    return res;
}


//DESC: Free memory if its necessary
void pair_destroy(pair_t p){
    free(p);
}


/*¿La implementación logra encapsulamiento? ¿Por qué sí? ¿Por qué no?
si logra, pero otra vez main no respeta abstraccion*/