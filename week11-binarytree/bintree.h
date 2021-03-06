/*
 * An implementation of binary tree in repsonse to week 11 content of the
 * INFO1910 course. This course deos not introduce malloc like functions, so
 * nodes are declared in the main stackframe, instead of being dynamically
 * allocated.
 */

#include <stddef.h>

/*
 * Each node contain 1 byte of data and reference to two other nodes, called
 * its left child and right child.
 * Struct definition must be included because nodes are declarad and initiated
 * in main stackframe.
 */
typedef struct _bt_node {
    char elem;
    struct _bt_node *left_child;
    struct _bt_node *right_child;
} bt_node;

/*
 * Set element component to given char. Set both children to point to NULL.
 */
void bt_node_init(bt_node *, char);

/*
 * Setter funciton for the left and right node.
 */
void bt_node_setl(bt_node *, bt_node *);
void bt_node_setr(bt_node *, bt_node *);

/*
 * Given a root node, return the total number of nodes in its branch. This
 * include itself, its immediate chilren and all subsequent children.
 */
int bt_size(bt_node *);

/*
 * Given a root node, return the depth of its branch. The depth is defined to be
 * the total number of steps in the longest chain from that node. So the root
 * node is considered to be at depth 0, its children at depth 1...
 */
int bt_depth(bt_node *);

/*
 * Given a certain depth, return the maximum possible number of nodes at that
 * depth. This function is independent of an actual binary tree.
 */
int bt_max_layer_size(int);

/*
 * ================================ Traversal ================================
 *
 * In this library, to visit a node means printing out its element as a
 * character.
 */

/*
 * Given a node, pre-order traverse through its subtree. Visit the current node
 * first, then pre-order traverse its left child, then pre-order traverse its
 * right child.
 */
void bt_pre_order(bt_node *);

/*
 * Given a node, in-order traverse through its subtree. First, in-order traverse
 * its left child, then visit the current node, and in-order traverse its right
 * child last.
 */
void bt_in_order(bt_node *);

/*
 * Given a node, post-order traverse through its subtree. First, post-order
 * traverse left child of the current node, then post-order traverse its right
 * child. Lastly, visit the that node.
 */
void bt_post_order(bt_node *);

/*
 * Given a node, perform a breath first search on its branch. Breath first
 * search works by keeping a list of nodes called fringe, and performing the
 * following steps:
 * (1) Put the root node in the fringe;
 * (2) Remove the first node from the fringe and visit it;
 * (3) Add all the children of the node in step (2) to the end of the fringe;
 * (4) Repeat steps (2) and (3) until the fringe is empty.
 */
 void bt_fbs(bt_node *);
