/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:31:42 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/31 23:40:39 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

char	*add_zeroes(char *str, int precision)
{
	char	*output;
	int		chars;
	int		dot_position;
	int		len;

	if (!precision)
		return (str);
	chars = 1;
	len = ft_strlen(str);
	dot_position = find_dot(str);
	output = ft_strnew(len + precision);
	ft_memcpy(output, str, len);
	output[dot_position + precision + 1] = '\0';
	while (precision)
	{
		if (!str[dot_position + chars])
			output[dot_position + chars] = '0';
		precision--;
		chars++;
	}
	free(str);
	return (output);
}

char	*round_number(int precision, int last_digit, char *str)
{
	char 	*temp;

	if (!precision)
	{
		if (str[0] >= '5' && (check_f_digits(str + 1) || last_digit % 2))
			return (ft_strdup("1"));
		return (ft_strnew(0));
	}
	temp = ft_strjoin(".", str);
	str = ft_strdup(temp);
	free(temp);
	if (str[precision + 1] >= '5')
	{
		if (!check_f_digits(str + 2) && last_digit % 2)
			return (ft_strnew(0));
		str[precision]++;
		while (str[precision] > '9')
		{
			str[precision--] = '0';
			if (str[precision - 1] == '.')
			{
				free(str);
				return (ft_strdup("1"));
			}
			str[precision]++;
		}
	}
	return (str);
}

static long double	to_whole_number(long double n, int pow)
{
	while (pow > 0)
	{
		n = n * 10;
		pow--;
	}
	return (n);
}

static char	*combine(long double f_part, long long i_part, size_t precision)
{
	char	*i_str;
	char	*f_str;
	char	*res;
	char	*temp;

	f_part = to_whole_number(f_part, count_fdigits(f_part, precision + 1));
	temp = ft_itoabase(f_part, 10);
	f_str = round_number(precision, i_part % 10, temp);
	free(temp);
	if (f_str[0] == '1')
	{
		i_part++;
		i_str = ft_itoabase(i_part, 10);
		if (precision > 0)
			res = ft_strjoin(i_str, ".");
		else
			res = ft_strdup(i_str);
	}
	else
	{
		i_str = ft_itoabase(i_part, 10);
		res = ft_strjoin(i_str, f_str);
	}
	free(i_str);
	free(f_str);
	return (res);
}

char	*ft_ftoa(long double n, size_t precision, long double f_part, long long	i_part)
{
	char	*res;
	int		minus_sign;
	char	*temp;

	minus_sign = 0;
	if (n < 0 || 1 / n < 0)
	{
		minus_sign = 1;
		n = -n;
	}
	i_part = (long long)n;
	f_part = n - i_part;
	temp = combine(f_part, i_part, precision);
	if (minus_sign)
		res = ft_strjoin("-", temp);
	else
		res = ft_strdup(temp);
	free(temp);
	res = add_zeroes(res, precision);
	return (res);
}
