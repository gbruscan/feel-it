/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:22:34 by ndauteui          #+#    #+#             */
/*   Updated: 2015/12/19 19:09:48 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>

int		ft_list_size(t_tlist *list)
{
	t_tlist			*tmp;
	int				counter;

	tmp = list;
	counter = 0;
	while (tmp)
	{
		counter++;
		tmp = tmp->next;
	}
	return (counter);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_tlist		*list;
	int			nb_tetri;

	if (argc != 2)
		return (ft_print_error());
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_print_error());
	if (ft_check_file(fd) == 0)
		return (0);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	list = ft_fill_list(fd);
	if (check_all_tetriminos(list) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	list = ft_parse_all_tetriminos(list);
	get_xy(list);
	nb_tetri = ft_list_size(list);
	ft_solve(&list, nb_tetri);
	return (0);
}
