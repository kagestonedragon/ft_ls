/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:29:30 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 16:04:10 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				put(t_ls *ls, uint16_t options, int level)
{
	t_ls		*parent;

	if (!(options & OPTION_RR) && (options & OPTION_ITER))
		return (0);
	parent = ls;
	while (parent)
	{
		if ((ft_strcmp(parent->name, "..") &&
					ft_strcmp(parent->name, ".")) || level == 1)
			put_input_name(parent, &options, level);
		if ((ft_strcmp(parent->name, "..") &&
					ft_strcmp(parent->name, ".")) || level == 1)
		{
			ls = (S_ISDIR(parent->stats.mode)) ?
				parsing_directory(parent->fpath, options) : NULL;
			if (ls)
			{
				put_list(&ls, &options, level, parent->stats.mode);
				put(ls, options, level + 1);
				ls_free(&ls);
			}
		}
		parent = parent->next;
	}
	return (0);
}
