#include "ft_ls.h"

static int	put_detailed_input_name(t_ls *ls, uint16_t *options, int level)
{
	t_ls	*temporary;

	temporary = ls->next;
	ls->next = NULL;
	put_detailed_list(ls, level, *options, 0);
	ls->next = temporary;
	return (0);
}

int 		put_input_name(t_ls *ls, uint16_t *options, int level)
{
	if ((*options & OPTION_INPUT) && level == 1)
		return (0);
	if (S_ISREG(ls->stats.mode) && level == 1)
	{
		if ((*options & OPTION_NAME))
			write(1, "\n", 1);
		(*options & OPTION_L) ? put_detailed_input_name(ls, options, level) : ft_putstr(ls->name);
		*options |= OPTION_NAME;
		write(1, "\n", 1);
	}
	else if (S_ISDIR(ls->stats.mode))
	{
		if ((*options & OPTION_NAME))
			write(1, "\n", 1);
		ft_putstr(ls->fpath);
		write(1, ":", 1);
		write(1, "\n", 1);
		*options |= OPTION_NAME;
	}
	return (0);
}