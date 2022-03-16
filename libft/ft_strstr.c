/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:37:35 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/24 12:34:02 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *heystack, const char *needle)
{
	int		i;
	int		j;
	char	*cheystack;
	char	*cneedle;
	int		needle_len;

	cneedle = (char *)needle;
	cheystack = (char *)heystack;
	needle_len = ft_strlen(cneedle);
	if (!needle || needle_len == 0)
		return (cheystack);
	i = 0;
	while (cheystack[i] != '\0')
	{
		j = 0;
		while (j < needle_len && cneedle[j] == cheystack[i + j])
		{
			if (j == needle_len - 1)
				return (cheystack + i);
			j++;
		}
		i++;
	}
	return (0);
}
