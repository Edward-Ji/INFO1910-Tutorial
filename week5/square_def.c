#include <stdio.h>
#define SQUARE(x) ((x) * (x))

int main(int argc, char const *argv[]) {
    int i = 0;
    while(i <= 10) {
        printf("%d\n", SQUARE(i++));
    }
    return 0;
}
