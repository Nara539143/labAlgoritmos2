#include "sorteddeck.h"
#include "card.h"
#include "card_helpers.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <assert.h>

struct s_sdeck {
    unsigned int size;
    unsigned int red_count;
    unsigned int black_count;
    struct s_node *first;
};

struct s_node {
    card c;
    cardcolor_t color;
    struct s_node *next;
};


typedef struct s_node * node_t;

/* Crea un nodo_t con la carta c, debe reservar memoria para el nodo_t, para la carta no, ya que se pasa como puntero, el campo next es null */
static node_t create_node(card c) {
    node_t node = malloc(sizeof(struct s_node)); // reservo espacio
    node -> c = c; //guardo el puntero a s_card
    node -> color = card_color(c); //guardo el color
    node -> next = NULL; 
    return node;
}

/* Toma un puntero a nodo, debe liberar memoria de node_t y de cualquier cosa interna en node_t (card) */
static node_t destroy_node(node_t node) {
    node -> c = card_destroy(node -> c); //libero memoria de la carta
    node -> next = NULL;
    free(node);
    node = NULL;
    assert(node == NULL);
    return node; 
}

/* me traje invrep de carta para controlar que cada carta sea valida*/
static bool invrep_card(card c) {
    bool valid=c!=NULL &&
               ace <= card_number(c) && card_number(c) <= king &&
               (card_suit(c)==spades ||
                card_suit(c)==hearts ||
                card_suit(c)==diamonds ||
                card_suit(c)==clubs);
               ;
    return valid;
}

/* se fija si un nodo es valido, es decir, su carta es valida y el color de la carta coincide con el del nodo*/
static bool invrep_node (node_t node){
    bool valid = invrep_card(node -> c) && (card_color(node ->c) == node -> color); 
    return valid;
}

/* un sdeck es valido si:
1. no es null
2. size es positivo (y voy a permitir maximo 100 cartas, para controlar que como es unsigned int no se me pase)
3. red_count es positivo y menor a size
4. black_count es positivo y menor a size
5. red_count + backcount = size
6. el mazo esta ordenado por color (primero todas rojas y despues todas negras o al revez)
respecto a next puede ser null (si el mazo es vacio), o no serlo (si hay cartas, asi que no hay condicion al respecto)
opcionales (podria incluirlos pero no se si son necesarios)
6. si size= 0 entonces next==NULL;
7. itero sobre cada carta y me fijo que todas sean validas
escribo los primeros por ahora, cualquier cosa despues mejoro
no modifica el estado, funcion de consulta
*/
static bool invrep(sdeck deck) {
    bool valid=false;
    valid = (deck != NULL) && 
            (deck -> size <= 100) &&  //no comparo que sea mayor a cero ya que como es unsigned int es siempre verdadero
            ( deck -> red_count <= deck -> size) && 
            (deck -> black_count <= deck -> size) && 
            (deck -> red_count + deck -> black_count == deck -> size);

    if(deck -> first == NULL || deck -> size == 0u){
        valid = valid && (deck -> first == NULL) && (deck -> size == 0u); //si el mazo es vacio el puntero debe ser null y size debe ser 0
    }else{
        //ahora, si el mazo no esta vacio debo ver que este ordenado y que cada carta sea valida
        node_t aux = deck -> first;
        cardcolor_t first_part = aux -> color;
        while (aux -> next != NULL && aux->color == first_part){
            valid = valid && invrep_node(aux);
            aux = aux -> next;
        }
        while (aux -> next != NULL && aux->color != first_part){
            valid = valid && invrep_node(aux);
            aux = aux -> next;
        }
        valid = valid && (aux -> next == NULL);
    }
    return valid;
}

/* Devuelve un mazo vacio, es decir, un puntero a una estructura s_deck inicializada en valores para mazo vacio, debe reservar memoria*/
sdeck sorteddeck_create(void) {
    sdeck deck = malloc(sizeof(struct s_sdeck));
    deck -> size = 0u;
    deck -> red_count = 0u;
    deck -> black_count = 0u;
    deck->first = NULL;
    assert(invrep(deck));
    return deck;
}

/* Destruye el mazo deck liberando toda la memoria utilizada por la instancia
debo liberar memoria de la estructura en si, y memoria de todos los nodos (debo iterar para esto) */
sdeck sorteddeck_destroy(sdeck deck) {
    assert(invrep(deck));
    if(deck -> first == NULL){
        free(deck);
        deck=NULL;
    }else{
        node_t aux1 = deck -> first;
        node_t aux2 = deck -> first;
        while(aux1->next != NULL){
            aux1 = aux1 -> next;
            aux2 = destroy_node(aux2);
            aux2 = aux1;
        }
        aux1=destroy_node(aux1);
        aux2=NULL;
        free(deck);
        deck=NULL;
    }
    return deck;
}

/* Agrega una carta al mazo actualizando todas las areas necesarias.
debe agregarla respetando la invariante de representacion*/

sdeck sorteddeck_add(sdeck deck, card c) {
    assert(invrep(deck));
    deck -> size = deck -> size +1; //actualizo campo size
    if(card_color(c) == red){ //actualizo contador de colores
        deck -> red_count = deck -> red_count + 1;
    }else if(card_color(c) == black){
        deck -> black_count = deck -> black_count + 1;
    }
    //me falta agregar el nodo a la lista de nodos nomas:
    node_t new_node = create_node(c);
    if(deck -> first == NULL){ //si el mazo esta vacio agrego la carta directamente
        deck -> first = new_node;
    }else if(deck -> first -> next == NULL){ //si el mazo tiene una sola carta tambien agrego la carta directamente
        deck -> first -> next = new_node;
    }else{ //si el mazo tiene mas de una carta si debo encargarme de que queden ordenadas
        node_t aux1 = deck->first;
        node_t aux2 = NULL;
        while(aux1 -> color != new_node -> color && aux1 -> next != NULL){
            aux1 = aux1 -> next;
        }
        aux2 = aux1 -> next;
        aux1 -> next = new_node;
        new_node -> next = aux2;
        aux1 = NULL;
        aux2 = NULL;
    }
    assert(invrep(deck) && !sorteddeck_is_empty(deck));
    return deck;
}


/*
toma un mazo y elimina una card c, liberando memoria necesaria y actualizando todos los campos correspondientes
PRE: el mazo no debe estar vacio

CASOS:
tengo que eliminar la primera carta
tengo que eliminar (o no), cualquier otra carta
*/
sdeck sorteddeck_remove(sdeck deck, card c) {
    assert(invrep(deck));
    assert(invrep_card(c));
    assert(! sorteddeck_is_empty(deck));

    node_t aux1, aux2;
    unsigned int tam_inicial = deck -> size;
    
    if(card_equals(deck->first->c, c)){ //CASO: tengo que eliminar la primera carta
        aux1=deck->first;
        deck->first = deck -> first -> next;
        aux1 = destroy_node(aux1);
        deck->size = deck -> size -1; //actualizo contador general
        if(card_color(c) == red){ //actualizo contador de colores
            deck -> red_count = deck -> red_count -1;
        }else if(card_color(c) == black){
            deck -> black_count = deck -> black_count -1;
        }
    }else{//CASO: no tengo que eliminar la primera carta (puedo o no tener que eliminar una de las siguientes)
        aux1=deck->first;
        while(aux1->next !=NULL && deck -> size == tam_inicial){
            if(card_equals(aux1 -> next->c, c)){
                aux2=aux1->next->next;
                aux1 -> next = destroy_node(aux1->next);
                aux1->next = aux2;
                deck->size = deck -> size -1;
                if(card_color(c) == red){ //actualizo contador de colores
                    deck -> red_count = deck -> red_count -1;
                }else if(card_color(c) == black){
                    deck -> black_count = deck -> black_count -1;
                }
            }
            aux1=aux1->next;
        }
    }
    aux1=NULL;
    aux2=NULL;
    
    assert(invrep(deck));
    return deck;
}

/* elimina la carta que esta al principio del mazo, libera la memoria necesaria y actualiza los campos necesarios 
PREE: el mazo no esta vacio*/

sdeck sorteddeck_popfirst(sdeck deck) {
    assert(invrep(deck));
    assert(! sorteddeck_is_empty(deck));
    
    node_t aux;
    deck->size = deck -> size -1; //actualizo contador general
    if(deck->first->color == red){ //actualizo contador de colores
        deck -> red_count = deck -> red_count -1;
    }else if(deck->first->color == black){
        deck -> black_count = deck -> black_count -1;
    }

    aux = deck -> first -> next;
    deck-> first = destroy_node(deck -> first);
    deck->first = aux;
    aux=NULL;
    
    return deck;
 }

/* retorna la primera carta, no hace una copia, no reserva memoria, y no modifica sdeck, es una funcion de consulta*/
card sorteddeck_first(sdeck deck) {
    assert(invrep(deck));
    return (deck -> first -> c);
}

/* retorna el tamaño del mazo, no reserva memoria, y no modifica sdeck, es una funcion de consulta*/
unsigned int sorteddeck_size(sdeck deck) {
    assert(invrep(deck));
    return(deck->size);
}

/* retorna la cantidad de cartas rojas, no reserva memoria, y no modifica sdeck, es una funcion de consulta*/
unsigned int sorteddeck_redcount(sdeck deck) {
    assert(invrep(deck));
    return (deck -> red_count);
}

/* retorna la cantidad de cartas negras, no reserva memoria, y no modifica sdeck, es una funcion de consulta*/
unsigned int sorteddeck_blackcount(sdeck deck) {
    assert(invrep(deck));
    return (deck -> black_count);
}

/* retorna si el mazo es vacio o no, no reserva memoria, y no modifica sdeck, es una funcion de consulta*/
bool sorteddeck_is_empty(sdeck deck) {
    assert(invrep(deck));
    return(deck -> size == 0);
}



/* Devuelve un arreglo en memoria dinámica que contiene todas las cartas de deck. Las cartas almacenadas en el arreglo deben ser copias de las
cartas que se encuentran en deck. 
No modifica deck 
se trata de un arreglo de punteros a card, necesito una funcion copy_card, pero creo que no la puedo agregar sin romper abstraccion, asi que hago a mano*/

card* sorteddeck_to_array(sdeck deck) {
    assert(invrep(deck));
    card* c;
    card elem;
    /* card* es un puntero al primer elemento de un arreglo de cartas, asi que voy a rellenar el arreglo */
    if(sorteddeck_is_empty(deck)){
        c = NULL;
    }else{
        node_t aux = deck -> first;
        c = malloc(deck->size * sizeof(card));;
        for(unsigned int i=0; i< deck -> size; i++){
            //copio la carta
            elem = card_create(card_number(aux -> c), card_suit(aux -> c));
            //guardo la carta en el arreglo
            c[i] = elem;
            //paso al siguiente nodo
            aux = aux -> next;
        }
        aux = NULL;
    }
    return c;
}

void sorteddeck_dump(sdeck deck) {
    assert(invrep(deck));
    node_t node = deck->first;
    if (node != NULL) {
        card_dump(node->c);
        while (node->next != NULL) {
            printf(" -> ");
            node = node->next;
            card_dump(node->c);
        }
        printf("\n");
    } else {
        printf("<>\n");
    }
}

