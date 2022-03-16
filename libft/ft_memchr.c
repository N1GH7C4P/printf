/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:00:14 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/26 13:31:00 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*cstr;
	unsigned char	*found;

	found = NULL;
	cstr = (unsigned char *)str;
	while (n--)
	{
		if (*cstr != (unsigned char)c)
		{
			cstr++;
		}
		else
		{
			found = cstr;
			break ;
		}
	}
	return (found);
}
