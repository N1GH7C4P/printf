/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:06:08 by linuxlite         #+#    #+#             */
/*   Updated: 2022/09/20 16:12:23 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

void	place_sign(t_dstr *options, int location)
{
	if (options->is_negative)
		options->content[location] = '-';
	else if (options->force_sign)
			options->content[location] = '+';
	else if (options->space)
		options->content[location] = ' ';
}

size_t	count_digits(char *str)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
			count++;
		i++;
	}
	return (count);
}

int	modify_percent_sign(t_dstr *s, int i)
{
	char	*str;

	if (s->precision)
		str = ft_strsub("%", 0, s->precision);
	else
		str = ft_strdup("%");
	if (str)
		s->digits = ft_strlen(str);
	modify_strings(str, s);
	free(str);
	return (i);
}
