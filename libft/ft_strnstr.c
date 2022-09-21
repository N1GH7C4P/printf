/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:06:10 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/24 12:36:58 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *heystack, const char *needle, size_t limit)
{
	unsigned int	i;
	int				j;
	char			*cheystack;
	char			*cneedle;
	int				nl;

	cneedle = (char *)needle;
	cheystack = (char *)heystack;
	nl = ft_strlen(cneedle);
	if (needle[0] == '\0')
		return (cheystack);
	i = 0;
	while (cheystack[i] != '\0' && i < limit)
	{
		j = 0;
		while (j < nl && cneedle[j] == cheystack[i + j] && j + i < limit)
		{
			if (j == nl - 1)
				return (cheystack + i);
			j++;
		}
		i++;
	}
	return (0);
}
