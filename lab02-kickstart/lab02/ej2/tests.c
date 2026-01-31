#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TIENE_CIMA 10
#define N_TESTCASES_CIMA 10

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();

    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    //es una lista de structs
    struct testcase tests[N_TESTCASES_TIENE_CIMA] = {
        { {8}, 1, true },
        { {8, 9}, 2, true },
        { {8, 6}, 2, true },
        { {8, 9, 10, 20}, 4, true },
        { {8, 7, 6, 5}, 4, true },
        { {8, 7, 5, 7}, 4, false },
        { {8, 7, 6, 10}, 4, false },
        { {8, 7, 6, 5, 4, 3, 2, 10}, 8, false },
        { {8, 9, 10, 1}, 4, true },
        { {1, 1, 1, 1}, 4, true },
    };
    bool result;

    printf("TESTING tiene_cima\n");

    for (int i=0; i < N_TESTCASES_TIENE_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = tiene_cima(tests[i].a, tests[i].length);

        if (result != tests[i].result) {
            printf("FAILED\n");
        } else {
            printf("OK\n");
        }
    }
}

void test_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        { {8}, 1, 8 },
        { {8, 9}, 2, 9 },
        { {8, 6}, 2, 8 },
        { {8, 9, 10, 20}, 4, 20 },
        { {8, 7, 6, 5}, 4, 8 },
        { {5, 8, 7, 5}, 4, 8 },
        { {8, 20, 11, 10}, 4, 20 },
        { {1, 8, 7, 6, 5, 4, 3, 2}, 8, 8 },
        { {8, 9, 10, 1}, 4, 10 },
        { {1, 1, 1, 1}, 4, 1 },

    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }
}
