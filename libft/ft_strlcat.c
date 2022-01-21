/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:29:33 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/24 12:36:45 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	result;
	char			*csrc;

	csrc = (char *)src;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(csrc);
	if (destsize > dest_len)
		result = dest_len + src_len;
	else
		result = src_len + destsize;
	i = 0;
	while (csrc[i] != '\0' && (dest_len + 1) < destsize)
	{
		dest[dest_len] = csrc[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (result);
}
