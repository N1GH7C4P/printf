/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:36:50 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/24 12:39:28 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*cdest;
	int		len;
	int		i;

	cdest = (char *)dest;
	len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && n--)
	{
		cdest[len + i] = src[i];
		i++;
	}
	cdest[len + i] = '\0';
	return (dest);
}
