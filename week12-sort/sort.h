#include <stddef.h>

typedef struct _point {
    int x;
    int y;
} point;

typedef int (*point_compare)(point, point);

/*
 * Given an integer array of a certain length, check if the integer array is
 * sorted or not. Return 1 if the array is in ascending order, 0 if not.
 */
int is_sorted_int(const int *array, int len);

/*
 * Given an integer array of a certain length, sort that integer array into
 * ascending order. This function uses the bubble sort algorithm.
 */
void sort_int(int *array, int len);

/*
 * Comparators functions for points
 * ================================
 * Given two points a and b, return an integer greater than, equal to, or less
 * than 0, according as the point a is greater than, equal to, or less than the
 * point b in the following order systems.
 *
 * Manhattan
 * ---------
 * Compare the Manhattan distance to origin.
 * The Manhattan distance between two points (x1, y1), (x2, y2) is given by
 * MD = |x2 - x1| + |y2 - y1|
 * So for a single point (x, y), its distance to the origin is given by
 * MDo = |x| + |y|
 *
 * Euclidiean
 * ----------
 * Compare the Euclidean distance to origin.
 * The Euclidean distnace between two points (x1, y1), (x2, y2) is given by
 * ED = √((x2 - x1)^2 + (y2 - y1)^2)
 * So for a single point (x, y), its distance to the origin is given by
 * EDo = √(x^2 + y^2)
 *
 * X-first
 * -------
 * Compare x values first, if they are the same, compare y values.
 *
 * Y-first
 * -------
 * Compare y values first, if they are the same, compare x values.
 *
 * All functions described above can be assigned to type point_compare.
 */
int manhattan(point a, point b);

int euclidean(point a, point b);

int x_first(point a, point b);

int y_first(point a, point b);

/*
 * Given a point array of a certain length, check if the point array is sorted
 * or not. Return 1 if the array is in ascending order, 0 if not.
 */
int is_sorted_point(const point *array, int len, point_compare fptr_cmp);

/*
 * Given a point array of a certain length, sort that point array into ascending
 * order. This function uses the bubble sort algorithm.
 */
void sort_point(point *array, int len, point_compare fptr_cmp);
