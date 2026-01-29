#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i=0;
    unsigned int length =0;
    while (s[i]!='\0'){
        ++length;
        ++i;
    }
    return length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int i=0;
    bool eq = true;
    while((s1[i]!='\0')&&(s2[i]!='\0')){
        eq=eq && (s1[i]==s2[i]);
        ++i;
    }
    eq=eq && (s1[i]=='\0')&&(s2[i]=='\0');
    return eq;
}

/* como comparo yo intuitivamente si entre dos listas una es mas chica que otra?
si de dos elementos, uno es mayor que otro, o es menor que otro ya tengo la informacion.
no tengo la informacion si son iguales, en ese caso paso a ver el siguiente.
y si llego al final y resulta que todos eran iguales me fijo si la primera es menor en tamaño a la segunda
*/

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool lesseq=false;
    bool founded = false;    
    unsigned int i=0;
    while((s1[i]!='\0')&&(s2[i]!='\0') && !founded){

        if(s1[i]>s2[i]){
            lesseq = false;
            founded = true;
        }else if (s1[i]==s2[i]){
            ++i;
        }else if(s1[i]<s2[i]){
            lesseq=true;
            founded=true;
        }
    }
    if(!founded && (s1[i]=='\0')){
        lesseq=true;
    }
    return lesseq;
   
}

