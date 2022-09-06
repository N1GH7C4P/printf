/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:21:17 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/26 16:52:42 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

static char	*convert_to_ascii(long long value, int base, int digits, int sign)
{
	char	*output;
	int		i;

	if (sign)
	{
		digits++;
		output = (char *)malloc(sizeof(char) * (digits + 1));
		output[0] = '-';
	}
	else
		output = (char *)malloc(sizeof(char) * (digits + 1));
	i = 1;
	while (value != 0)
	{
		if (value % base < 10)
			output[digits - i++] = '0' + value % base;
		else
			output[digits - i++] = 'a' + value % base - 10;
		value = value / base;
	}
	output[digits] = '\0';
	return (output);
}

char	*ft_itoabase(long long value, int base)
{	
	int		digits;
	int		minus_sign;

	if (value == (-9223372036854775807LL - 1))
		return (ft_strdup("-9223372036854775808"));
	minus_sign = 0;
	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && value < 0)
	{	
		value = -value;
		minus_sign = 1;
	}
	if (value == 0)
		return (ft_strdup("0"));
	digits = ft_countdigits((long long)value, base);
	return (convert_to_ascii(value, base, digits, minus_sign));
}

char	*ft_unsigned_itoabase(unsigned long long value, int base)
{	
	int		digits;
	char	*output;
	int		i;

	if (base < 2 || base > 16)
		return (0);
	if (value == 0)
		return ("0");
	digits = ft_countdigits(value, base);
	output = (char *)malloc(sizeof(char) * (digits + 1));
	i = 1;
	while (value != 0)
	{
		if (value % base < 10)
			output[digits - i++] = '0' + value % base;
		else
			output[digits - i++] = 'a' + value % base - 10;
		value = value / base;
	}
	output[digits] = '\0';
	return (output);
}
