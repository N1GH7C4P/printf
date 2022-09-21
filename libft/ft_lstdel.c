/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:59:37 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/29 15:02:10 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current_link;
	t_list	*next_link;

	if (!*alst || !del)
		return ;
	current_link = *alst;
	while (current_link)
	{
		next_link = current_link->next;
		del(current_link->content, current_link->content_size);
		free(current_link);
		current_link = next_link;
	}
	*alst = NULL;
}
