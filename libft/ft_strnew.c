/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:23:34 by ndauteui          #+#    #+#             */
/*   Updated: 2015/01/24 19:44:47 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(sizeof(*new_str) * size);
	if (new_str)
	{
		while (i < size)
		{
			new_str[i] = '\0';
			i++;
		}
	}
	return (new_str);
}
