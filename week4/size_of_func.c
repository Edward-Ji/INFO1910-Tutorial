#include <stdio.h>

int func_a()
{
    int x = 5;
    int y = 7;
    return x + y;
}

int func_b(int a, int b)
{
    int x = 5;
    int y = 7;
    return a * x + b * y;
}

int func_c(int* a)
{
    int x = 5;
    if (*a)
    {
    int y = 7;
    x += y;
    }
    return x;
}

int func_d(int* a)
{
    int x = 5;
    if (*a)
    {
        int y = 7;
        x += y;
    }
    else
    {
        double z = 8;
        x -= z;
    }
    return x;
}

int func_e(char* str)
{
    int x = 5;
    while (str++)
    {
        int z = 3;
        x += z;
    }
    while (x > 5)
    {
        double q = 3;
        x -= q;
    }
    if (x == 5)
    {
        int a = 4;
        x += a;
    }
    else
    {
        double q = 9.0;
        x -= q;
    }
    return x;
}

int main(int argc, char const *argv[]) {

    printf("int = %lu", sizeof(int));
    printf("chr = %lu", sizeof(char));
    printf("float = %lu", sizeof(float));
    printf("double = %lu", sizeof(double));

    return 0;
}
