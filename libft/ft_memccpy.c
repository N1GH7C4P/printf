/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:53:39 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/26 16:44:38 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	unsigned char	ch;

	if (!dest && !src)
		return (0);
	ch = (unsigned char)c;
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	while (n--)
	{
		*cdest = *csrc;
		if (*cdest == ch)
			return (++cdest);
		cdest++;
		csrc++;
	}
	return (NULL);
}
