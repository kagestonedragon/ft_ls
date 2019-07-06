#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../ft_ls.h"

t_dir               *init_root_directory(void)
{
    t_dir           *start;
    t_dir           *d;

    d = (t_dir *)malloc(sizeof(t_dir));
    start = d;
    d->info.level = 0;
    d->father = NULL;
    d->info.full_path = ft_strdup(".");
    d->info.type = DT_DIR;
    d->info.name = ft_strdup(".");
    d->next = (t_dir *)malloc(sizeof(t_dir));
    d->next->info.full_path = ft_strdup("..");
    d->next->info.level = 0;
    d->next->info.type = DT_DIR;
    d->next->info.name = ft_strdup("..");
    d->father = NULL;
    d->next->next = NULL;
    return (start);
}

char                *create_full_path(char *s1, char *s2, char *s3)
{
    char            *t1;
    char            *t2;

    t1 = ft_strjoin(s1, s2);
    t2 = ft_strjoin(t1, s3);
    free(t1);
    return (t2);
}

t_dir               *add_dir(t_dir *previous, t_dir *father, struct dirent *entry)
{
    t_dir           *n;

    n = (t_dir *)malloc(sizeof(t_dir));
    n->info.level = father->info.level;
    n->info.full_path = create_full_path(father->info.full_path, "/", entry->d_name);
    n->info.name = ft_strdup(entry->d_name);
    n->info.type = entry->d_type;
    n->father = father;
    n->next = NULL;
    previous->next = n;
    return (n);
}

t_dir               *reading(t_dir *d)
{
    DIR             *catalog;
    struct dirent   *entry;
    t_dir           *child;
    t_dir           *father;

    child = d;
    father = d;
    while (father)
    {
        if ((catalog = opendir(father->info.full_path)))
        {
            while ((entry = readdir(catalog)))
            {
                child = add_dir(child, father, entry);
                if (!ft_strncmp(entry->d_name, ".", 1))

            }
            closedir(catalog);
        }
        father = father->next;
    }
    return (d);
}