#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vfs.h"

#define BUFLEN 1024

#define TOKEN strtok(NULL, " ")

extern vfile *root;

vfile *cwdir;  // current working directory

void touch(char *name, char *text) {
    if (name == NULL || text == NULL) {
        printf("usage: touch <file name> [<text>]\n");
        return;
    }

    vfile *raw = new_raw(cwdir, name);
    if (raw && text) {
        write_raw(raw, text);
    }
}

void cat(char *name) {
    if (name == NULL) {
        printf("usage: cat <file name>\n");
        return;
    }

    vfile *vf = get_vfile(cwdir, name);
    if (vf == NULL) {
        printf("%s does not exist.\n", name);
        return;
    }
    if (vfile_type(vf) == RAW_TYPE) {
        char buffer[BUFLEN];
        read_raw(vf, buffer);
        printf("%s\n", buffer);
    } else {
        printf("%s is a not a file.\n", name);
    }
}

void rm(char *name) {
    if (name == NULL) {
        printf("usage: rm <file/directory name>\n");
        return;
    }

    vfile *vf = get_vfile(cwdir, name);
    if (vf != NULL) {
        del_vfile(vf);
    } else {
        printf("%s does not exist.\n", name);
    }
}

void mv(char *name1, char *name2) {
    if (name1 == NULL || name2 == NULL) {
        printf("usage: mv <old name> <new name>\n");
        return;
    }

    vfile *vf = get_vfile(cwdir, name1);
    if (vf != NULL) {
        rename_vfile(vf, name2);
    }
}

void mkdir(char *name) {
    if (name == NULL) {
        printf("usage: mkdir <directory name>\n");
        return;
    }

    new_dir(cwdir, name);
}

void rmdir(char *name) {
    if (name == NULL) {
        printf("usage: rmdir <directory name>\n");
        return;
    }

    vfile *vf = get_vfile(cwdir, name);
    if (vf != NULL) {
        if (vfile_type(vf) != DIR_TYPE) {
            del_vfile(vf);
        } else {
            printf("%s is a not a directory.\n", name);
        }
    } else {
        printf("%s does not exist.\n", name);
    }
}

void ls() {
    list_dir(cwdir);
}

void cd(char *name) {
    if (name == NULL) {
        printf("usage: cd <directory name>\n");
        return;
    }

    vfile *vf = get_vfile(cwdir, name);
    if (vf != NULL) {
        if (vfile_type(vf) == DIR_TYPE) {
            cwdir = vf;
        } else {
            printf("%s is a not a directory.\n", name);
        }
    }
    else {
        printf("%s does not exist.\n", name);
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
                printf("Command not recognised.\n");
            }
        }
    }

    del_root();

    return 0;
}
