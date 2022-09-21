/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:28:23 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/24 12:37:39 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char			*mem;
	unsigned int	i;

	mem = (char *)malloc(size);
	if (!mem)
		return (0);
	i = 0;
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
