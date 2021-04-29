#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

int main(int argc, char const *argv[]) {

    const int length = 11;
    const int sublen = 2;

    int numbers[length] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    int subnums[sublen] = {512, 1024};

    // TEST: general statistical functions
    printf("sum %d\n", sum(numbers, length));
    printf("max %d\n", max(numbers, length));
    printf("min %d\n", min(numbers, length));

    printf("average %f\n\n", average(numbers, length));

    // TEST: contains function
    printf("contains %d\n\n", contains(numbers, subnums, length, sublen));

    // TEST: folding sums function
    int numsums[length];
    cumsum(numbers, numsums, length);
    printf("folding sums\n");
    display(numsums, length);
    printf("\n");

    /* TEST: 2d array functions
       with dynamically allocated memory
       create a non-contiguous 2d array for testing */
    const int rows = 2;
    const int cols = 5;

    int **numbers_2d = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        numbers_2d[i] = (int *) malloc(cols * sizeof(int));
    }

    // populate 2d array for testing
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(numbers_2d[i] + j) = i * cols + j;
        }
    }

    printf("2-D array\n");
    display_2d(numbers_2d, rows, cols);

    // create a 1d array for flattening
    int *flattened = (int *) malloc(rows * cols * sizeof(int));

    // call flatten 2d array to 1d
    flatten_2d(numbers_2d, flattened, rows, cols);

    printf("flattened\n");
    display(flattened, rows * cols);

    // depopulate 2d array for testing
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(numbers_2d[i] + j) = 0;
        }
    }

    // call unflatten 1d array to 2d
    unflatten_2d(numbers_2d, flattened, rows, cols);

    printf("unflattened\n");
    display_2d(numbers_2d, rows, cols);

    // release memory
    for (int i = 0; i < rows; i++) {
        free(numbers_2d[i]);
    }
    free(numbers_2d);

    printf("\n");

    /* TEST: 3d array functions
       with dynamically allocated memory
       create a non-contiguous 2d array for testing */
    const int deps = 3;

    int ***numbers_3d = (int ***) malloc(deps * sizeof(int **));
    for (int i = 0; i < deps; i++) {
        numbers_3d[i] = (int **) malloc(rows * sizeof(int *));
        for (int j = 0; j < rows; j++) {
            *(numbers_3d[i] + j) = (int *) malloc(cols * sizeof(int));
        }
    }

    // populate 3d array for testing
    for (int i = 0; i < deps; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                *(*(numbers_3d[i] + j) + k) = i * rows * cols + j * cols + k;
            }
        }
    }

    printf("3-D array\n");
    display_3d(numbers_3d, deps, rows, cols);

    // depopulate a 1d array for flattening
    int *flattened_3d = (int *) malloc(deps * rows * cols * sizeof(int));

    // call flatten 2d array to 1d
    flatten_3d(numbers_3d, flattened_3d, deps, rows, cols);

    printf("flattened\n");
    display(flattened_3d, deps * rows * cols);

    // depopulate 3d array for testing
    for (int i = 0; i < deps; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                *(*(numbers_3d[i] + j) + k) = 0;
            }
        }
    }

    // call unflatten 1d array to 3d
    unflatten_3d(numbers_3d, flattened_3d, deps, rows, cols);

    printf("unflattened\n");
    display_3d(numbers_3d, deps, rows, cols);

    // release memory
    for (int i = 0; i < deps; i++) {
        for (int j = 0; j < rows; j++) {
            free(*(numbers_3d[i] + j));
        }
        free(numbers_3d[i]);
    }
    free(numbers_3d);

    printf("\n");

    // 2d array of int pointers
    int *arr_pt[] = {
        (int []) {1, 2},
        (int []) {3, 4},
        (int []) {5, 6}
    };

    display_2d(arr_pt, 3, 2);
    flatten_2d(arr_pt, flattened, 3, 2);
    display(flattened, 6);
    printf("\n");

    // 3d array of int pointers
    int **arr_pt_pt[] = {
        (int *[]) {
            (int []) {1, 2},
            (int []) {3, 4},
            (int []) {5, 6}
        },
        (int *[]) {
            (int []) {7, 8},
            (int []) {9, 10},
            (int []) {11, 12}
        }
    };

    display_3d(arr_pt_pt, 2, 3, 2);
    flatten_3d(arr_pt_pt, flattened, 2, 3, 2);
    display(flattened, 12);
}
