#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vfs.h"

#define NAME_LEN 256

#define RAW_TYPE 1  // indicate raw text vfile type
#define DIR_TYPE 2  // indicate directory vfile type

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

void move_vfile(vfile *vf, vfile *dir) {
    if (vf->parent) {
        rmv_vfile(vf->parent, vf);
        add_vfile(vf->parent, vf);
        vf->parent = dir;
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
    strcpy(raw->name, name);
    raw->content.text = NULL;
    raw->type = RAW_TYPE;
    raw->count = 0;

    return raw;
}

void write_raw(vfile *raw, char *text) {

}

void del_raw(vfile *raw) {
    free(raw);
}

vfile *new_dir(vfile *parent, char *name) {
    vfile *dir = malloc(sizeof(vfile));

    add_vfile(parent, dir);
    strcpy(dir->name, name);
    dir->content.subf = NULL;
    dir->type = DIR_TYPE;
    dir->count = 0;

    return dir;
}

void add_vfile(vfile *dir, vfile *new_file) {
    vfile **subf = dir->content.subf;
    size_t count = dir->count;

    vfile **new_subf;
    new_subf = (vfile **) realloc(subf, (count+1) * sizeof(vfile *));
    if (new_subf == NULL) {
        printf("Not enough virtual memory!\n");
        return;
    }

    new_subf[count] = new_file;
    dir->content.subf = new_subf;
    dir->count++;
    new_file->parent = dir;
}

void rmv_vfile(vfile *dir, vfile *old_file) {

}

void list_dir(vfile *dir) {
    vfile **subf = dir->content.subf;
    printf("%zu files in %s\n", dir->count, dir->name);
    for (int i = 0; i < dir->count; i++) {
        printf("%s\t", subf[i]->name);
    }
}

void del_dir(vfile *dir) {
    vfile **subf = dir->content.subf;
    for (int i = 0; i < dir->count; i++) {
        del_vfile(subf[i]);
    }
    free(dir);
}

vfile *new_root() {
    vfile *dir = malloc(sizeof(vfile));

    dir->parent = NULL;
    strcpy(dir->name, "root");
    dir->content.subf = NULL;
    dir->type = DIR_TYPE;
    dir->count = 0;

    return dir;
}

void del_root(vfile *root) {
    del_dir(root);
}
