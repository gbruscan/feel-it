/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:41:27 by ndauteui          #+#    #+#             */
/*   Updated: 2015/12/19 11:15:33 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

t_data			*ft_init_tab(int size)
{
	char	**mapchar;
	t_data	*map;
	int		a;
	int		b;

	a = 0;
	if (!(map = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	if (!(mapchar = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (a < size)
	{
		if (!(mapchar[a] = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		b = 0;
		while (b < size)
		{
			mapchar[a][b] = '.';
			b++;
		}
		a++;
	}
	map->map = mapchar;
	return (map);
}

int				ft_get_min_square(int nb, t_tlist **first)
{
	int			i;
	t_tlist		*tmp;

	i = 0;
	tmp = *first;
	while ((i * i) < (nb * 4))
		i++;
	while (tmp)
	{
		i = i < tmp->a + 1 ? tmp->a + 1 : i;
		i = i < tmp->b + 1 ? tmp->b + 1 : i;
		tmp = tmp->next;
	}
	return (i);
}

char			ft_resolve(t_tlist *elem, t_data *map)
{
	char	ret;

	elem->a = 0;
	while (elem->a + elem->y < map->size)
	{
		elem->b = 0;
		while (elem->b + elem->x < map->size)
		{
			if (ft_check_pos(elem, map))
			{
				if (elem->next)
					ret = ft_resolve(elem->next, map);
				if (!elem->next || ret == 0)
					return (0);
				ft_defiller(elem, map);
			}
			elem->b += 1;
		}
		elem->a += 1;
	}
	return (1);
}

int				ft_solve(t_tlist **first, int nb_tetri)
{
	t_data	*map;

	if (!(map = ft_init_tab(3 + nb_tetri)))
		return (1);
	map->size = ft_get_min_square(nb_tetri, first);
	while (ft_resolve(*first, map))
		map->size += 1;
	ft_print_map(map);
	free(map);
	return (0);
}
