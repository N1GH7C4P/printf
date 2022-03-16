/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:18:55 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/26 13:34:08 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t index)
{
	char				*temp;
	unsigned int		i;
	size_t				src_len;

	src_len = ft_strlen(src);
	temp = dest;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < index)
	{
		i++;
		if (i > src_len)
			*dest = '\0';
		else
		{
			*dest = *src;
			src++;
		}
		dest++;
	}
	return (temp);
}
