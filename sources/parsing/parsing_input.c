#include "ft_ls.h"

t_ls		*parsing_input(int argc, char **argv, uint16_t *options)
{
	t_ls	*ls;
	int 	i;

	ls = NULL;
	i = -1;
	if (!argc || argc == 1)
		*options |= OPTION_INPUT;
	if (argv[0])
		while (argv[++i])
			parsing_entry(&ls, "", argv[i]);
	else
		parsing_entry(&ls, "", ".");
	sorting(&ls, *options);
	return (ls);
}
