/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:31:48 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 16:04:44 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			put_list_option_m(t_ls **ls, uint16_t options)
{
	t_ls			*temporary;

	temporary = *ls;
	while (temporary)
	{
		if (options & OPTION_S)
		{
			ft_putnbr(temporary->stats.blocks);
			write(1, " ", 1);
		}
		ft_putstr(temporary->name);
		if ((temporary = temporary->next))
			write(1, ", ", 2);
	}
	return (0);
}

int					put_list(t_ls **ls, uint16_t *options,
		int level, int parent_mode)
{
	sorting(ls, *options);
	*options |= OPTION_ITER;
	if (*options & OPTION_L)
		put_detailed_list(*ls, *options, level, parent_mode);
	else if (*options & OPTION_M)
		put_list_option_m(ls, *options);
	else
		put_basic_list(*ls, *options);
	if ((*options & OPTION_M) || (*options & OPTION_L))
		write(1, "\n", 1);
	return (0);
}
