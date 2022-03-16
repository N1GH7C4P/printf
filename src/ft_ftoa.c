/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:31:42 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/14 16:29:48 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

char	*round_number(long long nb, int precision)
{
	int		i;
	char	*str;

	if (!precision)
		return (ft_strdup("!"));
	str = ft_strjoin(".", ft_itoabase(nb, 10));
	if (str[precision++] >= '5')
	{
		i = precision - 1;
		str[i]++;
		while (str[i] > '9')
		{
			str[i--] = '0';
			if (str[i - 1] == '.')
			{
				free(str);
				return (ft_strdup("1"));
			}
			str[i]++;
		}
	}
	str[precision] = '\0';
	while (!str[--precision])
		str[precision] = '0';
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

static int	count_fdigits(long double f, int max_precision)
{
	int	count;

	if (max_precision == 1)
		max_precision = 20;
	count = 0;
	while (count < max_precision)
	{
		f = f - (long long)f;
		f = f * 10;
		count++;
	}
	return (count);
}

static char	*combine(long double f_part, long long i_part, size_t precision)
{
	char	*str;
	int		fracs;
	char	*res;

	res = NULL;
	if (f_part != 0)
	{
		fracs = count_fdigits(f_part, precision + 1);
		f_part = to_whole_number(f_part, fracs);
		str = round_number(f_part, precision);
		if (str[0] == '1')
		{
			i_part++;
			res = ft_itoabase(i_part, 10);
		}
		else
		{
			if (str[0] != '!')
				res = ft_strjoin(ft_itoabase(i_part, 10), str);
			else
				res = ft_itoabase(i_part, 10);
		}
	}
	return (res);
}

char	*ft_ftoa(long double n, size_t precision)
{
	long double	f_part;
	long long	i_part;
	char		*res;
	int			minus_sign;

	minus_sign = 0;
	if (n < 0)
	{
		minus_sign = 1;
		n = -n;
	}
	i_part = (long long)n;
	f_part = n - i_part;
	if (minus_sign)
		res = ft_strjoin("-", combine(f_part, i_part, precision));
	else
		res = combine(f_part, i_part, precision);
	return (res);
}
