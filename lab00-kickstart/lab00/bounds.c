#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

/* que determina si por un lado el valor value es mayor o igual a todos los elementos del 
arreglo arr (que tiene length elementos), por otro lado si es menor o igual a todos los 
elementos del arreglo, también indica si value se encuentra en arr y en caso de 
encontrarse indica en qué posición se lo encontró. Toda esta información es devuelta en
una estructura struct bound_data que tiene la siguiente definición:
Los cuatro campos de la estructura son los siguientes: valor de verdad que indica si el 
valor es mayor o igual a todos los elementos del arreglo (is_upperbound), valor de verdad
que indica si el valor es menor o igual a todos los elementos (is_lowerbound), valor de 
verdad que indica si el elemento existe en el arreglo (exists) y posición donde se 
encontró el elemento (where) */

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    //printf("DEBUG: acabo de inicializar el struct, los valores son: \n is_upperbound=%d\n is_lowerbound=%d\n exists=%d\n", res.is_upperbound, res.is_lowerbound, res.exists);
    for (unsigned int i=0; i<length; i++) {
        res.is_upperbound = res.is_upperbound && (value > arr[i]);
        res.is_lowerbound = res.is_lowerbound && (value < arr[i]);
        if((value==arr[i])){
            res.exists = true;
            res.where = i;
        }
        //printf("DEBUG: esta es la vuelta %d del ciclo, los valores son: \n is_upperbound=%d\n is_lowerbound=%d\n exists=%d\n", i, res.is_upperbound, res.is_lowerbound, res.exists);
        
    }

    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    printf("Se le va a solicitar el ingreso de %d elementos para el arreglo: \n", ARRAY_SIZE);
    for(unsigned int i = 0; i<ARRAY_SIZE; i++){
        printf("Ingrese el elemento %d: ", i+1);
        scanf("%d",&a[i]);
    }
    printf("Ingrese un valor para comparar con los elementos del arreglo: ");
    scanf("%d", &value);
    //printf("DEBUG: el valor de value es %d\n", value);
    
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    //printf("DEBUG: estoy por imprimir los valores, quedaron: \n is_upperbound=%d\n is_lowerbound=%d\n exists=%d\n", result.is_upperbound, result.is_lowerbound, result.exists);

    if(result.is_upperbound){
        printf("%d es cota superior\n", value);
    }else{
        printf("%d no es cota superior\n", value);
    };
    if(result.is_lowerbound){
        printf("%d es cota inferior\n", value);
    }else{
        printf("%d no es cota inferior\n", value);
    };
    if(result.exists){
        printf("El valor %d se encuentra en la posicion %d del arreglo\n", value, result.where);
    }else{
        printf("%d no se encuentra en el arreglo\n", value);
    };

    return EXIT_SUCCESS;
}

/*
Una vez que se obtienen los elementos, se le debe pedir al usuario un valor para 
verificar con check_bound(). La salida por pantalla debe indicar si el valor que ingresó 
el usuario es cota superior, cota inferior, mínimo o máximo. Solo en caso de ser mínimo 
o máximo (esto significa que el valor se encuentra en el arreglo) mostrar por pantalla 
la posición donde se encontró el elemento
*/