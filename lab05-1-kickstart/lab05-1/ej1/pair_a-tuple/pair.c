#include <stdio.h>
#include "pair.h"


//DESC: Creates a new pair with components (x, y)
pair_t pair_new(int x, int y){
    pair_t res;
    res.fst = x;
    res.snd = y;
    return res;
}


//DESC: Returns the first component of p
int pair_first(pair_t p){
    return p.fst;
}


//DESC: Returns the second component of p
int pair_second(pair_t p){
    return p.snd;
}


//DESC: Return a NEW pair with the components of p reversed
pair_t pair_swapped(pair_t p){
    pair_t swapped;
    swapped.fst = p.snd;
    swapped.snd = p.fst;
    return swapped;
}


//DESC: Free memory if its necessary
void pair_destroy(pair_t p){
    (void)p; //es para que el compilador no se queje de set but not used
}


