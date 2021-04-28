/*
* Ordering Puzzle
* Take in three numbers and output them sorted using only:
* - scanf, printf
* - logical operators
* - numeric operators
* - int variables
*/

#include <stdio.h>

int main () {

    int a, b, c;
    int max, min, mid;

    printf("Input an intger: ");
    scanf("%d", &a);
    printf("Input an intger: ");
    scanf("%d", &b);
    printf("Input an intger: ");
    scanf("%d", &c);

    printf("%d %d %d\n",
           a * (a < b && a < c) + b * (b < a && b < c) + c * (c < a && c < b),
           a * (a < b && a > c) + b * (b < a && b > c) + c * (c < a && c > b) + 
           a * (a > b && a < c) + b * (b > a && b < c) + c * (c > a && c < b),
           a * (a > b && a > c) + b * (b > a && b > c) + c * (c > a && c > b));

    return 0;
}