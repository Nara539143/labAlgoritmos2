#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

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
*/

void absolute(int x, int *y) {
    if(x>=0){
        *y=x;
    }else{
        *y=-x;
    }
}

int main(void) {
    int a=0;
    int res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---

    a=-10;
    absolute(a, &res);
    printf("%d\n", res);
    
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}


/*
c) Para pensar:
¿El parámetro int *y de absolute() es de tipo in, de tipo out o de tipo in/out?
RESPUESTA: es de tipo out

¿Qué tipo de parámetros tiene disponibles  C para sus funciones?
Parámetros in
Parámetros out
Parámetros in/out
RESPUESTA: todos los anteriores, le puedo pasar y devolver valores con punteros, esos son in/out, tambien puedo pasarle 
un puntero en null, eso es out, o puedo declarar variables normales, esas son in


*/

