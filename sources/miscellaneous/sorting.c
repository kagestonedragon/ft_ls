/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:20:38 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 13:21:13 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_ls		*swap(t_ls *ls1, t_ls *ls2)
{
	ls1->next = ls2->next;
	ls2->next = ls1;
	return (ls2);
}

static t_ls		*sorting_time(t_ls *ls)
{
	if (!ls)
		return (NULL);
	if (ls->next && (ls->stats.time < ls->next->stats.time))
		ls = swap(ls, ls->next);
	else if (ls->next && ls->stats.time == ls->next->stats.time)
		if (ls->next && (ls->stats.ntime < ls->next->stats.ntime))
			ls = swap(ls, ls->next);
	ls->next = sorting_time(ls->next);
	if (ls->next && (ls->stats.time < ls->next->stats.time))
	{
		ls = swap(ls, ls->next);
		ls->next = sorting_time(ls->next);
	}
	else if (ls->next && ls->stats.time == ls->next->stats.time)
	{
		if (ls->next && (ls->stats.ntime < ls->next->stats.ntime))
		{
			ls = swap(ls, ls->next);
			ls->next = sorting_time(ls->next);
		}
	}
	return (ls);
}

static t_ls		*sorting_ascii(t_ls *ls)
{
	if (!ls)
		return (NULL);
	if (ls->next && ft_strcmp(ls->name, ls->next->name) > 0)
		ls = swap(ls, ls->next);
	ls->next = sorting_ascii(ls->next);
	if (ls->next && ft_strcmp(ls->name, ls->next->name) > 0)
	{
		ls = swap(ls, ls->next);
		ls->next = sorting_ascii(ls->next);
	}
	return (ls);
}

static t_ls		*sorting_reverse(t_ls *ls)
{
	t_ls		*temporary;
	t_ls		*next;
	t_ls		*previous;

	temporary = ls;
	previous = NULL;
	while (temporary)
	{
		next = temporary->next;
		temporary->next = previous;
		previous = temporary;
		temporary = next;
	}
	return (previous);
}

int				sorting(t_ls **ls, int options)
{
	*ls = sorting_ascii(*ls);
	if (options & OPTION_T)
		*ls = sorting_time(*ls);
	if (options & OPTION_R)
		*ls = sorting_reverse(*ls);
	return (0);
}
