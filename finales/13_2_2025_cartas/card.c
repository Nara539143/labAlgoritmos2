#include <stdlib.h>
#include <stdbool.h>

#include <assert.h>

#include "card.h"

struct s_card {                           
    cardnum_t num;
    cardsuit_t suit;
};

/* Una carta es valida si: 
1. es distinto de null, nunca una carta puede ser null
2. tiene un numero valido
3. tiene un palo valido */
bool invrep(card c) {
    bool valid=c!=NULL &&
               ace <= c->num && c->num <= king &&
               (c->suit==spades ||
                c->suit==hearts ||
                c->suit==diamonds ||
                c->suit==clubs);
               ;
    return valid;
}

/* Toma un numero y un palo y con eso crea un card (puntero a la estructura s_card)*/
card card_create(cardnum_t num, cardsuit_t suit) {
    card c=NULL;
    c=malloc(sizeof(struct s_card));
    c->num = num;
    c->suit = suit;
    assert(invrep(c));
    return c;
}

/* Toma una carta valida, libera toda la memoria asociada y devuelve null
El retorno de null sirve para evitar punteros colgantes, si quiero liberar una carta c debo hacer c=card_destroy(c)*/
card card_destroy(card c) {
    assert(invrep(c));
    free(c);
    c=NULL;
    assert(c==NULL);
    return c;
}

/* Toma una card y retorna su color, no modifica card, funcion de consulta */
cardcolor_t card_color(card c) {
    assert(invrep(c));
    return c->suit==hearts || c->suit==diamonds ? red: black;
}

/* Toma una card y retorna su numero, no modifica card, funcion de consulta */
cardnum_t card_number(card c) {
    assert(invrep(c));
    return c->num;
}

/* Toma una card y retorna su palo, no modifica card, funcion de consulta */
cardsuit_t card_suit(card c) {
    assert(invrep(c));
    return c->suit;
}

/* Toma dos card y corrobora si son iguales, no modifica las card, funcion de consulta */
bool card_equals(card c1, card c2) {
    assert(invrep(c1) && invrep(c2));
    return c1->num == c2->num && c1->suit==c2->suit;
}

