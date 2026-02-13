/*
b) En el directorio static se encuentra el programa del Laboratorio 1 que carga en un arreglo en memoria estática desde un archivo. Completar en la carpeta dynamic la función array_from_file() de array_helpers.c:
int *array_from_file(const char *filepath, size_t *length);

que carga los datos del archivo filepath devolviendo un puntero a memoria dinámica con los elementos del arreglo y dejando en *length la cantidad de elementos leídos. Completar además en main.c el código necesario para liberar la memoria utilizada por el arreglo. Probar el programa con todos los archivos de la carpeta input para asegurar el correcto funcionamiento (notar que la versión en static no funciona para todos los archivos de la carpeta input).

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


void array_dump(int a[], size_t length) { //size_t es un entero para representar tamaños en memoria, viene en stdlib.h
    fprintf(stdout, "length: %lu\n", length);
    fprintf(stdout, "[ ");
    for (size_t i = 0u; i < length; ++i) {
        fprintf(stdout, "%d", a[i]);
        if (i < length - 1) {
            fprintf(stdout, ", ");
        }
    }
    fprintf(stdout, "]\n");
}


int * array_from_file(const char *filepath, size_t *length) {
    FILE *file = NULL; //declaro un puntero a un archivo
    file = fopen(filepath, "r"); //abro el archivo con el modo "r" y lo guardo en file


    /*
    dudas hasta ahora:
    que se guarda en file? un puntero al archivo? el archivo entero?
    que es la variable FILE? como funciona? que contiene
    fopen devuelve null si falla la apertura 
    
    FILE es una estructura opaca, fopen devuelve un puntero a esa estructura que contiene toda la informacion
    del archivo */

    //MANEJO DE ERRORES: 
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    //QUE REPRESENTA CADA VARIABLE? 
    unsigned int i = 0u; //se usa para recorrer los elementos del arreglo
    unsigned int size = 0u; //guarda el tamaño del arreglo que obtiene desde la carpeta input
    int res = 0; //lee la cantidad de argumentos que toma fscanf, debe ser uno solo si el formato es correcto

    res = fscanf(file, " %u ", &size); //asigno res y size

    //MANEJO DE ERRORES
    if (res != 1) {
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }

    //int *array=NULL; //declaro un puntero a un entero
    //para mi en vez de la linea de arriba deberia ir esta linea de abajo:

    int *array = malloc(sizeof(int)*size); 

    //tengo que ir recorriendo los elementos del arreglo input, guardandolos en *array
    //*length=0; //mi idea es ir aumentandolo, mi duda: fscanf devuelve la cantidad de argumentos que lee, 
    // podria tambien asignar asi directamente? o que pasa es que no los leo todos juntos, sino que en cada vuelta 
    // del cilo leo uno, entonces por ese lado se complica
    //mensa, esto ya esta programado abajo en el while 
    /*
    for (int k=0; k<size; k++){
        fscanf(file, " %u ", (*array)[k]);
        *length=*length + 1; //son los elementos leidos, no necesariamente el tamaño que el arreglo dice tener
        //tal como dice el enunciado

        //siento que deberia agregar algun manejo de errores aca

    }
    *//*aca me perdi al 100%, no deberia ser un puntero a un arreglo de enteros? 
    no deberia en vez de signarle null asignarle malloc(sizeof(a[size]))? 
    como que cambiar el valor de length? el tamaño del arreglo no esta en size?
    despues deberia recorrer el arreglo de input con fscanf e ir guardando cada elemento en el arreglo particular de 
    aca*/
    *length = size;


    //
    // COMPLETAR: - Reservar memoria para array
    //            - Cambiar el valor de *length para que contenga el tamaño del
    //              arreglo.
    //
    if (size > 0 && array == NULL) {
        fprintf(stderr, "Not enough memory\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        res = fscanf(file," %d ", &(array[i])); //otra duda aca, no entiendo como lo guarda en el arreglo, en 
        // general no entiendo la idea entre puntero al arreglo y arreglo en si, no puedo visualizar la estructura, 
        // no es tanto duda de codigo en si sino de como funcionan las estructuras
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
       ++i;
    }
    fclose(file);
    return array;
}

