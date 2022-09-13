/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:21:11 by kpolojar          #+#    #+#             */
/*   Updated: 2022/02/15 16:26:51 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_insert_digits(long long n, char *str, int digits)
{
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	else if (n == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[digits - 1] = '0' + n % 10;
		n = n / 10;
		digits--;
	}
	return (str);
}

char	*ft_itoa(long long nb)
{
	char		*str;
	int			digits;
	long long	n;

	n = (long)nb;
	digits = ft_countdigits(n, 10);
	str = ft_strnew(digits);
	if (!str)
		return (0);
	str = ft_insert_digits(n, str, digits);
	return (str);
}
