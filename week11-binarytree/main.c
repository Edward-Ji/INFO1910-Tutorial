#include <stdio.h>
#include "bintree.h"

int main(int argc, char const *argv[]) {

    bt_node root, *ptr_root;
    ptr_root = &root;

    bt_node_init(ptr_root, 'A');

    bt_node node_l, node_r, node_l_l, node_l_r, node_r_l, node_r_r;

    bt_node_init(&node_l, 'B');
    bt_node_addl(ptr_root, &node_l);

    bt_node_init(&node_r, 'C');
    bt_node_addr(ptr_root, &node_r);

    bt_node_init(&node_l_l, 'D');
    bt_node_addl(&node_l, &node_l_l);

    bt_node_init(&node_l_r, 'E');
    bt_node_addr(&node_l, &node_l_r);

    bt_node_init(&node_r_l, 'F');
    bt_node_addl(&node_r, &node_r_l);

    bt_node_init(&node_r_r, 'G');
    bt_node_addr(&node_r, &node_r_r);

    printf("%d\n", bt_size(ptr_root));

    return 0;
}
