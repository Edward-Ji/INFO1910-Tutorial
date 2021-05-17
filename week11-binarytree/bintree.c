#include <stdio.h>
#include "bintree.h"

void bt_node_init(bt_node *node, char elem) {
    node->elem = elem;
    node->left_child = NULL;
    node->right_child = NULL;
}

void bt_node_setl(bt_node *parent, bt_node *child) {
    parent->left_child = child;
}

void bt_node_setr(bt_node *parent, bt_node *child) {
    parent->right_child = child;
}

int bt_size(bt_node *root) {
    if (root == NULL) {
        return 0;
    }
    return bt_size(root->left_child) + bt_size(root->right_child) + 1;
}

int bt_depth(bt_node *root) {
    if (root == NULL) {
        return -1;
    }
    int depthl = bt_depth(root->left_child);
    int depthr = bt_depth(root->right_child);
    return (depthl > depthr? depthl : depthr) + 1;
}

int bt_max_layer_size(int depth) {
    if (depth <= 0) {
        return 1;
    }
    return 2 * bt_max_layer_size(depth - 1);
}

void bt_pre_order(bt_node *root) {
    if (root != NULL) {
        printf("%c ", root->elem);
        bt_pre_order(root->left_child);
        bt_pre_order(root->right_child);
    }
}

void bt_in_order(bt_node *root) {
    if (root != NULL) {
        bt_in_order(root->left_child);
        printf("%c ", root->elem);
        bt_in_order(root->right_child);
    }
}

void bt_post_order(bt_node *root) {
    if (root != NULL) {
        bt_post_order(root->left_child);
        bt_post_order(root->right_child);
        printf("%c ", root->elem);
    }
}

void bt_fbs(bt_node *root) {
    const int max_layer_size = bt_max_layer_size(bt_depth(root));

    bt_node *fringe[max_layer_size];

    fringe[0] = root;
    for (int i = 1; i < max_layer_size; i++) {
        fringe[i] = NULL;
    }

    int i;
    bt_node *current;

    while (fringe[0] != NULL) {
        // take out the first node in fringe
        i = 0;
        current = fringe[0];

        while (i < max_layer_size && fringe[i] != NULL) {
            fringe[i] = fringe[i+1];
            i++;
        }
        fringe[--i] = NULL;

        // visit that node
        printf("%c ", current->elem);

        // add its children to the fringe
        if (current->left_child != NULL) {
            fringe[i++] = current->left_child;
        }
        if (current->right_child != NULL) {
            fringe[i] = current->right_child;
        }
    }
}
