/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:03:30 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/24 12:41:11 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*heystack;
	unsigned char	needle;
	unsigned int	len;

	len = ft_strlen((char *)str);
	heystack = (char *)str + len;
	needle = (unsigned char)c;
	while (*heystack != needle && len)
	{
		len--;
		heystack--;
	}
	if (needle == *heystack)
		return (heystack);
	return (0);
}
