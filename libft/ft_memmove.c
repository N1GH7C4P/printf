/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:40:44 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/24 12:35:51 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;

	if (!dest && !src)
		return (0);
	csrc = (char *)src;
	cdest = (char *)dest;
	if (csrc < cdest && csrc + n > cdest)
	{
		cdest += n;
		csrc += n;
		while (n--)
			*(--cdest) = *(--csrc);
	}
	else
		while (n--)
			*cdest++ = *csrc++;
	return (dest);
}
