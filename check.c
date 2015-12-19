/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 11:08:46 by gbruscan          #+#    #+#             */
/*   Updated: 2015/12/19 14:22:30 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		ft_check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '.' && line[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_sharp(char *line, int counter)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '#')
			counter++;
		i++;
	}
	return (counter);
}

int		ft_check_end(int size, int counter)
{
	if (size < 4)
		return (ft_print_error());
	if (counter != 4)
		return (ft_print_error());
	return (1);
}

int		ft_check_file(int fd)
{
	int		size;
	char	*line;
	int		counter;

	counter = 0;
	size = 0;
	while (get_next_line(fd, &line))
	{
		size++;
		counter = ft_check_sharp(line, counter);
		if (size <= 4 && ft_strlen(line) != 4)
			return (ft_print_error());
		if (size <= 4 && ft_check_line(line) == 0)
			return (ft_print_error());
		if (size == 5 && ft_strcmp(line, "") == 0)
		{
			size = 0;
			counter = 0;
		}
		if (size > 4)
			return (ft_print_error());
	}
	return (ft_check_end(size, counter));
}
