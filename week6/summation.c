#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    int sum;
    char number[11];

    while (fgets(number, 11, stdin)) {
        sum += atoi(number);
    }

    printf("Sum is %d.\n", sum);

    return 0;
}
