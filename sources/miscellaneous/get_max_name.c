/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:20:13 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 13:20:22 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_max_name(t_ls *lst)
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
