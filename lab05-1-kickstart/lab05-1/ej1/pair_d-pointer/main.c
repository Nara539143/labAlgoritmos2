#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

static
void show_pair(pair_t p) {
    printf("(%d, %d)\n", pair_first(p), pair_second(p));
}

int main(void) { 
    pair_t p, q;

    // Nuevo par p
    p = pair_new(3, 4);

    // Se muestra el par por pantalla
    printf("p = ");
    show_pair(p);

    // Nuevo para q con elementos de p intercambiados
    q = pair_swapped(p);

    // Se vuelve a mostrar p
    printf("p = ");
    show_pair(p);

    // Se muestra q
    printf("q = ");
    show_pair(q);

    // Se destruyen p y q
    pair_destroy(p);
    pair_destroy(q);

    return EXIT_SUCCESS;
}

/*aca me obligo a cambiar el main, sino me tiraba error en tiempo de compilacion
ter$ gcc -Wall -Werror -Wextra -pedantic -std=c99 pair.c main.c -o main
main.c: In function ‘show_pair’:
main.c:7:27: error: invalid use of undefined type ‘struct s_pair_t’
    7 |     printf("(%d, %d)\n", p->fst, p->snd);
      |                           ^~
main.c:7:35: error: invalid use of undefined type ‘struct s_pair_t’
    7 |     printf("(%d, %d)\n", p->fst, p->snd);
      |                                   ^~
nara@nara-IdeaPad-Slim-3-15AMN8:~/Documentos/labAlgoritmos2/lab05-1-kickstart/lab05-1/ej1/pair_d-pointer$ 

Capaz a esto se referia con lo de "logra encapsulamiento", esto me obliga a

*/