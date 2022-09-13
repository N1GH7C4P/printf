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

static char	*add_zeroes(char *str, int prec)
{
	char	*output;
	int		chars;
	int		dot_position;
	int		len;

	if (!prec)
		return (str);
	chars = 1;
	len = ft_strlen(str);
	dot_position = find_dot(str);
	output = ft_strnew(len + prec);
	ft_memcpy(output, str, len);
	output[dot_position + prec + 1] = '\0';
	while (prec)
	{
		if (!str[dot_position + chars])
			output[dot_position + chars] = '0';
		prec--;
		chars++;
	}
	free(str);
	return (output);
}

static char	*round_number(int prec, int last_digit, char *str)
{
	if (!prec)
	{
		if (str[0] >= '5' && (check_f_digits(str + 1) || last_digit % 2))
			return (ft_strdup("1"));
		return (ft_strnew(0));
	}
	str = ft_strjoin(".", str);
	if (str[prec + 1] >= '5')
	{
		if (!check_f_digits(str + 2) && last_digit % 2)
			return (ft_strnew(0));
		str[prec]++;
		while (str[prec] > '9')
		{
			str[prec--] = '0';
			if (str[prec - 1] == '.')
			{
				free(str);
				return (ft_strdup("1"));
			}
			str[prec]++;
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

static char	*combine(long double f_part, long long i_part, size_t prec, char *t)
{
	char	*i_str;
	char	*f_str;
	char	*res;

	f_part = to_whole_number(f_part, count_fdigits(f_part, prec + 1));
	f_str = round_number(prec, i_part % 10, t);
	free(t);
	if (f_str[0] == '1')
	{
		i_part++;
		i_str = ft_itoabase(i_part, 10);
		if (prec > 0)
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

char	*ft_ftoa(long double n, size_t p, long double f_part, long long i_part)
{
	char	*res;
	int		minus_sign;
	char	*t;

	minus_sign = 0;
	if (n < 0 || 1 / n < 0)
	{
		minus_sign = 1;
		n = -n;
	}
	i_part = (long long)n;
	f_part = n - i_part;
	t = combine(f_part, i_part, p, ft_itoabase(f_part, 10));
	if (minus_sign)
		res = ft_strjoin("-", t);
	else
		res = ft_strdup(t);
	free(t);
	res = add_zeroes(res, p);
	return (res);
}
