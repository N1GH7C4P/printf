/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:39:45 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/24 12:38:29 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen((char *)s);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		new_str[i] = f(s[i]);
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}
