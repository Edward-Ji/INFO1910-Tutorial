#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vfs.h"

#define NAME_LEN 256

typedef struct _vfile {
    struct _vfile *parent;
    char name[NAME_LEN];
    union {
        char *text;
        struct _vfile **subf;
    } content;
    char type;
    size_t count;
} vfile;

vfile *root;

void new_root() {
    vfile *dir = malloc(sizeof(vfile));

    dir->parent = NULL;
    strcpy(dir->name, "root");
    dir->content.subf = NULL;
    dir->type = DIR_TYPE;
    dir->count = 0;

    root = dir;
}

void del_root() {
    del_dir(root);
}

void abs_path(vfile *vf) {
    if (vf->parent) {
        abs_path(vf->parent);
    }
    printf("%s/", vf->name);
}

char vfile_type(vfile *vf) {
    return vf->type;
}

void move_vfile(vfile *vf, vfile *dir) {
    if (vf->parent) {
        if (dir->type != DIR_TYPE) {
            printf("Target is not a directory.\n");
        }
        rmv_vfile(vf->parent, vf);
        add_vfile(dir, vf);
        vf->parent = dir;
    } else {
        printf("Root directory can not be moved.\n");
    }
}

int rename_vfile(vfile *vf, char *name) {
    if (strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
        strncpy(vf->name, name, NAME_LEN);
        return 0;
    } else {
        printf("%s is reserved.\n", name);
        return -1;
    }
}

void del_vfile(vfile *vf) {
    switch (vf->type) {
        case RAW_TYPE:
            del_raw(vf);
            break;
        case DIR_TYPE:
            del_dir(vf);
    }
}

vfile *new_raw(vfile *parent, char *name) {
    vfile *raw = malloc(sizeof(vfile));

    add_vfile(parent, raw);
    if (rename_vfile(raw, name) != 0) {
        return NULL;
    }

    char *text = (char *) malloc(sizeof(char));
    *text = '\0';
    raw->content.text = text;

    raw->type = RAW_TYPE;
    raw->count = 0;

    return raw;
}

void write_raw(vfile *raw, char *text) {
    char *rtext = raw->content.text;
    rtext = realloc(rtext, (strlen(text)+1) * sizeof(char));
    if (rtext) {
        strcpy(rtext, text);
        raw->content.text = rtext;
    } else {
        printf("Not enough virtual memory!\n");
    }
}

void read_raw(vfile *raw, char *buffer) {
    strcpy(buffer, raw->content.text);
}

void del_raw(vfile *raw) {
    rmv_vfile(raw->parent, raw);
    free(raw->content.text);
    free(raw);
}

vfile *new_dir(vfile *parent, char *name) {
    vfile *dir = malloc(sizeof(vfile));

    add_vfile(parent, dir);
    if (rename_vfile(dir, name) != 0) {
        return NULL;
    }

    dir->content.subf = NULL;
    dir->type = DIR_TYPE;
    dir->count = 0;

    return dir;
}

void add_vfile(vfile *dir, vfile *vf) {
    vfile **subf;
    subf = (vfile **) realloc(dir->content.subf,
        (++dir->count) * sizeof(vfile *));
    if (subf) {
        subf[dir->count-1] = vf;
        dir->content.subf = subf;
        vf->parent = dir;
    }
    else {
        printf("Not enough virtual memory!\n");
    }
}

void rmv_vfile(vfile *dir, vfile *vf) {
    if (!dir) {
        return;
    }

    vfile **subf = dir->content.subf;
    int found = 0;

    for (int i = 0; i < dir->count; i++) {
        if (found) {
            subf[i-1] = subf[i];
        } else if (subf[i] == vf) {
            found = 1;
        }
    }

    if (found) {
        subf = (vfile **) realloc(subf, (--dir->count) * sizeof(vfile *));
        dir->content.subf = subf;
        vf->parent = NULL;
    }
}

void list_dir(vfile *dir) {
    vfile **subf = dir->content.subf;
    for (int i = 0; i < dir->count; i++) {
        printf("%s\t", subf[i]->name);
    }
    if (dir->count) {
        printf("\n");
    }
}

vfile *get_vfile(vfile *dir, char *name) {
    vfile **subf = dir->content.subf;
    if (strcmp(name, ".") == 0) {
        return dir;
    } else if (strcmp(name, "..") == 0) {
        if (dir->parent) {
            return dir->parent;
        } else {
            return dir;  // root
        }
    }
    for (int i = 0; i < dir->count; i++) {
        if (strcmp(subf[i]->name, name) == 0) {
            return subf[i];
        }
    }
    return NULL;
}

void del_dir(vfile *dir) {
    vfile **subf = dir->content.subf;
    for (int i = 0; i < dir->count; i++) {
        del_vfile(subf[i]);
    }
    rmv_vfile(dir->parent, dir);
    free(dir);
}
