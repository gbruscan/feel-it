/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:47:15 by ndauteui          #+#    #+#             */
/*   Updated: 2014/01/26 22:20:06 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;
	int				i;

	tmp = s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		tmp[i] = tmp2[i];
		i++;
		n--;
	}
	return (s1);
}
