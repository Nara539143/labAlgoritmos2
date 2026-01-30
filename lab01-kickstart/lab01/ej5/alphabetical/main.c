/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "fixstring.h"
#include "sort_helpers.h"
#include "sort.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 1000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
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

    return result;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    printf("LINEA 49 main.c\n");
    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    printf("LINEA 53 main.c\n");
    /* create an array of MAX_SIZE elements */
    fixstring array[MAX_SIZE];

    printf("LINEA 57 main.c\n");
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    printf("LINEA 61 main.c\n");
    /* create a copy of the array, to do some checks later */
    fixstring copy[MAX_SIZE];
    array_copy(copy, array, length);

    printf("LINEA 66 main.c\n");
    quick_sort(array, length);

    printf("LINEA 69 main.c\n");
    /* show the ordered array in the screen */
    array_dump(array, length);

    printf("LINEA 73 main.c\n");
    /* check if it is sorted */
    assert(array_is_sorted(array, length));

    printf("LINEA 77 main.c\n");
    /* check if it is a permutation of original */
    assert(array_is_permutation_of(copy, array, length));
    return EXIT_SUCCESS;
}
