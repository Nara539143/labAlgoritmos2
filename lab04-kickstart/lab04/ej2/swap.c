/*
IMPLEMENTAR:
proc swap(in/out a : int, in/out b : int)
    var aux : int
    aux := a
    a := b
    b := aux 
end proc
fun main() ret r : int
  var x, y : int
  x := 6
  y := 4
  print(x, y)
  swap(x, y)
  print(x, y)
  r := 0
end fun

*/

#include <stdio.h>
#include <stdlib.h>

void swap (int* a, int* b){
    int* aux = malloc(sizeof(*aux));
    (*aux)=(*a);
    (*a)=(*b);
    (*b)=(*aux);
    free(aux);
    aux = NULL;
}

int main(){
    int x, y;
    x=6;
    y=4;
    printf("%d, %d\n", x, y);
    swap(&x, &y);
    printf("%d, %d\n", x, y);
    return(EXIT_SUCCESS); 
}