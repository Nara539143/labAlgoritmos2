#include "weather_table.h" //si los incluyo aca no los tengo que incluir en el .c no?
#include "weather.h"

int temperatura_minima_historica (WeatherTable weather_table);

void max_temp_max_from_each_year (WeatherTable weather_table, int mtm_year[YEARS]);

void array_max_rainfall (WeatherTable weather_table, int month_max_rainfall[YEARS]);