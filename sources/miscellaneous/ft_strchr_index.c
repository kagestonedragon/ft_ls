/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:19:01 by emedea            #+#    #+#             */
/*   Updated: 2019/09/28 13:19:07 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strchr_index(char *string, char character)
{
	int		i;

	i = -1;
	while (string[++i])
		if (string[i] == character)
			return (i);
	return (-1);
}
