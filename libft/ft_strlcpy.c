/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:34:35 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/26 14:34:06 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	unsigned int	src_len;

	src_len = (unsigned int)ft_strlen((char *)src);
	if (dstsize == 0)
		return (src_len);
	if (dstsize < src_len)
	{
		dstsize--;
		while (dstsize)
		{
			dstsize--;
			*dest++ = (char) *src++;
		}
	}
	while ((char) *src != '\0' && dstsize--)
	{
		*dest++ = (char) *src++;
	}
	*dest = '\0';
	return (src_len);
}
