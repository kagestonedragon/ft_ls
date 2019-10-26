/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:17:55 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 13:18:40 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					main(int argc, char **argv)
{
	int				i;
	t_ls			*ls;
	uint16_t		options;

	i = parsing_options(&options, argc, argv);
	ls = parsing_input(argc - i, argv + i, &options);
	put(ls, options, 1);
	ls_free(&ls);
	return (0);
}
