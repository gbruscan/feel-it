/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:54:32 by ndauteui          #+#    #+#             */
/*   Updated: 2015/12/16 18:24:06 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_max_col(char **tab)
{
	int		size;
	int		last_char_pos;
	int		i;
	int		j;

	size = 0;
	last_char_pos = 0;
	j = 0;
	i = 0;
	while (tab[i] && tab[i][j])
	{
		while (tab[i] && tab[i][j])
		{
			if (tab[i][j] != '.')
				last_char_pos = i;
			i++;
		}
		if (last_char_pos > size)
			size = last_char_pos;
		i = 0;
		j++;
	}
	return (size + 1);
}

int		ft_get_max_line(char **tab)
{
	int		size;
	int		i;
	int		j;
	int		last_char_pos;

	i = 0;
	last_char_pos = 0;
	size = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != '.')
				last_char_pos = j;
			j++;
		}
		if (last_char_pos > size)
			size = last_char_pos;
		i++;
	}
	return (size + 1);
}

int		ft_get_square_size(char **tab)
{
	int		line_max;
	int		col_max;

	line_max = ft_get_max_line(tab);
	col_max = ft_get_max_col(tab);
	if (line_max > col_max)
		return (line_max);
	return (col_max);
}
