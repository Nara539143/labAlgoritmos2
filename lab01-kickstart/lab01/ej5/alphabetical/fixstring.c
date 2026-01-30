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
    eq= (eq && (s1[i]=='\0')&&(s2[i]=='\0'));
    return eq;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool lesseq=false;
    bool founded = false;    
    unsigned int i=0;
    while((s1[i]!='\0')&&(s2[i]!='\0') && (!founded)){

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
    if((!founded) && (s1[i]=='\0')){
        lesseq=true;
    }
    return lesseq;
}

bool fstring_less(fixstring s1, fixstring s2){
    bool res;
    res = fstring_less_eq(s1, s2) && !fstring_eq(s1, s2);
    return res;
}

//Sets the string <s1> with the content of <s2>
void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}


