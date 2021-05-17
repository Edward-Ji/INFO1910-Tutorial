#include <stdio.h>
#include "bintree.h"

int main(int argc, char const *argv[]) {

    bt_node root, *ptr_root;
    ptr_root = &root;

    bt_node_init(ptr_root, 'A');

    bt_node node_l, node_r, node_l_l, node_l_r, node_r_l, node_r_r, node_r_r_r;

    bt_node_init(&node_l, 'B');
    bt_node_setl(ptr_root, &node_l);

    bt_node_init(&node_r, 'C');
    bt_node_setr(ptr_root, &node_r);

    bt_node_init(&node_l_l, 'D');
    bt_node_setl(&node_l, &node_l_l);

    bt_node_init(&node_l_r, 'E');
    bt_node_setr(&node_l, &node_l_r);

    bt_node_init(&node_r_l, 'F');
    bt_node_setl(&node_r, &node_r_l);

    bt_node_init(&node_r_r, 'G');
    bt_node_setr(&node_r, &node_r_r);

    // bt_node_init(&node_r_r_r, 'H');
    // bt_node_setr(&node_r_r, &node_r_r_r);

    printf("size : %d\n", bt_size(ptr_root));

    printf("depth: %d\n", bt_depth(ptr_root));

    printf("max size: %d\n", bt_max_layer_size(3));

    printf("Pre-order traversal\n");
    bt_pre_order(ptr_root);
    printf("\n");

    printf("In-order traversal\n");
    bt_in_order(ptr_root);
    printf("\n");

    printf("Post-order traversal\n");
    bt_post_order(ptr_root);
    printf("\n");

    printf("First breath search\n");
    bt_fbs(ptr_root);
    printf("\n");

    return 0;
}
