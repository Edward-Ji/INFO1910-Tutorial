#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256

int main(int argc, char const *argv[]) {

    int numbers[MAX_LEN];

    int sum;
    char number[11];

    FILE *f = fopen("fibonacci.txt", "r");

    while (fgets(number, 11, f)) {
        sum += atoi(number);
    }

    printf("Sum is %d.\n", sum);

    return 0;
}
