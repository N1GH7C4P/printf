/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:46:13 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/25 23:54:07 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

int	find_dot(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == '.')
			break ;
		count++;
	}
	return (count);
}

int	check_f_digits(char *str)
{
	while (*str)
	{
		if (*str++ > '0')
			return (1);
	}
	return (0);
}

int	count_fdigits(long double f, int max_precision)
{
	int	count;

	if (max_precision == 1)
		max_precision = 17;
	count = 0;
	while (count < max_precision)
	{
		f = f - (long long)f;
		f = f * 10;
		count++;
	}
	return (count);
}
