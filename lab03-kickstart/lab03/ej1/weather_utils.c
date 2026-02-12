#include <stdio.h>
#include <limits.h>

#include "weather_table.h" //tengo dudas si esto va aca o no
#include "weather.h"
#include "weather_utils.h"

/*
Una función que obtenga la menor temperatura mínima histórica registrada en la ciudad de Córdoba según los datos del arreglo .
osea, debo iterar por cada dia, mes, y año, hasta encontrar el minimo

*/

int temperatura_minima_historica (WeatherTable weather_table){
    int min_hist = INT_MAX;
    for(int i = 0; i<YEARS; i++){
        for(int j=0; j<MONTHS; j++){
            for(int k=0; k<DAYS; k++){
                if(((weather_table[i][j][k])._min_temp)<min_hist){
                    min_hist=(weather_table[i][j][k])._min_temp;
                }

            }
        }
    }
    return min_hist;
}

/*
Un “procedimiento” que registre para cada año entre 1980 y 2016 la mayor temperatura máxima registrada durante ese año

osea, devuelve voy, y debo cargar los valores en un arreglo con tamaño YEARS
debo iterar para cada año sobre los dias y los meses, esto podria ser una funcion auxiliar
*/

static int max_temp_max_from_year (WeatherTable weather_table, int year ){
    int max_temp_max = INT_MIN;
    for (int i=0; i<MONTHS; i++){
        //printf("Primer for i=%d\n", i);
        for (int j=0; j<DAYS; j++){
            //printf("Segundo for j=%d\n", j);
            if(((weather_table[year][i][j])._max_temp)>max_temp_max){
                    max_temp_max=(weather_table[year][i][j])._max_temp;
            }
        }
    }
    return max_temp_max;
}

void max_temp_max_from_each_year (WeatherTable weather_table, int mtm_year[YEARS]){
    for (int i=0; i<YEARS; i++){
        //printf("For i=%d\n", i);
        mtm_year[i]=max_temp_max_from_year(weather_table, i);
    }
}

/*
Implementar un procedimiento que registre para cada año entre 1980 y 2016 el mes de ese año en que se registró 
la mayor cantidad mensual de precipitaciones (campo rainfall) (práctico 2.1, ejercicio 2.c).

devuelve un arreglo de tamaño year, en cada lugar del arreglo guardo un mes, debe ser el mes con mayor cantidad mensual de precipitaciones

osea voy a necesitar una funcion auxiliar que toma un mes y un año y devuelve las precipitaciones mensuales (simplemente itera sobre los dias y suma)

y luego otra que en base a la anterior devuelva el mes del año en que ese fue maximo (aunque puedo hacer de una en la final esto)

*/

static int prec_mensuales (WeatherTable weather_table, int year, int month){
    int sum_prec=0;
    for (int i=0; i<DAYS; i++){
        sum_prec = sum_prec + (weather_table[year][month][i]._rainfall);
    }
    return sum_prec;
}

static int month_m_rainfall(WeatherTable weather_table, int year){
    int max_rainfall=INT_MIN;
    int res; 
    for(int i=0; i<MONTHS; i++){
        if(prec_mensuales(weather_table, year, i)>max_rainfall){
            max_rainfall = prec_mensuales(weather_table, year, i);
            res=i+1;
        }

    }
    return res;
}

void array_max_rainfall (WeatherTable weather_table, int month_max_rainfall[YEARS]){
    for(int i=0; i<YEARS; i++){
        month_max_rainfall[i] = month_m_rainfall(weather_table, i);
    }
}