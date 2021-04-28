#include <stdio.h>

int main()
{

    int n;
    int i, k;
    unsigned short bits = sizeof(n) * 8;

    scanf("%d", &n);

    for (i = bits; i >= 0; i--)
    {
        if (n & (1 << i))
            printf("1");
        else
            printf("0");
    }

    printf("\n");

    return 0;
}