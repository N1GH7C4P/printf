/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:49:05 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/24 12:36:33 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*cdest;
	int		len;
	int		i;

	cdest = (char *) dest;
	len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		cdest[len + i] = src[i];
		i++;
	}
	cdest[len + i] = '\0';
	return (dest);
}
