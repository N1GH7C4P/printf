/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:19:26 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/25 23:54:50 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(char *src)
{
	char	*dest;
	int		i;

	if (!src)
		return (ft_strnew(0));
	dest = ft_strnew(ft_strlen(src));
	i = 0;
	while (src[i])
	{
		dest[i] = (char)ft_toupper((int) src[i]);
		i++;
	}
	return (dest);
}
