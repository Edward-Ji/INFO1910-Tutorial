typedef struct _node node;

void make_node(node *, char);

void append(node *, node *);

int length(node *);

int contains(node *, char);

char getelem(node *, int);

void insert(node *, node *, int);

char popelem(node *, int);

void extend(node *, node *);
