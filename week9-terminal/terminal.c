#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 1024

#define TOKEN strtok(NULL, " ")

extern int errno;

void printerr() {
    int errnum = errno;
    fprintf(stderr, "Error %d: %s\n", errnum, strerror(errnum));
}

void touch(char *fname, char *text) {
    if (fname == NULL) {
        printf("You need to supply a file name!\n");
        return;
    }
    if (text == NULL) {
        text = "\0";
    }

    FILE *fp = fopen(fname, "w");
    if (fp == NULL) {
        return printerr();
    }
    if (fputs(text, fp) == EOF) {
        return printerr();
    }
    fclose(fp);
}

void cat(char *fname) {
    if (fname == NULL) {
        printf("You need to supply a file name!\n");
        return;
    }

    FILE *fp = fopen(fname, "r");
    if (fp == NULL) {
        return printerr();
    }
    char buffer[BUFLEN];
    if (fgets(buffer, BUFLEN, fp) == NULL) {
        return printerr();
    }
    if (fclose(fp) == EOF) {
        return printerr();
    }
    printf("%s\n", buffer);
}

void rm(char *fname) {
    if (remove(fname) == -1) {
        return printerr();
    }
}

void mv(char *fname1, char *fname2) {
    if (rename(fname1, fname2) == -1) {
        return printerr();
    }
}

int main(int argc, char const *argv[]) {

    char *buffer, *token;
    buffer = (char *) malloc(BUFLEN * sizeof(char));

    while (1) {
        printf("> ");
        fgets(buffer, BUFLEN, stdin);
        *(strchr(buffer, '\n')) = '\0';
        if ((token = strtok(buffer, " ")) != NULL) {
            if (strcmp(token, "touch") == 0) {
                touch(TOKEN, TOKEN);
            } else if (strcmp(token, "cat") == 0) {
                cat(TOKEN);
            } else if (strcmp(token, "rm") == 0) {
                rm(TOKEN);
            } else if (strcmp(token, "mv") == 0) {
                mv(TOKEN, TOKEN);
            } else if (strcmp(token, "exit") == 0) {
                break;
            }
        }
    }

    return 0;
}
