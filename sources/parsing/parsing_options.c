/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:24:20 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 15:18:54 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	optimization(uint16_t *options, int bit)
{
	if (bit == 2)
	{
		*options &= ~OPTION_M;
		*options &= ~OPTION_ONE;
	}
	else if (bit == 5)
	{
		*options &= ~OPTION_L;
		*options &= ~OPTION_M;
	}
	else if (bit == 6)
	{
		*options &= ~OPTION_L;
		*options &= ~OPTION_ONE;
	}
	return (0);
}

static int	get_options(uint16_t *options, char *argv)
{
	int		i;

	while (*(++argv))
	{
		if ((i = ft_strchr_index(AVAILABLE_OPTIONS, *argv)) == -1)
			ls_log(ERROR_OPTIONS, argv);
		optimization(options, i);
		*options |= (1 << i);
	}
	return (0);
}

int			parsing_options(uint16_t *options, int argc, char **argv)
{
	int		i;

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
