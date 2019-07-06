#include "../ft_ls.h"
#include "../libft/libft.h"
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

/*void                printR(t_dir *dir)
{
    t_dir           *temp;
    t_dir           *temp2;
    int             print;

    temp = dir;
    temp = temp->next;
    temp2 = temp;
    while (temp->level == 1)
    {
        printf("%s ", temp->d_name);
        temp = temp->next;
    }
    printf("\n");
    while (temp2)
    {
        if (temp2->d_type == DT_DIR)
        {
            print = 0;
            printf("\n%s:\n", temp2->path);
            while (temp && ft_strncmp(temp->path, temp2->path, ft_strlen(temp2->path)) == 0 && (temp2->level + 1) == (temp->level))
            {
                printf("%s ", temp->d_name);
                temp = temp->next;
                print = 1;
            }
            (print) ? printf("\n") : 0;
        }
        temp2 = temp2->next;
    }
}*/

void                print_test(t_dir *d)
{
    t_dir           *temp;

    temp = d;
    while (temp)
    {
        printf("%s ", temp->info.full_path);
        temp = temp->next;
    }
}


/*
 * Print lr -R "file"
 */
void                print_recursively_list(t_dir *d)
{
    t_dir           *child;
    t_dir           *father;

    child = d->next;
    father = d;
    while (child->father == father)
    {
        printf("%s ", child->info.name);
        child = child->next;
    }
    father = father->next;
    while (father)
    {
        if (father->info.type == DT_DIR)
        {
            printf("\n%s:\n", father->info.full_path);
            while (child && father == child->father)
            {
                printf("%s ", child->info.name);
                child = child->next;
            }
        }
        father = father->next;
    }
}

int					main(int argc, char **argv)
{
    DIR				*catalog;
    struct dirent	*entry;
    t_dir			*d;

    catalog = opendir(".");
    entry = readdir(catalog);
    d = (t_dir *)malloc(sizeof(t_dir));
    d->info.level = 0;
    d->father = NULL;
    d->info.full_path = ft_strdup(".");
    d->next = NULL;
    d->info.type = entry->d_type;
    d->info.name = ft_strdup(entry->d_name);
    reading(d);
    //print_test(d);
    print_reverse(d->next, d);
    printf("\n\n");
    print_all(d->next, d);
    //print_recursively_list(d);
    return (0);
}
