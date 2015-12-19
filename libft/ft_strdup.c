/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:36:14 by ndauteui          #+#    #+#             */
/*   Updated: 2014/03/23 12:55:50 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s1) * (sizeof(char)) + 1);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	if (dest == NULL)
		return (NULL);
	return (dest);
}
