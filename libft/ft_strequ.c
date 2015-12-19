/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 13:21:08 by ndauteui          #+#    #+#             */
/*   Updated: 2013/12/07 23:31:09 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (i < (int)ft_strlen(s1) && s1[i] == s2[i])
		i++;
	if ((s1[i] == '\0' || s2[i] == '\0') && s1[i] == s2[i])
		return (1);
	return (0);
}
