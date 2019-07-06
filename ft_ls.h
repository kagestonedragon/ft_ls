#ifndef FT_LS_H
# define FT_LS_H

typedef enum{
        false,
        true
}       t_bool;

typedef struct      s_info{
    int             level;
    char            *full_path;
    char            *name;
    int             type;
}                   t_info;

typedef struct		s_dir{
    t_info          info;
    struct s_dir    *father;
    struct s_dir	*next;
}					t_dir;

t_dir               *reading(t_dir *d);
void                print_reverse(t_dir *child, t_dir *father);
void                print_all(t_dir *child, t_dir *father);

# endif
