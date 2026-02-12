/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "weather_table.h"
#include "weather_utils.h"
/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */
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

//IMPRIMIR VALORES DE UN ARREGLO
void printf_array(int a[], int length){
    printf("[");
    for (int i=0; i<(length-1); i++){
        printf("%d ",  a[i]);
    }
    printf("%d]\n", a[length-1]);
}

/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create a table variable */
    WeatherTable table; //es un arreglo [años][meses][dias]

    /* parse the file to fill the table */
    table_from_file(table, filepath);

    /* show the table in the screen */
    //table_dump(table);

    //llamar a temperatura minima historica
    printf("La temperatura minima historica es: %d\n", temperatura_minima_historica (table));

    //mostrar la maxima temperatura maxima de cada año
    int mtm_year[YEARS];
    max_temp_max_from_each_year (table, mtm_year);
    printf("Para cada año entre 1980 y 2016 las mayores temperaturas máximas registradas durante ese año fueron: \n");
    printf_array(mtm_year, YEARS);
    
    //imprimir arreglo con la maxima precipitacion
    int month_max_rainfall[YEARS];
    array_max_rainfall (table, month_max_rainfall);
    printf("La maxima precipitacion mensual fue: \n");
    printf_array(month_max_rainfall, YEARS);

    return EXIT_SUCCESS;
}


















