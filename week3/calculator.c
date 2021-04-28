#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    if (argc != 4) {
        printf("Not enough arguments!\n");
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    char ope = argv[3][0];

    float result;

    switch (ope) {

        case '+':
        result = a + b;
        break;

        case '-':
        result = a - b;
        break;

        case '*':
        result = a * b;
        break;

        case '/':
        result = a / b;
        break;

        default:
        printf("Operation not valid!\n");
        return 2;
    }

    printf("%f\n", result);

    return 0;
}
