/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:30:02 by ndauteui          #+#    #+#             */
/*   Updated: 2015/01/24 19:28:30 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	counter;

	if (size == 0)
		return (0);
	counter = 0;
	ptr = (char *)malloc(sizeof(char) * (size));
	if (ptr == NULL)
		return (NULL);
	while (counter < size)
	{
		*ptr = '\0';
		ptr++;
		counter++;
	}
	*ptr = '\0';
	return ((char *)ptr - size);
}
