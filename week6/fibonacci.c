#include <stdio.h>

#define MAX_LEN 256

int main(int argc, char const *argv[]) {

    int count;
    scanf("%d", &count);

    int numbers[MAX_LEN] = {1, 1};

    int i;
    for (i = 2; i < count; i++) {
        numbers[i] = numbers[i-2] + numbers[i-1];
    }

    FILE *f = fopen("fibonacci.txt", "w");
    for (i = 0; i < count; i++) {
        fprintf(f, "%d\n", numbers[i]);
    }

    return 0;
}
