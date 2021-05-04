// virtual file structure
typedef struct _vfile vfile;

// virtual file functions
void move_vfile(vfile *vf, vfile *new_dir);
void del_vfile(vfile *vf);

// constructors and destructors for
// raw file, directory and root directory
vfile *new_raw(vfile *parent, char *name);
void write_raw(vfile *raw, char *text);
void del_raw(vfile *raw);

vfile *new_dir(vfile *parent, char *name);
void add_vfile(vfile *dir, vfile *new_file);
void rmv_vfile(vfile *dir, vfile *old_file);
void list_dir(vfile *dir);
void del_dir(vfile *dir);

vfile *new_root();
void del_root(vfile *root);
