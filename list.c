/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:17:40 by ndauteui          #+#    #+#             */
/*   Updated: 2015/12/15 13:48:51 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft/libft.h"

t_tlist	*ft_create_elem(void)
{
	t_tlist *elem;

	elem = (t_tlist *)malloc(sizeof(t_tlist));
	elem->tab = (char**)malloc(sizeof(char *) * 5);
	elem->next = NULL;
	elem->a = 0;
	elem->b = 0;
	elem->prev = NULL;
	return (elem);
}

void	ft_add_elem(t_tlist **nlst, t_tlist *elem)
{
	t_tlist	*tmp;

	tmp = *nlst;
	if (tmp == NULL)
	{
		*nlst = elem;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	elem->prev = tmp;
	tmp->next = elem;
}

t_tlist	*ft_add_tetriminos(t_tlist *elem, t_tlist **list)
{
	elem->tab[4] = NULL;
	ft_add_elem(list, elem);
	elem = ft_create_elem();
	return (elem);
}

t_tlist	*ft_fill_list(int fd)
{
	t_tlist	*list;
	t_tlist	*elem;
	char	*line;
	int		i;

	i = -1;
	list = NULL;
	line = NULL;
	elem = ft_create_elem();
	while (get_next_line(fd, &line))
	{
		i++;
		if (ft_strcmp(line, "") == 0)
		{
			elem = ft_add_tetriminos(elem, &list);
			i = -1;
		}
		else
			elem->tab[i] = ft_strdup(line);
	}
	elem->tab[i + 1] = NULL;
	ft_add_elem(&list, elem);
	return (list);
}
