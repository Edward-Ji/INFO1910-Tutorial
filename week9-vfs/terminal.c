#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vfs.h"

#define BUFFERLEN 1024

int main(int argc, char const *argv[]) {

    vfile *root = new_root();
    vfile *file_a = new_raw(root, "file_a");
    vfile *dir_a = new_dir(root, "dir_a");
    vfile *dir_a_x = new_dir(dir_a, "dir_x");
    vfile *file_b = new_raw(dir_a, "file_b");

    // test read and write raw file
    char *buffer = malloc(BUFFERLEN * sizeof(char));
    fgets(buffer, BUFFERLEN, stdin);
    write_raw(file_b, buffer);
    memset(buffer, 0, BUFFERLEN);
    read_raw(file_b, buffer);
    printf("%s", buffer);

    list_dir(root);
    list_dir(dir_a);

    del_root(root);

    return 0;
}
