#include <stdlib.h>
#include <stdio.h>

/*
LENGUAJE DE LA MATERIA QUE DEBO TRADUCIR

proc absolute(in x : int, out y : int)
  if x >= 0 then
    y := x
  else
    y := -x
  fi
end proc

fun main() ret r : int
  var a : int
  a := -10
  absolute(a, res)
  {- supongamos que print() muestra el valor de una variable -}
  print(res)
  {- esta última asignación es análoga a `return EXIT_SUCCESS;` -}
  r := 0
end fun

PREGUNTA:
¿Qué valor se mostraría al ejecutar la  función main() del programa anterior?
RESPUESTA:
10

*/

void absolute(int x, int y) {
    if (x>=0){
        y=x;
    }else{
        y=-x;
    }
}

int main(void) {
    int a=0;
    int res=0;

    a=-10;
    absolute(a, res);
    printf("%d\n", res);

    return EXIT_SUCCESS;
}

/*
¿Qué valor se muestra por pantalla? ¿Coincide con el programa en el lenguaje del teórico? Responder en un comentario al final de abs1.c.
se muestra el valor cero, no coincide con el programa del teorico*/

