#define RAW_TYPE 1  // indicate raw text vfile type
#define DIR_TYPE 2  // indicate directory vfile type

// virtual file structure
typedef struct _vfile vfile;

// constructor and deconstructor for root directory
// must be called at the start and end of program
void new_root();
void del_root();

// functions for all virtual file type
void abs_path(vfile *vf);
char vfile_type(vfile *vf);
void move_vfile(vfile *vf, vfile *new_dir);
void rename_vfile(vfile *vf, char *name);
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
vfile *get_vfile(vfile *dir, char *name);
void del_dir(vfile *dir);
