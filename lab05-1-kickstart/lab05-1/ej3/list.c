#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"



struct list_ {
    struct list_ * next;
    int elem;
};


//crea una lista vacía
list empty(){
    return NULL;
}

//agrega el elemento e al comienzo de la lista l
list addl (int e, list l){
    list first = malloc(sizeof(struct list_));
    if(first==NULL){
        fprintf(stderr, "Error al reservar memoria\n");
    }
    first -> elem = e;
    first -> next = l;
    l=NULL;
    return first;
}

//Libera memoria en caso que sea necesario
void destroy (list l){
    list aux = NULL;
    while(l!=NULL){
        aux=l;
        l= (l->next);
        free(aux);
    }
}

//Devuelve True si l es vacía
bool is_empty(list l){
    return (l==NULL);
}

//Devuelve el primer elemento de la lista l
//PRE: not is_empty(l)
int head(list l){
    assert(!(is_empty(l)));
    return (l -> elem);
}

//Elimina el primer elemento de la lista l
//PRE: not is_empty(l)
list tail(list l){
    assert(!(is_empty(l)));
    list aux = l;
    l = (l -> next);
    free(aux);
    return(l);
}

//agrega el elemento e al final de la lista l
list addr (list l, int e){
    list last = malloc(sizeof(struct list_));
    if(last==NULL){
        fprintf(stderr, "Error al reservar memoria\n");
        exit(EXIT_FAILURE);
    }
    last -> elem = e;
    last -> next = NULL;
    if(l==NULL){
        l=last;
    }else{
        list aux = l;
        while((aux->next)!=NULL){
            aux=(aux -> next);
        }
        (aux -> next) = last;
    }
    return l;
}

//Devuelve la cantidad de elementos de la lista l
int length(list l){
    //printf("l86 length \n");
    list aux = l;
    //printf("l88 length \n");
    int length = 0;
    //printf("l90 length \n");
    while (aux != NULL){
        //printf("l92 - while %d length \n", length);
        ++length;
        //printf("l94 - while %d length \n", length);
        aux = (aux -> next);
        //printf("l96 - while %d length \n", length);
    }
    //printf("l98 length \n");
    //printf("length = %d\n", length);
    return length;
}

//Agrega al final de l todos los elementos de l0 en el mismo orden.
list concat(list l, list l0){
    if(l==NULL){
        l=l0;
    }else{
        list aux = l;
        while((aux->next)!=NULL){
            aux=(aux -> next);
        }
        (aux -> next) = l0;
    }
    return l;
}

//Devuelve el n-ésimo elemento de la lista l (asumo empieza a contar desde cero)
//PRE: length(l) > n
int index(list l, int n){
    assert(length(l)>n);
    assert(n >= 0);
    list aux = l;
    while(n!=0){
        aux = (aux ->next);
        --n;
    }
    return (aux -> elem);
}


//Deja en l sólo los primeros n elementos, eliminando el resto
//si n> length(l) devuelve l completo
list take(list l, int n){                     
    list aux = l;
    while(aux !=NULL && n!=0){
        aux = (aux -> next);
        --n;
    }
    destroy(aux);
    return l;
}

//Elimina los primeros n elementos de l
//si n>length(l) devuelve vacio
list drop(list l, int n){
    list aux;
    while(l!=NULL && n!=0){
        aux = l;
        l = (l -> next);
        free(aux);
        --n;
    }
    return l;
}

//Copia todos los elementos de l1 en la nueva lista l2
list copy_list(list l1){
    list l2;
    if(l1 == NULL){
        l2 = NULL;
    }else{
        l2=malloc(sizeof(struct list_));
        if(l2==NULL){
            fprintf(stderr, "Error al reservar memoria\n");
        }
        list aux1, aux2;
        aux2=l2;
        aux1=l1;
        while (aux1 != NULL){
            aux2 -> elem = aux1 -> elem;
            if(aux1 -> next != NULL){
                aux2 -> next = malloc(sizeof(struct list_));
                if(aux2 -> next ==NULL){
                    fprintf(stderr, "Error al reservar memoria\n");
                }
            }else{
                aux2 -> next = NULL;
            }
            aux1 = aux1 -> next;
            aux2 = aux2 -> next;
        }
    }
    return l2;
}