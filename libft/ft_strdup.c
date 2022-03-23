/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:56:16 by kpolojar          #+#    #+#             */
/*   Updated: 2022/03/21 14:52:39 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		l;
	char	*dest;
	int		i;

	if (!src)
		return (NULL);
	l = ft_strlen(src);
	dest = (char *)malloc(l + 1);
	if (!dest)
		return (0);
	i = 0;
	while (i < l)
	{
		dest[i] = src[i];
		i++;
	}
	dest[l] = '\0';
	return (dest);
}
