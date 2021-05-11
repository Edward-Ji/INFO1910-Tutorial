#include <stdio.h>
#include "linkedlist.h"

#ifndef MAXLEN
#define MAXLEN 20
#endif

typedef struct _node {
    char elem;
    struct _node *next;
} node;

int main(int argc, char const *argv[]) {

    char *literal1 = "Hello";

    node head1;
    make_node(&head1, literal1[0]);

    node *list1 = &head1;

    node node1_1;
    make_node(&node1_1, literal1[1]);
    append(list1, &node1_1);

    node node1_2;
    make_node(&node1_2, literal1[2]);
    append(list1, &node1_2);

    node node1_3;
    make_node(&node1_3, literal1[3]);
    append(list1, &node1_3);

    node node1_4;
    make_node(&node1_4, literal1[4]);
    append(list1, &node1_4);

    printf("%d\n", length(list1));

    printf("%d\n", contains(list1, 'l'));

    for (int i = 0; i < MAXLEN; i++) {
        printf("%c", getelem(list1, i));
    }
    printf("\n");

    // insert
    node node5;
    make_node(&node5, '!');
    insert(list1, &node5, 5);

    printf("\n inserted\n");

    printf("%d\n", length(list1));

    for (int i = 0; i < MAXLEN; i++) {
        printf("%c", getelem(list1, i));
    }
    printf("\n");

    // pop element
    char c = popelem(list1, 1);

    printf("\n popped %c\n", c);

    printf("%d\n", length(list1));

    for (int i = 0; i < MAXLEN; i++) {
        printf("%c", getelem(list1, i));
    }
    printf("\n");

    // extend
    char *literal2 = " world!";

    node head2;
    make_node(&head2, literal2[0]);

    node *list2 = &head2;

    node node2_1;
    make_node(&node2_1, literal2[1]);
    append(list2, &node2_1);

    node node2_2;
    make_node(&node2_2, literal2[2]);
    append(list2, &node2_2);

    node node2_3;
    make_node(&node2_3, literal2[3]);
    append(list2, &node2_3);

    node node2_4;
    make_node(&node2_4, literal2[4]);
    append(list2, &node2_4);

    node node2_5;
    make_node(&node2_5, literal2[5]);
    append(list2, &node2_5);

    node node2_6;
    make_node(&node2_6, literal2[6]);
    append(list2, &node2_6);

    printf("\n second list\n");

    for (int i = 0; i < MAXLEN; i++) {
        printf("%c", getelem(list2, i));
    }
    printf("\n");

    extend(list1, list2);

    printf("\n extended\n");

    printf("%d\n", length(list1));

    for (int i = 0; i < MAXLEN; i++) {
        printf("%c", getelem(list1, i));
    }
    printf("\n");

    return 0;
}
