/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:03:01 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/25 16:56:33 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_end(char *s, int len)
{
	int	i;
	int	end;

	end = 0;
	i = len - 1;
	while (s[i] && i >= 0)
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			end++;
			i--;
		}
		else
			break ;
	}
	return (end);
}

static int	find_begin(char *s, int len)
{
	int	i;
	int	begin;

	i = 0;
	begin = 0;
	while (s[i] && i < len)
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			begin++;
			i++;
		}
		else
			break ;
	}
	return (begin);
}

char	*ft_strtrim(char const *s)
{
	int		len;
	int		begin;
	int		end;
	char	*new_str;

	end = 0;
	len = ft_strlen((char *)s);
	begin = 0;
	if (!s)
		return (0);
	begin = find_begin((char *)s, len);
	end = find_end((char *)s, len);
	if (len - begin - end == 0)
		return (ft_strnew(0));
	new_str = ft_strsub(s, begin, len - begin - end);
	return (new_str);
}
