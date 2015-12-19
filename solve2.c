/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 17:36:14 by ndauteui          #+#    #+#             */
/*   Updated: 2015/12/19 10:59:51 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft/libft.h"

void	ft_filler(t_tlist *elem, t_data *map)
{
	int	a;
	int	b;

	a = 0;
	while (a <= elem->y)
	{
		b = 0;
		while (b <= elem->x)
		{
			if (elem->tab[a][b] == elem->c)
				map->map[elem->a + a][elem->b + b] = elem->c;
			b++;
		}
		a++;
	}
}

char	ft_check_pos(t_tlist *elem, t_data *map)
{
	int a;
	int b;
	int counter;

	counter = 0;
	a = 0;
	while (a <= elem->y)
	{
		b = 0;
		while (b <= elem->x)
		{
			if (map->map[elem->a + a][elem->b + b] == '.'
					&& elem->tab[a][b] == elem->c)
				counter++;
			if (counter == 4)
			{
				ft_filler(elem, map);
				return (1);
			}
			b++;
		}
		a++;
	}
	return (0);
}

void	ft_defiller(t_tlist *elem, t_data *map)
{
	int a;
	int b;

	a = 0;
	while (a <= elem->y)
	{
		b = 0;
		while (b <= elem->x)
		{
			if (map->map[elem->a + a][elem->b + b] == elem->c)
				map->map[elem->a + a][elem->b + b] = '.';
			b++;
		}
		a++;
	}
}
