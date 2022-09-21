/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:56:16 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/26 13:32:38 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	int		l;
	char	*dest;
	int		i;

	l = ft_strlen(s);
	dest = (char *)malloc(l + 1);
	if (!dest)
		return (0);
	i = 0;
	while (i < l && n--)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
