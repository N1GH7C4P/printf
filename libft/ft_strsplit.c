/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:58:08 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/29 14:58:12 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_w(char *str, char delimiter)
{
	int	word_count;
	int	whitespace;

	word_count = 0;
	whitespace = 1;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == delimiter)
		{
			whitespace = 1;
			str++;
			continue ;
		}
		if (whitespace == 1)
		{
			whitespace = 0;
			word_count++;
		}
		str++;
	}
	return (word_count);
}

static int	ft_dist_to_next_char(char *str, char c)
{
	int	dist;

	dist = 0;
	while (*str)
	{
		if (*str == c)
			return (dist);
		str++;
		dist++;
	}
	return (-1);
}

static void	ft_clearlib(char **lib, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		ft_strdel(&lib[i]);
		i++;
	}
	free(lib);
}

static char	**ft_addwords(char *s, char c, char **lib, int word_count)
{
	int		j;
	int		word_len;

	j = 0;
	while (*s && j < word_count)
	{
		word_len = ft_dist_to_next_char(s, c);
		if (word_len == -1)
		{
			lib[j] = ft_strcpy(ft_strnew(ft_strlen(s)), s);
			break ;
		}
		else if (word_len == 0)
		{
			s++;
			continue ;
		}
		else
			lib[j] = ft_strncpy(ft_strnew(word_len), (char *)s, word_len);
		j++;
		s = s + word_len;
	}
	return (lib);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**lib;
	int		word_count;

	word_count = ft_count_w((char *) s, c);
	lib = (char **) malloc(sizeof(char *) * (word_count + 1));
	if (!lib)
		return (0);
	lib = ft_addwords((char *)s, c, lib, word_count);
	if (!lib)
	{
		ft_clearlib(lib, word_count);
		return (0);
	}
	lib[word_count] = NULL;
	return (lib);
}
