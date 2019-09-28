#include "ft_ls.h"

static int	get_options(uint16_t *options, char *argv)
{
	int 	i;

	while (*(++argv))
	{
		if ((i = ft_strchr_index(AVAILABLE_OPTIONS, *argv)) == -1)
			ls_log(ERROR_OPTIONS, argv);
		*options |= (1 << i);
	}
	return (0);
}

int 		parsing_options(uint16_t *options, int argc, char **argv)
{
	int 	i;

	*options = 0;
	i = 0;
	while (++i < argc && argv[i][0] == '-' && argv[i][1])
	{
		if (argv[i][0] == '-' && argv[i][1] == '-' && !argv[i][2])
			return (i + 1);
		get_options(options, argv[i]);
	}
	return (i);
}