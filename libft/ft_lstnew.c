/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:14:56 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/29 15:00:15 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list *) ft_memalloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	if (content == NULL)
		content_size = 0;
	new_list -> content = (void *) content;
	new_list -> content_size = content_size;
	new_list -> next = NULL;
	return (new_list);
}
