/*
PRIMERO ENTENDAMOS PARTE A PARTE

*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 20

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s)) //no entiendo esta linea
// es tamaño total / tamaño de un elemento = tamaño del arreglo

int main(void) {
    char user_input[MAX_LENGTH]; //declara un arreglo, llamado user_input de caracteres
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.'}; //declara un arreglo y le asigna caracteres
    char *filtered=NULL; //declara un puntero a un char e inicializa en null
    char *aux = NULL;

    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH);
    scanf("%s", user_input); //guarda el string ingresado por el usuario por stdin
    filtered = string_filter(user_input, ignore_chars[0]); //usa la funcion para filtrar los caracteres, devuelve 
                                                           //un puntero, filtra solo el ' '

    for (unsigned int i=0; i < SIZEOF_ARRAY(ignore_chars); i++) { //no entiendo el limite de este for pero porque no 
                                                                  // entiendo la linea 10
        aux = filtered;
        filtered = string_filter(filtered, ignore_chars[i]); //aca itera para filtrar los demas caracteres, 
        free(aux);
        aux = NULL; 
        // itera sobre ignore_chars, pero porque inicializa i en 0 si ya ignoro el caracter 0 arriba
        
        /*YA ENTENDI 
        cada llamada a la funcion string_filter hace un malloc nuevo, y devuelve un puntero NUEVO con la informacion
        asi que deberia guardar el puntero en una variable auxiliar y liberarla despues de cada llamada*/
    }

    printf("El texto:\n\n"
            "\"%s\" \n\n" //imprime la cadea completa
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es"); //imprime la rta
    free(filtered);
    filtered = NULL;
    return EXIT_SUCCESS;
}

