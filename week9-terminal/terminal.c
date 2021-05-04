#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERLEN 1024
#define ARRAYLEN 16

char *dirfiles[ARRAYLEN];
size_t filecount;

void touch(const char *, const char *);
void cat(const char *);
void rm(const char *);
void mv(const char *, const char *);

void ls();

void cleanup();

int main(int argc, char const *argv[]) {

    for (int i = 0; i < ARRAYLEN; i++) {
        dirfiles[i] = (char *) malloc(BUFFERLEN * sizeof(char));
    }

    char *buffer = (char *) malloc(BUFFERLEN * sizeof(char));

    while (1) {
        char *bufhead = buffer;

        printf("> ");
        fgets(buffer, BUFFERLEN, stdin);
        strtok(buffer, "\n");

        char *command = strsep(&buffer, " ");
        if (strcmp(command, "touch") == 0) {
            touch(strsep(&buffer, " "), strsep(&buffer, " "));
        } else if (strcmp(command, "cat") == 0) {
            cat(strsep(&buffer, " "));
        } else if (strcmp(command, "rm") == 0) {
            rm(strsep(&buffer, " "));
        } else if (strcmp(command, "mv") == 0) {
            mv(strsep(&buffer, " "), strsep(&buffer, " "));
        } else if (strcmp(command, "ls") == 0) {
            ls();
        } else if (strcmp(command, "exit") == 0) {
            cleanup();
            break;
        }
        buffer = bufhead;
    }

    for (int i = 0; i < ARRAYLEN; i++) {
        free(dirfiles[i]);
    }

    free(buffer);

    return 0;
}

void touch(const char *filename, const char *content) {
    int found = 0;
    for (int i = 0; i < filecount; i++) {
        if (strcmp(filename, dirfiles[i]) == 0) {
            found = 1;
        }
    }
    if (!found) {
        FILE *fp = fopen(filename, "w");
        if (fp) {
            if (content) {
                fputs(content, fp);
            }
            fclose(fp);
        }

        strcpy(dirfiles[filecount], filename);
        filecount++;
    } else {
        printf("File %s exists.\n", filename);
    }
}

void cat(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char buffer[BUFFERLEN];
    if (fp) {
        fgets(buffer, BUFFERLEN, fp);
        printf("%s\n", buffer);
        fclose(fp);
    } else {
        printf("No file named %s.\n", filename);
    }
}

void rm(const char *filename) {
    char found = 0;
    for (int i = 0; i < filecount; i++) {
        if (strcmp(filename, dirfiles[i]) == 0) {
            remove(filename);
            filecount--;
            found = 1;
        }
        if (found) {
            strcpy(dirfiles[i], dirfiles[i+1]);
        }
    }
    if (!found) {
        printf("No file named %s.\n", filename);
    }
}

void mv(const char *filename1, const char *filename2) {
    FILE *fp = fopen(filename1, "r");
    char buffer[BUFFERLEN];
    if (fp) {
        fgets(buffer, BUFFERLEN, fp);
        fclose(fp);
        int countnow = filecount;
        touch(filename2, buffer);
        if (countnow != filecount) {
            rm(filename1);
        }
    } else {
        printf("No file named %s.\n", filename1);
    }
}

void ls() {
    for (int i = 0; i < filecount; i++) {
        printf("%s \n", dirfiles[i]);
    }
}

void cleanup() {
    for (int i = 0; i < filecount; i++) {
        remove(dirfiles[i]);
    }
}
