/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 20:02:34 by ndauteui          #+#    #+#             */
/*   Updated: 2015/01/24 20:05:30 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = (t_list*)malloc(sizeof(t_list));
	if (new_elem)
	{
		if (!content)
		{
			new_elem->content = NULL;
			new_elem->content_size = 0;
			free(new_elem);
		}
		else
		{
			if (!(new_elem->content = (void*)malloc(content_size)))
				return (NULL);
			ft_memcpy(new_elem->content, content, content_size);
		}
		new_elem->next = NULL;
	}
	return (new_elem);
}
