#include <stdbool.h>
#include <stdio.h>
#include "list.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TAIL 5
#define N_TESTCASES_ADDR 6
#define N_TESTCASES_TAKE 7
#define N_TESTCASES_DROP 4
#define N_TESTCASES_CONCAT 4

// construye una lista a partir de un arreglo
// (usa los constructores de lista empty y addl)
list array_to_list(int array[], int length) {
    list result;
    result = empty();

    // agregamos al revés ya que usamos addl
    for (int i = length; i > 0; i--) {
        result = addl(array[i-1], result);
    }

    return result;
}

// chequea si dos listas son iguales
// (usa las funciones de listas length e index)
bool is_equal_to(list l1, list l2) {
    int len1 = length(l1);
    int len2 = length(l2);
    int i = 0;
    while (i < len1 && i < len2 && index(l1, i) == index(l2, i)) {
        i++;
    }
    return i == len1 && len1 == len2;
}

// // imprime una lista
// // (usa las funciones de listas length e index)
// void show_list(list l) {
// }

// Testeo de la función tail()
void test_tail() {
    // representación de un solo caso de test
    struct tail_testcase {
        int a[MAX_LENGTH];       // elementos de la lista de entrada
        int length;              // largo de la lista de entrada
        int result[MAX_LENGTH];  // elementos esperados de la lista resultado
        int result_length;       // largo esperado de la lista resultado
    };

    // casos de test (uno por línea)
    struct tail_testcase tests[N_TESTCASES_TAIL] = {
      { {-2}, 1, {}, 0 },             // testea: tail([-2]) == []
      { {1, -2}, 2, {-2}, 1 },        // testea: tail([1, -2]) == [-2]
      { {8, 1, -2}, 3, {1, -2}, 2 },  // testea: tail([8, 1, -2]) == [1, -2]
      { {1, 2, 3, 4}, 4, {2, 3, 4}, 3}, // testea: tail([1, 2, 3, 4]) == [1, 2, 3]
      { {1, 0, 5, 3, 2}, 5, {0, 5, 3, 2}, 4}, //testea: tail([1, 0, 5, 3, 2]) == [0, 5, 3, 2]
    };

    list input;
    list result, expected_result;

    printf("TESTING tail\n");

    for (int i=0; i < N_TESTCASES_TAIL; i++) {
        printf("Test case %i: ", i+1);

        // creamos la lista de entrada
        input = array_to_list(tests[i].a, tests[i].length);

        // TEST! llamamos la función a testear
        result = tail(input);

        // creamos la lista resultado esperada
        expected_result = array_to_list(tests[i].result, tests[i].result_length);

        // comparamos resultado obtenido con resultado esperado
        if (is_equal_to(result, expected_result)) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }

        destroy_list(result);
        destroy_list(expected_result);
    }
}

// Testeo de la función addr()
void test_addr() {
    // representación de un solo caso de test
    struct addr_testcase {
        int a[MAX_LENGTH];       // elementos de la lista de entrada
        int length;              // largo de la lista de entrada
        elem e;                  // elemento a agregar
        int result[MAX_LENGTH];  // elementos esperados de la lista resultado
        int result_length;       // largo esperado de la lista resultado
    };

    // casos de test (uno por línea)
    struct addr_testcase tests[N_TESTCASES_ADDR] = {
      { {8, 1, -2}, 3, 44, {8, 1, -2, 44}, 4 },  // testea: addr([8, 1, -2], 44) == [8, 1, -2, 44]
      { {1, -2}, 2, 44, {1, -2, 44}, 3 },        // testea: addr([1, -2], 44) == [1, -2, 44]
      { {-2}, 1, 44, {-2, 44}, 2 },              // testea: addr([-2], 44) == [-2, 44]
      { {}, 0, 44, {44}, 1 },                    // testea: addr([], 44) == [44]    
      { {1, 1, 1, 1}, 4, 2, {1, 1, 1, 1, 2}, 5}, // testea: addr([1, 1, 1, 1], 2) == [1, 1, 1, 1, 2]
      { {1, 2}, 2, 3, {1, 2, 3}, 3},             // testea: addr([1, 2], 3) == [1, 2, 3]
    };

    list input;
    list result, expected_result;

    printf("TESTING addr\n");

    for (int i=0; i < N_TESTCASES_ADDR; i++) {
        printf("Test case %i: ", i+1);

        // creamos la lista de entrada
        input = array_to_list(tests[i].a, tests[i].length);

        // TEST! llamamos la función a testear
        result = addr(input, tests[i].e);

        // creamos la lista resultado esperada
        expected_result = array_to_list(tests[i].result, tests[i].result_length);

        // comparamos resultado obtenido con resultado esperado
        if (is_equal_to(result, expected_result)) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }

        destroy_list(result);
        destroy_list(expected_result);
    }
}

// Testeo de la función take()
void test_take() {
    // representación de un solo caso de test
    struct take_testcase {
        int a[MAX_LENGTH];       // elementos de la lista de entrada
        int length;              // largo de la lista de entrada
        int n;                   // cantidad de elementos a tomar
        int result[MAX_LENGTH];  // elementos esperados de la lista resultado
        int result_length;       // largo esperado de la lista resultado
    };

    // casos de test (uno por línea)
    struct take_testcase tests[N_TESTCASES_TAKE] = {
      { {8, 1, -2}, 3, 0, {}, 0 },          // testea: take([8, 1, -2], 0) == []
      { {8, 1, -2}, 3, 1, {8}, 1 },         // testea: take([8, 1, -2], 1) == [8]
      { {8, 1, -2}, 3, 2, {8, 1}, 2 },      // testea: take([8, 1, -2], 2) == [8, 1]
      { {8, 1, -2}, 3, 3, {8, 1, -2}, 3 },  // testea: take([8, 1, -2], 3) == [8, 1, -2]
      { {8, 1, -2}, 3, 4, {8, 1, -2}, 3 },  // testea: take([8, 1, -2], 4) == [8, 1, -2]
      { {}, 0, 0, {}, 0},                   // testea: take([], 0) == []
      { {8}, 1, 1, {8}, 1},                 // testea: take([8], 1) == 8
    };

    list input;
    list result, expected_result;

    printf("TESTING take\n");

    for (int i=0; i < N_TESTCASES_TAKE; i++) {
        printf("Test case %i: ", i+1);
        fflush(stdout);

        // creamos la lista de entrada
        input = array_to_list(tests[i].a, tests[i].length);

        // TEST! llamamos la función a testear
        result = take(input, tests[i].n);

        // creamos la lista resultado esperada
        expected_result = array_to_list(tests[i].result, tests[i].result_length);

        // comparamos resultado obtenido con resultado esperado
        if (is_equal_to(result, expected_result)) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }

        destroy_list(result);
        destroy_list(expected_result);
    }
}

//testeo de la funcion drop
void test_drop(){
    //representacion de un solo caso del test
    struct drop_testcase {
        int a[MAX_LENGTH];      // Elementos de la lista de entrada
        int length;             // Tamaño de la lista de entrada
        int d;                  // Cantidad de elementos a tirar
        int result[MAX_LENGTH]; // Elementos esperados de la lista resultado
        int result_length;      // Largo esperado de la lista resultado
    };

    //casos del test (uno por linea)                     
    struct drop_testcase tests[N_TESTCASES_DROP] = {
        { {1, 2}, 2, 0, {1, 2}, 2 },     // testea: drop([1, 2], 0) == [1, 2]
        { {1, 2, 3}, 3, 2, {3}, 1 },     // testea: drop([1, 2, 3], 2) == [3]
        { {}, 0, 0, {}, 0 },             // testea: drop([], 0) == []
        { {1}, 1, 1, {}, 0 },            // testea: drop([1], 1) == []
    };

    list input;
    list result, expected_result;

    printf("TESTING drop\n");

    for(int i = 0; i<N_TESTCASES_DROP; i++){
        printf("testcase %i: ", i+1);
        fflush(stdout);

        // Creamos la lista de entrada
        input = array_to_list(tests[i].a, tests[i].length);

        // TEST! llamamos a la funcion a testear
        result = drop(input, tests[i].d);

        // Creamos la lista resultado esperado
        expected_result = array_to_list(tests[i].result, tests[i].result_length);

        // Comparamos resultado obtenido con resultado esperado
        if(is_equal_to(result, expected_result)){
            printf("OK\n");
        }else{
            printf("FAILED\n");
        }

        destroy_list(result);
        destroy_list(expected_result);


    }
}

//testeo de la funcion concat
void test_concat(){
    //representacion de un solo caso del test
    struct concat_testcase {
        int a1[MAX_LENGTH];      // Elementos de la lista 1 de entrada
        int length1;             // Tamaño de la lista 1 de entrada
        int a2[MAX_LENGTH];      // Elementos de la lista 2 de entrada
        int length2;             // Tamaño de la lista 2 de entrada
        int result[MAX_LENGTH];  // Elementos esperados de la lista resultado
        int result_length;       // Largo esperado de la lista resultado
    };

    //casos del test (uno por linea)                     
    struct concat_testcase tests[N_TESTCASES_CONCAT] = {
        { {}, 0, {}, 0, {}, 0 },                    // testea: concat([], []) == []
        { {1, 2, 3}, 3, {}, 0, {1, 2, 3}, 3 },      // testea: concat( [1, 2, 3], []) == [1, 2, 3]
        { {}, 0, {1}, 1, {1}, 1},                   // testea: concat( [], [1]) == [1]
        { {1, 2}, 2, {2, 3}, 2, {1, 2, 2, 3},  4 }, // testea: concat( [1, 2], [2, 3]) == [1, 2, 2, 3]
    };

    list input1, input2;
    list result, expected_result;

    printf("TESTING concat\n");

    for(int i = 0; i<N_TESTCASES_CONCAT; i++){
        printf("testcase %i: ", i+1);
        fflush(stdout);

        // Creamos la lista de entrada 1
        input1 = array_to_list(tests[i].a1, tests[i].length1);

        // Creamos la lista de entrada 1
        input2 = array_to_list(tests[i].a2, tests[i].length2);

        // TEST! llamamos a la funcion a testear
        result = concat(input1, input2);

        // Creamos la lista resultado esperado
        expected_result = array_to_list(tests[i].result, tests[i].result_length);

        // Comparamos resultado obtenido con resultado esperado
        if(is_equal_to(result, expected_result)){
            printf("OK\n");
        }else{
            printf("FAILED\n");
        }

        destroy_list(result);
        destroy_list(expected_result);

    }
}

int main() {
    test_tail();
    test_addr();
    test_take();
    test_drop();
    test_concat();

    return 0;
}


