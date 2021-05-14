#include "linkedlist.h"

#ifndef NULL
#define NULL ((void *) 0)
#endif

typedef struct _node {
    char elem;
    struct _node *next;
} node;

void set_node(node *new, char elem) {
    new->elem = elem;
    new->next = NULL;
}

node *append(node *list, node *new) {

    node *current = list;
    if (list != NULL) {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    } else {
        list = new;
    }
    return list;
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

char getelem(node *list, size_t index) {
    while (list != NULL) {
        if (index-- == 0) {
            return list->elem;
        }
        list = list->next;
    }
    return (char) 0;
}

node *insert(node *list, node *new, size_t index) {
    node *current = list;
    if (current != NULL && index != 0) {
        while (--index > 0 && current->next) {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    } else if (index == 0) {
        list = new;
    }
    return list;
}

char popelem(node *list, size_t index) {
    if (index != 0) {
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

node *extend(node *list1, node *list2) {
    node *current = list1;
    if (current != NULL) {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = list2;
    } else {
        list1 = list2;
    }
    return list1;
}
