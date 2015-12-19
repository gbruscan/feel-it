/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 20:58:18 by ndauteui          #+#    #+#             */
/*   Updated: 2015/01/24 21:00:40 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_list_push_back(t_list **begin_list, t_list *elem)
{
	t_list	*start;

	start = *begin_list;
	if (begin_list)
	{
		if (!*begin_list)
		{
			*begin_list = elem;
			return (start);
		}
		while ((*begin_list)->next)
			(*begin_list) = (*begin_list)->next;
		(*begin_list)->next = elem;
	}
	return (start);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*elem;

	new_list = NULL;
	while (lst)
	{
		elem = f(lst);
		ft_list_push_back(&new_list, elem);
		lst = lst->next;
	}
	return (new_list);
}
