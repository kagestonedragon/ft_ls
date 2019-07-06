#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../ft_ls.h"

void            print_reverse(t_dir *child, t_dir *father)
{
    if (child->father == father)
    {
        print_reverse(child->next, father);
        printf("%s\t\t\t", child->info.name);
    }
}

void            print_all(t_dir *child, t_dir *father)
{
    if (child->father == father)
    {
        printf("%s\t\t\t", child->info.name);
        print_all(child->next, father);
    }
}