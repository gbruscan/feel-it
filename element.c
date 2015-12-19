/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:02:42 by gbruscan          #+#    #+#             */
/*   Updated: 2015/12/16 18:23:40 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_x(char **tab)
{
	int		size;
	int		i;
	int		j;

	size = 0;
	j = 0;
	i = 0;
	while (tab[i] && tab[i][j])
	{
		if (tab[i] && tab[i][j] && tab[i][j] == '.' && tab[i + 1][j] != '.')
			i += 1;
		while (tab[i] && tab[i][j] && tab[i][j] != '.')
			i++;
		if (i > size)
			size = i;
		i = 0;
		j++;
	}
	return (size);
}

int		ft_get_y(char **tab)
{
	int		size;
	int		i;
	int		j;

	i = 0;
	size = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] && tab[i][j] == '.' && tab[i][j + 1] != '.')
			j += 1;
		while (tab[i][j] && tab[i][j] != '.')
			j++;
		if (j > size)
			size = j;
		i++;
	}
	return (size);
}

void	get_xy(t_tlist *list)
{
	while (list)
	{
		list->y = ft_get_x(list->tab) - 1;
		list->x = ft_get_y(list->tab) - 1;
		list = list->next;
	}
}
