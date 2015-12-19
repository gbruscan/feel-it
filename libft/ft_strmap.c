/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:49:52 by ndauteui          #+#    #+#             */
/*   Updated: 2014/03/23 12:54:56 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (s == NULL || *f == NULL)
		return (NULL);
	tmp = (char *)malloc(ft_strlen(s) + 1);
	if (tmp == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		tmp[i] = f(s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
