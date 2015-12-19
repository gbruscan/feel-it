/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 20:00:52 by ndauteui          #+#    #+#             */
/*   Updated: 2014/03/23 12:47:13 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s1) * (sizeof(char)) * n + 1);
	while (s1[i] && i < n)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	if (dest == NULL)
		return (NULL);
	return (dest);
}
