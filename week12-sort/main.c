#include <stdio.h>
#include "sort.h"

void display_ints(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void display_points(point *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("(%d, %d) ", array[i].x, array[i].y);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {

    int int_arr_empty[] = {};
    int int_arr_single[] = {1};
    int int_arr_sorted[] = {1, 2, 3, 4, 5};
    int int_arr_unsort[] = {5, 2, 3, 1, 4};

    puts(" is sorted int");
    printf("empty is sorted  %2d\n", is_sorted_int(int_arr_empty, 0));
    printf("single is sorted %2d\n", is_sorted_int(int_arr_single, 1));
    printf("sorted is sorted %2d\n", is_sorted_int(int_arr_sorted, 5));
    printf("unsort is sorted %2d\n", is_sorted_int(int_arr_unsort, 5));
    putchar('\n');

    puts(" sort int");
    sort_int(int_arr_unsort, 5);
    display_ints(int_arr_unsort, 5);
    putchar('\n');

    const int point_count = 5;
    point points_x_sorted[point_count] = {
        (point) {-1,  2},
        (point) { 1, -2},
        (point) { 1,  2},
        (point) { 2,  3},
        (point) { 3, -4},
    };

    point points_unsort[point_count] = {
        (point) {-1,  2},
        (point) { 1,  2},
        (point) { 1, -2},
        (point) { 2,  3},
        (point) { 3, -4},
    };

    puts(" is sorted point");
    printf("x_sorted is sorted %d\n",
        is_sorted_point(points_x_sorted, point_count, x_first));
    printf("unsort is sorted   %d\n",
        is_sorted_point(points_unsort, point_count, x_first));
    putchar('\n');

    puts(" sort point");
    puts("manhattan");
    sort_point(points_unsort, point_count, manhattan);
    display_points(points_unsort, point_count);
    puts("euclidean");
    sort_point(points_unsort, point_count, euclidean);
    display_points(points_unsort, point_count);
    puts("x first");
    sort_point(points_unsort, point_count, x_first);
    display_points(points_unsort, point_count);
    puts("y first");
    sort_point(points_unsort, point_count, y_first);
    display_points(points_unsort, point_count);

    return 0;
}
