/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:55:14 by ndauteui          #+#    #+#             */
/*   Updated: 2015/12/19 16:49:15 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_under(char **tab, int i, int j)
{
	if (i + 1 >= 4)
		return (0);
	if (tab[i + 1][j] == '#')
		return (1);
	return (0);
}

int	check_right(char **tab, int i, int j)
{
	if (j + 1 >= 4)
		return (0);
	if (tab[i][j + 1] == '#')
		return (1);
	return (0);
}

int	check_left(char **tab, int i, int j)
{
	if (j - 1 < 0)
		return (0);
	if (tab[i][j - 1] == '#')
		return (1);
	return (0);
}
