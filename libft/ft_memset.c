/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:50:18 by kpolojar          #+#    #+#             */
/*   Updated: 2022/03/22 15:38:07 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ch;

	ch = str;
	while (n > 0)
	{
		n--;
		*ch++ = (unsigned char)c;
	}
	return (str);
}
