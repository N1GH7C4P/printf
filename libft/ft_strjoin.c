/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:45:11 by kpolojar          #+#    #+#             */
/*   Updated: 2021/12/14 14:43:13 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*new_str;
	int		i;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (!new_str)
		return (0);
	i = 0;
	while (i < len1 + len2)
	{
		if (i < len1)
			new_str[i] = s1[i];
		else
			new_str[i] = s2[i - len1];
		i++;
	}
	new_str[len1 + len2] = '\0';
	return (new_str);
}
