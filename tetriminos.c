/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 17:06:01 by gbruscan          #+#    #+#             */
/*   Updated: 2015/12/20 11:46:14 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		check_sharp_helper(char **tab, int i, int j, int k)
{
	if (k != 4 && check_left(tab, i + 1, j - 1) == 1)
		k += 1;
	if (k != 4 && check_under(tab, i + 1, j - 1) == 1)
		k += 1;
	return (k);
}

int		check_sharp(char **tab, int i, int j, int k)
{
	if (k != 4 && check_right(tab, i, j) == 1)
	{
		k += 1;
		if (k != 4 && check_under(tab, i, j) == 1)
		{
			k += 1;
			if (k != 4 && check_left(tab, i + 1, j) == 1)
				k += 1;
			if (k != 4 && check_under(tab, i + 1, j) == 1)
				k += 1;
		}
		return (check_sharp(tab, i, j + 1, k));
	}
	else if (k != 4 && check_under(tab, i, j))
	{
		k += 1;
		if (k != 4 && check_left(tab, i + 1, j) == 1)
		{
			k += 1;
			check_sharp_helper(tab, i, j, k);
		}
		return (check_sharp(tab, i + 1, j, k));
	}
	return (k);
}

int		check_tetrimino(char **tab)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 1;
	while (tab[i])
	{
		while (j <= 3)
		{
			if (tab[i][j] == '#')
			{
				k = check_sharp(tab, i, j, k);
				if (k != 4)
					return (0);
				else
					return (1);
			}
			j++;
		}
		i += 1;
		j = 0;
	}
	return (0);
}

int		check_all_tetriminos(t_tlist *list)
{
	int		counter;

	counter = 0;
	while (list)
	{
		if (check_tetrimino(list->tab) == 0)
			return (0);
		list = list->next;
		counter++;
	}
	if (counter >= 27)
		return (0);
	return (1);
}
