#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};


//Create a new counter with initial value. Allocates new memory.
//Being c the returned counter, counter_is_init(c) should be true.
counter counter_init(void) {
    counter c = malloc(sizeof(struct _counter));
    if(c==NULL){
        fprintf(stderr, "Error al reservar memoria\n");
        return(NULL);
    }
    c -> count = 0u;
    assert(counter_is_init(c));
    return c;
}

//Increments the counter c.
void counter_inc(counter c) {
    assert(c != NULL);
    c -> count = (c -> count) + 1;

}

//Return whether the counter c has the initial value.
bool counter_is_init(counter c) {
    assert(c != NULL);
    return ((c -> count)==0u);
}

//Decrements the counter c.
//PRECONDITION: !counter_is_init(c)
void counter_dec(counter c) {
    assert(c != NULL);
    assert(!counter_is_init(c));
    c -> count = (c -> count) -1;
}

//Makes a copy of counter c. Allocates new memory.
counter counter_copy(counter c) {
    assert(c != NULL);
    counter res = malloc(sizeof(struct _counter));
    if(res==NULL){
        fprintf(stderr, "Error al reservar memoria\n");
        return(NULL);
    }
    res -> count = c -> count;
    return res;
}

//Frees memory for c.
void counter_destroy(counter c) {
    free(c);
}
