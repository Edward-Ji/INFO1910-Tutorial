#include <stddef.h>

typedef struct _bt_node {
    char elem;
    struct _bt_node *left_child;
    struct _bt_node *right_child;
} bt_node;

void bt_node_init(bt_node *, char);

void bt_node_addl(bt_node *, bt_node *);
void bt_node_addr(bt_node *, bt_node *);

int bt_size(bt_node *);
