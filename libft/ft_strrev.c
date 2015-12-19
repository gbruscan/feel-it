/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 13:13:53 by ndauteui          #+#    #+#             */
/*   Updated: 2015/01/24 19:40:44 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char **str)
{
	int		i;
	int		j;
	char	tmp;

	i = (ft_strlen(*str) - 1);
	j = 0;
	while (j < i)
	{
		tmp = (*str)[i];
		(*str)[i] = (*str)[j];
		(*str)[j] = tmp;
		i--;
		j++;
	}
}
