/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 14:03:08 by gbruscan          #+#    #+#             */
/*   Updated: 2015/12/16 18:20:24 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	**ft_tab2_filler(char **tab, char **tab2)
{
	int		i;

	i = 0;
	while (tab[i] && tab2[i])
	{
		tab2[i] = ft_strcpy(tab2[i], tab[i]);
		i++;
	}
	return (tab2);
}

int		ft_tab_total_i(char **tab)
{
	int		i;
	int		j;
	int		total_i;

	i = 0;
	j = 0;
	total_i = 0;
	while (tab[i])
	{
		i++;
		j = 0;
		while (tab[i] && tab[i][j])
		{
			if (tab[i][j] != '.')
				total_i += i;
			j++;
		}
	}
	return (total_i);
}

int		ft_tab_total_j(char **tab)
{
	int		i;
	int		j;
	int		total_j;

	i = 0;
	j = 0;
	total_j = 0;
	while (tab[i])
	{
		i++;
		j = 0;
		while (tab[i] && tab[i][j])
		{
			if (tab[i][j] != '.')
				total_j += j;
			j++;
		}
	}
	return (total_j);
}

int		ft_is_better_tab(char **tab, char **tab2)
{
	if (ft_get_square_size(tab) < ft_get_square_size(tab2))
		return (1);
	else if (ft_get_square_size(tab) > ft_get_square_size(tab2))
		return (0);
	if (ft_tab_total_i(tab) < ft_tab_total_i(tab2))
		return (1);
	else if (ft_tab_total_i(tab) > ft_tab_total_i(tab2))
		return (0);
	if (ft_tab_total_j(tab) < ft_tab_total_j(tab2))
		return (1);
	return (0);
}
