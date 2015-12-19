/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 15:11:36 by ndauteui          #+#    #+#             */
/*   Updated: 2015/01/22 15:11:55 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strpos(const char *s1, const char *s2)
{
	char	*s1_;
	char	*s2_;
	int		l;
	int		counter;

	counter = 0;
	s1_ = (char *)s1;
	s2_ = (char *)s2;
	l = ft_strlen(s2_);
	while (*s1_ != '\0')
	{
		if (ft_strncmp(s1_, s2_, l) == 0)
			return (counter);
		s1_++;
		counter++;
	}
	return (counter);
}
