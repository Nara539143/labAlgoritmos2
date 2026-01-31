#include <stdbool.h>
#include <stdio.h>
#include "cima_log.h"

#define MAX_LENGTH 10
#define N_TESTCASES_CIMA 10

int main() {
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

        result = cima_log(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
