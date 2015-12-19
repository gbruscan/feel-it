/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:20:47 by ndauteui          #+#    #+#             */
/*   Updated: 2015/12/16 18:19:26 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void		ft_assign_letter(t_tlist **tmp, int counter)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((*tmp)->tab[i][j] == '#')
				(*tmp)->tab[i][j] = 65 + counter;
			j++;
		}
		i++;
	}
	(*tmp)->c = 65 + counter;
}

t_tlist		*ft_parse_all_tetriminos(t_tlist *list)
{
	t_tlist	*tmp;
	int		counter;

	counter = 0;
	tmp = list;
	while (tmp)
	{
		upper_move(&tmp);
		ft_assign_letter(&tmp, counter);
		tmp = tmp->next;
		counter++;
	}
	return (list);
}
