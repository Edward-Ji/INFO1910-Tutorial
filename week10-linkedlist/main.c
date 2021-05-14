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

    node *list1 = NULL;

    node node1_0;
    set_node(&node1_0, literal1[0]);
    list1 = append(list1, &node1_0);

    node node1_1;
    set_node(&node1_1, literal1[1]);
    list1 = append(list1, &node1_1);

    node node1_2;
    set_node(&node1_2, literal1[2]);
    list1 = append(list1, &node1_2);

    node node1_3;
    set_node(&node1_3, literal1[3]);
    list1 = append(list1, &node1_3);

    node node1_4;
    set_node(&node1_4, literal1[4]);
    list1 = append(list1, &node1_4);

    printf("%d\n", length(list1));

    printf("%d\n", contains(list1, 'l'));

    for (int i = 0; i < MAXLEN; i++) {
        printf("%c", getelem(list1, i));
    }
    printf("\n");

    // insert
    node node5;
    set_node(&node5, '!');
    list1 = insert(list1, &node5, 5);

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
    set_node(&head2, literal2[0]);

    node *list2 = &head2;

    node node2_1;
    set_node(&node2_1, literal2[1]);
    list2 = append(list2, &node2_1);

    node node2_2;
    set_node(&node2_2, literal2[2]);
    list2 = append(list2, &node2_2);

    node node2_3;
    set_node(&node2_3, literal2[3]);
    list2 = append(list2, &node2_3);

    node node2_4;
    set_node(&node2_4, literal2[4]);
    list2 = append(list2, &node2_4);

    node node2_5;
    set_node(&node2_5, literal2[5]);
    list2 = append(list2, &node2_5);

    node node2_6;
    set_node(&node2_6, literal2[6]);
    list2 = append(list2, &node2_6);

    printf("\n second list\n");

    for (int i = 0; i < MAXLEN; i++) {
        printf("%c", getelem(list2, i));
    }
    printf("\n");

    list1 = extend(list1, list2);

    printf("\n extended\n");

    printf("%d\n", length(list1));

    for (int i = 0; i < MAXLEN; i++) {
        printf("%c", getelem(list1, i));
    }
    printf("\n");

    // edge case: empty list
    node *list3 = NULL;

    list3 = extend(list3, list1);

    printf("\n extended empty list\n");

    for (int i = 0; i < MAXLEN; i++) {
        printf("%c", getelem(list3, i));
    }
    printf("\n");

    return 0;
}
