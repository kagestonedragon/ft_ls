#include "ft_ls.h"

int		get_max_name(t_ls *lst)
{
	int		maxlen;

	maxlen = 0;
	while (lst)
	{
		maxlen = MAX((int)ft_strlen(lst->name), maxlen);
		lst = lst->next;
	}
	return (maxlen);
}