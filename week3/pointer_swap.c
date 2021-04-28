#include <stdio.h>

void mem_swap(int* a, int* b)
{
    if (a != NULL && b != NULL)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main(int argc, char const *argv[]) {
    int x = 19, y = 10;
    mem_swap(&x, &y);
    printf("x = %d\ny = %d\n", x, y);
    return 0;
}
