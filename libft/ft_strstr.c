/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:42:27 by ndauteui          #+#    #+#             */
/*   Updated: 2015/01/24 20:59:58 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] == s2[j])
		{
			i++;
			j++;
			if (s2[j] == '\0')
			{
				i = i - j;
				return ((char *)s1 + i);
			}
			else if (s1[i] != s2[j])
				i -= (j - 1);
		}
		i++;
	}
	return (NULL);
}
