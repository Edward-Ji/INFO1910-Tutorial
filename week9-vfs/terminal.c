#include <stdio.h>
#include "vfs.h"

int main(int argc, char const *argv[]) {

    vfile *root = new_root();
    vfile *file_a = new_raw(root, "file_a");

    list_dir(root);

    del_root(root);

    return 0;
}
