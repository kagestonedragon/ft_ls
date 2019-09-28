#include "ft_ls.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	int 		i;
	t_ls		*ls;
	uint16_t		options;

	i = parsing_options(&options, argc, argv);
	ls = parsing_input(argc - i, argv + i, &options);
	put(ls, options, 1);
	ls_free(&ls);
	return (0);
}