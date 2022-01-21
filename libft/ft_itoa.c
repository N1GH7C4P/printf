/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:21:11 by kpolojar          #+#    #+#             */
/*   Updated: 2021/12/02 13:50:16 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_insert_digits(long n, char *str, int digits)
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

char	*ft_itoa(int nb)
{
	char	*str;
	int		digits;
	long	n;

	n = (long)nb;
	digits = ft_countdigits(n);
	str = ft_strnew(digits);
	if (!str)
		return (0);
	str = ft_insert_digits(n, str, digits);
	return (str);
}
