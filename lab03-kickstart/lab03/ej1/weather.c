/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

/*
Toma un archivo con el siguiente formato:
Año - mes - dia - media - máxima - mínima - presión atmosférica - humedad - precipitaciones

y carga todos los valores de ese archivo en un arreglo 
typedef Weather WeatherTable [YEARS][MONTHS][DAYS];

cada lugar del arreglo esta ocupado por un struct
typedef struct _weather
{
    int _average_temp;
    int _max_temp;
    int _min_temp;
    unsigned int _pressure;
    unsigned int _moisture;
    unsigned int _rainfall;
} Weather;

cosas que tengo que hacer:

1. guardar cada cosa en una variable con fopen
2. ir cargando en el arreglo



*/

Weather weather_from_file(FILE* file){ //un puntero a una variable de tipo FILE llamado file (es el contenido de un archivo)
    Weather weather;
    if(file == NULL){ //manejo de errores, aunque podria ponerlo como PRE tambien
      fprintf(stderr, "El archivo no es valido"); //imprimo por la salida de errores mensaje de error
      exit(EXIT_FAILURE); //aborto el programa
    }
    int res;
    res = fscanf(file, " %d %d %d %u %u %u ", &weather._average_temp, &weather._max_temp, &weather._min_temp, &weather._pressure, &weather._moisture, &weather._rainfall);

    if(res != 6){
      fprintf(stderr, "Error: linea invalida\n");
      exit(EXIT_FAILURE);
    }

    return weather;
}

void weather_to_file(FILE* file, Weather weather){
    fprintf(file, "%d %d %d %u %u %u", weather._average_temp, weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
