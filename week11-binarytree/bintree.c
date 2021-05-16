#include "bintree.h"

void bt_node_init(bt_node *node, char elem) {
    node->elem = elem;
    node->left_child = NULL;
    node->right_child = NULL;
}

void bt_node_addl(bt_node *parent, bt_node *child) {
    parent->left_child = child;
}

void bt_node_addr(bt_node *parent, bt_node *child) {
    parent->right_child = child;
}

int bt_size(bt_node *node) {
    int count = 1;
    if (node->left_child != NULL) {
        count += bt_size(node->left_child);
    }
    if (node->right_child != NULL) {
        count += bt_size(node->right_child);
    }
    return count;
}
