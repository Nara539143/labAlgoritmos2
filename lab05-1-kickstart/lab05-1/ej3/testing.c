#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "list.h"



int main() {
    list l = empty();
    printf("La lista es vacia? deberia ser uno: %d\n", is_empty(l));
    l= addl (1, l);
    l= addl (2, l); //[2,1]
    printf("La lista es vacia? deberia ser cero: %d\n", is_empty(l));
    printf("El primer elemento deberia ser 2: %d\n", head(l));
    l=tail(l);
    printf("El primer elemento deberia ser 1: %d\n", head(l));
    l=addr(2, l); // [1,2]
    printf("El tamaño de la lista deberia ser dos: %d\n", length(l));
    l = concat(l, l); //[1,2,1,2]
    printf("Con index imprimo la lista completa [%d, %d, %d, %d]\n", index(l, 0), index(l, 1), index(l, 2), index(l, 3));

    //VOY POR INDEX



    // destroy

    return (EXIT_SUCCESS);
}
