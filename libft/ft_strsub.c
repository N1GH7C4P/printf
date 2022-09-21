/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:33:53 by kpolojar          #+#    #+#             */
/*   Updated: 2022/03/22 01:19:18 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	i;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_strnew(0));
	new_str = ft_strnew(len);
	if (!new_str)
		return (0);
	i = 0;
	while (i < s_len && i < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[s_len] = '\0';
	while (i < len)
	{
		new_str[i] = '\0';
		i++;
	}
	return (new_str);
}
