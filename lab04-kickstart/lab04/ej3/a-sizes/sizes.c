#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "data.h"

void
print_data(data_t* d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d->name, d->age, d->height);
}

int main(void) {

    data_t* messi = malloc(sizeof(data_t));
    strcpy(messi->name, "Leo Messi");
    messi ->age = 36;
    messi-> height = 169;
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", (long unsigned int) sizeof(messi->name), (long unsigned int) sizeof(messi->age), 
           (long unsigned int) sizeof(messi->height), (long unsigned int) sizeof(*messi));

    printf("¿La suma de los miembros coincide con el total?\n");
    printf("Suma total = %lu\n", 
           (long unsigned int) sizeof(messi->name) + (long unsigned int) sizeof(messi->age) +
           (long unsigned int) sizeof(messi->height));

    printf("name-addres  : %lu \n"
           "age-addres   : %lu \n"
           "height-addres: %lu \n"
           "data_t-addres: %lu \n", (long unsigned int) &(messi->name), (long unsigned int) &(messi->age), 
           (long unsigned int) &(messi->height), (long unsigned int) (messi));

    free(messi);
    messi=NULL;

    

    return EXIT_SUCCESS;
}

/*
¿El tamaño del campo name depende del nombre que contiene? 
para mi no porque se trata de un arreglo fijo*/