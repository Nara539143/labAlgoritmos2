#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "strfuncs.h"

size_t string_length(const char *str){
    //quiero recorrer la cadena hasta llegar a '/0'
    size_t length = 0;
    while(str[length]!='\0'){
        ++length;
    }
    return length;
}
/*Calcula la longitud de la cadena apuntada por str*/


char *string_filter(const char *str, char c){
    //voy a hacerlo de una forma que capaz no es la mas optima, pero lo que se me ocurre es:
    // 1. contar cuanto espacio necesito
    // 2. guardar las cosas
    //tengo una mejor idea, guardo todo en una estructura grande y despues modifico
    
    unsigned int i = 0u;
    unsigned int j = 0u;
    char *res = malloc(sizeof(char)*(string_length(str)+1));

    while(str[i]!='\0'){
        if(str[i]!=c){
            res[j]=str[i];
            ++j;
        }
        ++i;
    }
    res[j]='\0';

    res = realloc(res, sizeof(char)*j);

    return res;

}


/*Devuelve una nueva cadena en memoria dinámica que se obtiene tomando los caracteres de str que son distintos del 
caracter c*/

bool string_is_symmetric(const char *str){

    int i = 0;
    int j= (int)string_length(str) - 1;
    bool res = true;

    while(i<j){
        res = res && (str[i]==str[j]);
        i++;
        j--;
    }

    return res;
}
/*Indica si la cadena apuntada por str es simétrica en cuanto que el primer caracter coincide con el último, 
el segundo con el penúltimo, etc; como por ejemplo las cadenas "aba", "abcba", "a", "". */




















