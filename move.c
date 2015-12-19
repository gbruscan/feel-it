/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:44:15 by gbruscan          #+#    #+#             */
/*   Updated: 2015/12/19 10:59:38 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft/libft.h"

void	column_move(t_tlist **elem)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		while (i < 4 && (*elem)->tab[i][j] == '#')
		{
			i++;
			if (i == 4)
			{
				i = 0;
				while (i < 4)
				{
					ft_strcpy((*elem)->tab[i], "#...");
					i++;
				}
				return ;
			}
		}
		j++;
	}
}

void	left_move_helper(t_tlist **elem, int i, int j)
{
	char	c;

	while (i < 4 && (*elem)->tab[i][j] != '#')
	{
		i++;
		if (i == 4)
		{
			i = 0;
			while (i < 4)
			{
				c = (*elem)->tab[i][j];
				while (j < 3)
				{
					(*elem)->tab[i][j] = (*elem)->tab[i][j + 1];
					j++;
				}
				(*elem)->tab[i][3] = c;
				j = 0;
				i++;
			}
			i = 0;
		}
	}
}

void	left_move(t_tlist **elem)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (k < 2)
	{
		left_move_helper(elem, i, j);
		k++;
	}
}

void	upper_move(t_tlist **elem)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	column_move(elem);
	while (k < 3)
	{
		if (ft_strcmp((*elem)->tab[i], "....") == 0)
		{
			i = 1;
			while (i < 4)
			{
				ft_strcpy((*elem)->tab[i - 1], (*elem)->tab[i]);
				i++;
			}
			(*elem)->tab[3] = ft_strcpy((*elem)->tab[3], "....");
			i = 0;
		}
		k += 1;
	}
	return (left_move(elem));
}
