#include "linkedlist.h"

#ifndef NULL
#define NULL ((void *) 0)
#endif

typedef struct _node {
    char elem;
    struct _node *next;
} node;

void make_node(node *new, char elem) {
    new->elem = elem;
    new->next = NULL;
}

void append(node *list, node *new) {
    if (list != NULL) {
        while (list->next != NULL) {
            list = list->next;
        }
        list->next = new;
    }
}

int length(node *list) {
    int count = 0;
    while (list != NULL) {
        list = list->next;
        count++;
    }
    return count;
}

int contains(node *list, char elem) {
    int index = 0;
    while (list != NULL) {
        if (list->elem == elem) {
            return index;
        }
        list = list->next;
        index++;
    }
    return -1;
}

char getelem(node *list, int index) {
    while (list != NULL) {
        if (index-- == 0) {
            return list->elem;
        }
        list = list->next;
    }
    return (char) 0;
}

void insert(node *list, node *new, int index) {
    if (list != NULL && index >= 1) {
        while (--index > 0 && list->next) {
            list = list->next;
        }
        new->next = list->next;
        list->next = new;
    }
}

char popelem(node *list, int index) {
    if (index >= 1) {
        node *prev;
        while (list != NULL) {
            if (index-- == 0) {
                prev->next = list->next;
                return list->elem;
            }
            prev = list;
            list = list->next;
        }
    }
    return (char) 0;
}

void extend(node *list1, node *list2) {
    if (list1 != NULL) {
        while (list1->next != NULL) {
            list1 = list1->next;
        }
        list1->next = list2;
    }
}
