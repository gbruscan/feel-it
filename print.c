/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 14:19:33 by gbruscan          #+#    #+#             */
/*   Updated: 2015/12/19 14:23:07 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	ft_print_map(t_data *map)
{
	int x;
	int	y;

	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			ft_putchar(map->map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int		ft_print_error(void)
{
	ft_putendl("error");
	return (0);
}
