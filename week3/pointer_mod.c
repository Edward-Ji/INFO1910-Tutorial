#include <stdio.h>

void var_mod(int* mod_int, const int value);

int main()
{
    int x = 5;
    var_mod(&x, 7);
    printf("%d\n", x); // Should print 7
}

void var_mod(int* mod_int, const int value) {
    *mod_int = value;
}
