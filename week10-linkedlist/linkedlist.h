#include <stddef.h>

typedef struct _node node;

void set_node(node *, char);

node *append(node *, node *);

int length(node *);

int contains(node *, char);

char getelem(node *, size_t);

node *insert(node *, node *, size_t);

char popelem(node *, size_t);

node *extend(node *, node *);
