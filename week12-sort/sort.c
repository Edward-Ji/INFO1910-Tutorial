#include <math.h>
#include <stdlib.h>
#include "sort.h"

int is_sorted_int(const int *array, int len) {
    for (int i = 0; i < len-1; i++) {
        if (array[i] > array[i+1]) {
            return 0;
        }
    }
    return 1;
}

void sort_int(int *array, int len) {
    char swapped = 1;
    int temp;
    while (swapped) {
        swapped = 0;
        for (int i = 0; i < len-1; i++) {
            if (array[i] > array[i+1]) {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swapped = 1;
            }
        }
    }
}

int manhattan(point a, point b) {
    return abs(a.x) + abs(a.y) - (abs(b.x) + abs(b.y));
}

int euclidean(point a, point b) {
    return sqrt(pow(a.x, 2) + pow(a.y, 2))
         - sqrt(pow(b.x, 2) + pow(b.y, 2)) > 0 ? 1 : -1;
}

int x_first(point a, point b) {
    if (a.x == b.x) {
        return a.y - b.y;
    }
    return a.x - b.x;
}

int y_first(point a, point b) {
    if (a.y == b.y) {
        return a.x - b.x;
    }
    return a.y - b.y;
}

int is_sorted_point(const point *array, int len, point_compare fptr_cmp) {
    for (int i = 0; i < len-1; i++) {
        if (fptr_cmp(array[i], array[i+1]) > 0) {
            return 0;
        }
    }
    return 1;
}

void sort_point(point *array, int len, point_compare fptr_cmp) {
    char swapped = 1;
    point temp;
    while (swapped) {
        swapped = 0;
        for (int i = 0; i < len-1; i++) {
            if (fptr_cmp(array[i], array[i+1]) > 0) {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swapped = 1;
            }
        }
    }
}
