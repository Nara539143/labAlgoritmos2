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
    int año, mes, dia, t_media, t_maxima, t_minima, res;
    unsigned int presion, humedad, precipitaciones;

    while(fscanf(file, "%d" " %d" " %d" " %d" " %d" " %d" " %u" " %u" " %u", &año, &mes, &dia, &t_media, &t_maxima, &t_minima, &presion, &humedad, &precipitaciones) == 9){
      if((año > YEARS) || (mes > MONTHS) || (dia > DAYS)){
        fprintf(stderr, "Error: acceso fuera del arreglo\n");
        exit(EXIT_FAILURE);
      }else{
        (weather[año][mes][dia])._average_temp = t_media;
        (weather[año][mes][dia])._max_temp = t_maxima;
        (weather[año][mes][dia])._min_temp = t_minima;
        (weather[año][mes][dia])._pressure = presion;
        (weather[año][mes][dia])._moisture = humedad;
        (weather[año][mes][dia])._rainfall = precipitaciones;

    }
    
    /*
    MANEJOS DE ERRORES QUE ME FALTAN
    la linea una es correcta, la linea dos es correcta, pero la tres es incorrecta, y de ahi en mas siguen correctos
    en ves de guardar hasta la linea dos y ya deberia imprimir un mensaje de error
    idea que se me ocurre: antes de hacer el while contar las lineas, e iterar por cada line for(i=0, i<lineas, i++){fopen ... }
    de esta forma puedo imprimir mensajes de error especificos si una linea es incorrecta. contras: aumenta la complejidad del programa, ya que debo recorrer
    el archivo dos veces, una para contar lineas y una para cargar valores
    
    otro error, el tamaño del arreglo no alcanza para guardar todos los datos
    se soluciona agregando una condicion al while de que la posicion del arreglo debe ser menor al tamaño del arreglo. pero ahi lo que haria seria simplemente cargar una
    menor cantidad de elementos, y a mi me gustaria imprimir un mensaje de error especifico
    otra opcion: agregar un if adentro del while, es codigo un poco mas sucio pero me permite imprimir mensajes de error especificos
    otra opcion, igual que arriba, contar las lineas antes de entrar al while
    
    */

    

    return weather;
}

void weather_to_file(FILE* file, Weather weather){
    fprintf(file, "%d %d %d %u %u %u", weather._average_temp, weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
