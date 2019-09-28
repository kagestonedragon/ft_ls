#include "ft_ls.h"
#include <stdlib.h>

int 		ls_free(t_ls **ls)
{
	while (*ls)
	{
		free((*ls)->name);
		free(*ls);
		*ls = (*ls)->next;
	}
	return (0);
}