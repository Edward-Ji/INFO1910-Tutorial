#include <stdio.h>
#include <stdlib.h>
#include "strlib.h"

int main(int argc, char const *argv[]) {

    const char *string1 = "Hello world!";
    const char *string2 = "Hello!";
    const char *string3 = "Heloo! Hello!";

    // TEST: string length
    printf("evaluate: %2d  expect: %2d\n", strlength(string2), 6);
    printf("evaluate: %2d  expect: %2d\n", strlength(string1), 12);
    printf("\n");

    // TEST: string contains string
    printf("evaluate: %2d  expect: %2d\n", strfind(string1, string2), -1);
    printf("evaluate: %2d  expect: %2d\n", strfind(string3, string2), 7);
    printf("evaluate: %2d  expect: %2d\n", strfind(string2, ""), 0);
    printf("evaluate: %2d  expect: %2d\n", strfind("", string2), -1);
    printf("\n");

    // TEST: string equality
    printf("evaluate: %2d  expect: %2d\n", strequal(string2, "Hello world!"), 0);
    printf("evaluate: %2d  expect: %2d\n", strequal(string2, "Hello!"), 1);
    printf("evaluate: %2d  expect: %2d\n", strequal(string2, "Hello"), 0);
    printf("evaluate: %2d  expect: %2d\n", strequal("", ""), 1);
    printf("\n");

    char buffer1[] = "**********";
    char buffer2[] = "**********";

    // TEST: string copy
    strcopyn(string1, buffer1, 6);
    printf("buffer: %12s  expect: %12s\n", buffer1, "Hello");
    printf("\n");

    // TEST: string strip
    strstrip("--H-e-l-l-o--", buffer2, '-');
    printf("buffer: %12s  expect: %12s\n", buffer2, "H-e-l-l-o");

    strstrip("", buffer2, '-');
    printf("buffer: %12s  expect: %12s\n", buffer2, "");

    printf("\n");

    // TEST: string split and join

    const int nword = 10;
    const int nchar = 20;
    char **strarr = malloc(nword * sizeof(char *));
    for (int i = 0; i < nword; i++) {
        strarr[i] = malloc(nchar * sizeof(char));
    }

    const char *line = "Hello_world!__We_love_programming_in_C.";

    int nstr;
    nstr = strsplit(line, strarr, '_');

    printf("nstr: %d  expect: %d\n", nstr, 8);
    printf("Split result: \n");
    for (int i = 0; i < nstr; i++) {
        printf("[%d] %s\n", i, strarr[i]);
    }

    printf("\n");

    char buffer[100];

    strjoin(strarr, buffer, nstr, ' ');
    printf("%s\n", buffer);

    for (int i = 0; i < nword; i++) {
        free(strarr[i]);
    }
    free(strarr);

    return 0;
}
