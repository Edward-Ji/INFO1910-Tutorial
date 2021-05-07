#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vfs.h"

#define BUFLEN 1024

#define TOKEN strtok(NULL, " ")

extern vfile *root;

vfile *cwdir;  // current working directory

void touch(char *fname, char *text) {
    vfile *raw = new_raw(cwdir, fname);
    if (raw && text) {
        write_raw(raw, text);
    }
}

void cat(char *fname) {
    vfile *vf = get_vfile(cwdir, fname);
    if (vf == NULL) {
        printf("Target does not exist!\n");
        return;
    }
    if (vfile_type(vf) == RAW_TYPE) {
        char buffer[BUFLEN];
        read_raw(vf, buffer);
        printf("%s\n", buffer);
    } else {
        printf("Target is a not a file.\n");
    }
}

void rm(char *fname) {
    vfile *vf = get_vfile(cwdir, fname);
    if (vf != NULL) {
        del_vfile(vf);
    } else {
        printf("Target does not exist!\n");
    }
}

void mv(char *name1, char *name2) {
    vfile *vf = get_vfile(cwdir, name1);
    if (vf != NULL) {
        rename_vfile(vf, name2);
    }
}

void mkdir(char *name) {
    new_dir(cwdir, name);
}

void rmdir(char *name) {
    vfile *vf = get_vfile(cwdir, name);
    if (vf != NULL) {
        if (vfile_type(vf) != DIR_TYPE) {
            del_vfile(vf);
        } else {
            printf("Target is a not a directory.\n");
        }
    } else {
        printf("Target does not exist!\n");
    }
}

void ls() {
    list_dir(cwdir);
}

void cd(char *name) {
    vfile *vf = get_vfile(cwdir, name);
    if (vf != NULL) {
        if (vfile_type(vf) == DIR_TYPE) {
            cwdir = vf;
        } else {
            printf("Target is a not a directory.\n");
        }
    }
    else {
        printf("Target does not exist!\n");
    }
}

void pwd() {
    abs_path(cwdir);
    printf("\n");
}

int main(int argc, char const *argv[]) {

    new_root();
    cwdir = root;

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
            } else if (strcmp(token, "mkdir") == 0) {
                mkdir(TOKEN);
            } else if (strcmp(token, "rmdir") == 0) {
                rmdir(TOKEN);
            } else if (strcmp(token, "ls") == 0) {
                ls();
            } else if (strcmp(token, "cd") == 0) {
                cd(TOKEN);
            } else if (strcmp(token, "pwd") == 0) {
                pwd();
            } else if (strcmp(token, "exit") == 0) {
                break;
            } else {
                printf("Command not recognised!\n");
            }
        }
    }

    del_root();

    return 0;
}
