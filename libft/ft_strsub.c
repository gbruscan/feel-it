/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:47:06 by ndauteui          #+#    #+#             */
/*   Updated: 2015/01/24 20:07:11 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*strsub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	strsub = (char *)malloc((len + 1) * sizeof(char));
	if (strsub == NULL)
		return (NULL);
	while (i < len && s[i + start])
	{
		strsub[i] = s[i + start];
		i++;
	}
	strsub[i] = '\0';
	return (strsub);
}
