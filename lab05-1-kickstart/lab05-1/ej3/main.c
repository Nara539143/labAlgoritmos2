/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "list.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Compute average for the list of numbers in file.\n"
           "\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

//Calcula el promedio
float average(list l) {
    //printf("l36\n");
    list aux = copy_list(l);
    //printf("l38\n");
    int sum = 0;
    //printf("l40\n");
    for(int i = 0; i< length(l); i++){
        //printf("l42 - for %d\n", i);
        sum = sum + index(aux, i);
        //printf("l44 - for %d\n", i);
    }
    //printf("l46\n");
    destroy(aux);
    //printf("l48\n");
    float res = sum/length(l);
    //printf("l50\n");
    return res;
}

list array_to_list(int array[], unsigned int length) {
    list l = empty();
    for (unsigned int i = 0u; i < length; ++i) {
        l=addr(l, array[i]);
    }
    return l;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    printf("parse the filepath given in command line arguments\n");
    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    printf("create an array of MAX_SIZE elements\n");
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    printf("parse the file to fill the array and obtain the actual length\n");
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length_v = array_from_file(array, MAX_SIZE, filepath);
    printf("length_v = %d\n", length_v);

    printf("show the array in the screen\n");
    /* show the array in the screen */
    array_dump(array, length_v);

    printf("transform from array to our list type\n");
    /* transform from array to our list type */
    list l = array_to_list(array, length_v);

    //CONTROL, IMPRIMO LOS DATOS DE LA LISTA
    printf("length = %d\n", length(l));

    printf("call the average function\n");
    /* call the average function */
    printf("The average is: %.2f \n", average(l));

    destroy(l);

    return (EXIT_SUCCESS);
}
