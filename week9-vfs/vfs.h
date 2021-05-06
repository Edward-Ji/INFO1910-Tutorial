// virtual file structure
typedef struct _vfile vfile;

// functions for all virtual file type
void move_vfile(vfile *vf, vfile *new_dir);
void del_vfile(vfile *vf);

// functions certain type of virtual file
vfile *new_raw(vfile *parent, char *name);
void write_raw(vfile *raw, char *text);
void read_raw(vfile *raw, char *buffer);
void del_raw(vfile *raw);

vfile *new_dir(vfile *parent, char *name);
void add_vfile(vfile *dir, vfile *vf);
void rmv_vfile(vfile *dir, vfile *vf);
void list_dir(vfile *dir);
void del_dir(vfile *dir);

vfile *new_root();
void del_root(vfile *root);
