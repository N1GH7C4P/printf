/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:04:34 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/24 12:36:15 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*cstr1;
	unsigned char	*cstr2;

	cstr1 = (unsigned char *)str1;
	cstr2 = (unsigned char *)str2;
	while (n--)
	{
		if (*cstr1 != *cstr2)
			return ((int)(*cstr1 - *cstr2));
		cstr1++;
		cstr2++;
	}
	return (0);
}
