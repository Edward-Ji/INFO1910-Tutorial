#include <stdio.h>

int main(int argc, char const *argv[]) {

    union {
        int i;
        char c;
        float f;
    } u;

    scanf("%c", &(u.c));
    printf("%d\n", u.i);
    printf("%f\n", u.f);

    return 0;
}
