/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:21:05 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/29 15:03:08 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*first_node;

	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew(f(lst)->content, f(lst)->content_size);
	first_node = new_list;
	if (!new_list)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		new_list->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		new_list = new_list->next;
	}
	return (first_node);
}
