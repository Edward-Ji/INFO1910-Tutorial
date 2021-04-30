#include <stdio.h>
#include <limits.h>
#include "intarr.h"

// general statistical functions
int sum(int *array, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += array[i];
    return sum;
}

int max(int *array, int len) {
    int max = INT_MIN;
    for (int i = 0; i < len; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

int min(int *array, int len) {
    int min = INT_MAX;
    for (int i = 0; i < len; i++) {
        if (array[i] < min)
            min = array[i];
    }
    return min;
}

float average(int *array, int len) {
    return (float) sum(array, len) / len;
}

// 1d array functions
void display(int *array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int contains(int *array, int *sequence, int arr_len, int seq_len) {
    int i_arr = 0;
    int i_seq = 0;
    while (i_arr < arr_len - i_seq) {
        if (array[i_arr] == sequence[i_seq])
            i_seq++;
        else
            i_seq = 0;
        if (i_seq == seq_len)
            return i_arr - seq_len + 1;
        i_arr++;
    }
    return -1;
}

void cumsum(int *array, int *folding_sums, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += array[i];
        folding_sums[i] = sum;
    }
}

// 2d array functions
void display_2d(int **array, int outer_len, int inner_len) {
    for (int i = 0; i < outer_len; i++) {
        for (int j = 0; j < inner_len; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void flatten_2d(int **array_2d, int *array, int outer_len, int inner_len) {
    for (int i = 0; i < outer_len; i++) {
        for (int j = 0; j < inner_len; j++) {
            array[i * inner_len + j] = array_2d[i][j];
        }
    }
}

void unflatten_2d(int **array_2d, int *array, int outer_len, int inner_len) {
    for (int i = 0; i < outer_len; i++) {
        for (int j = 0; j < inner_len; j++) {
            array_2d[i][j] = array[i * inner_len + j];
        }
    }
}

// 3d array functions
void display_3d(int ***array_3d, int dim1_len, int dim2_len, int dim3_len) {
    for (int i = 0; i < dim1_len; i++) {
        printf(" [%d][][]\n", i);
        for (int j = 0; j < dim2_len; j++) {
            for (int k = 0; k < dim3_len; k++) {
                printf("%d ", array_3d[i][j][k]);
            }
            printf("\n");
        }
    }
}

void flatten_3d(int ***array_3d, int *array, int dim1_len, int dim2_len, int dim3_len) {
    for (int i = 0; i < dim1_len; i++) {
        for (int j = 0; j < dim2_len; j++) {
            for (int k = 0; k < dim3_len; k++) {
                array[i * dim2_len * dim3_len + j * dim3_len + k] = array_3d[i][j][k];
            }
        }
    }
}

void unflatten_3d(int ***array_3d, int *array, int dim1_len, int dim2_len, int dim3_len) {
    for (int i = 0; i < dim1_len; i++) {
        for (int j = 0; j < dim2_len; j++) {
            for (int k = 0; k < dim3_len; k++) {
                array_3d[i][j][k] = array[i * dim2_len * dim3_len + j * dim3_len + k];
            }
        }
    }
}
