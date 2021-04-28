#include <stdio.h>

size_t c_strlen(char* str);

int main(int argc, char const *argv[]) {
    char *str = "Hello world!";
    printf("%zu\n", c_strlen(str));
    return 0;
}

size_t c_strlen(char* str) {
    int len = 0;
    while (*str) {
        len += 1;
        str += 1;
    }
    return len;
}
