/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:11:55 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/23 21:57:05 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

char	*format_unsigned_numbers(t_dstr *s, va_list vl)
{
	char	*str;

	if (!ft_strncmp(s->length, "hh", 2))
		str = ft_unsigned_itoabase((unsigned char)va_arg(vl, int), 10);
	else if (!ft_strncmp(s->length, "h", 1))
		str = ft_unsigned_itoabase((unsigned short)va_arg(vl, int), 10);
	else if (!ft_strncmp(s->length, "ll", 2))
		str = ft_unsigned_itoabase(va_arg(vl, unsigned long long), 10);
	else if (!ft_strncmp(s->length, "l", 1))
		str = ft_unsigned_itoabase(va_arg(vl, unsigned long), 10);
	else
		str = ft_unsigned_itoabase(va_arg(vl, unsigned int), 10);
	return (str);
}

char	*format_real_numbers(t_dstr *s, va_list vl)
{
	char	*str;

	if (!ft_strncmp(s->length, "hh", 2))
		str = ft_itoabase((char)va_arg(vl, int), 10);
	else if (!ft_strncmp(s->length, "h", 1))
		str = ft_itoabase((short)va_arg(vl, int), 10);
	else if (!ft_strncmp(s->length, "ll", 2))
		str = ft_itoabase(va_arg(vl, long long), 10);
	else if (!ft_strncmp(s->length, "l", 1))
		str = ft_itoabase(va_arg(vl, long), 10);
	else
		str = ft_itoabase(va_arg(vl, int), 10);
	return (str);
}

char	*format_floats(t_dstr *s, va_list vl)
{
	char	*str;

	if (!s->precision && !s->zero_precision)
		s->precision = 6;
	if (s->length[0] == 'L')
		str = ft_ftoa((long double)va_arg(vl, long double), s->precision);
	else
		str = ft_ftoa((double)va_arg(vl, double), s->precision);
	return (str);
}

char	*format_str(t_dstr *s, va_list vl)
{
	char	*str;

	if (s->precision)
		str = ft_strsub(va_arg(vl, char *), 0, s->precision);
	else
		str = ft_strdup(va_arg(vl, char *));
	return (str);
}

char	*format_hexadecimal_numbers(char c, t_dstr *s, va_list vl)
{
	char	*str;
	char	*temp;
	size_t	len;

	if (!ft_strncmp(s->length, "hh", 2))
		str = ft_itoabase((char)va_arg(vl, int), 16);
	else if (!ft_strncmp(s->length, "h", 1))
		str = ft_itoabase((short)va_arg(vl, int), 16);
	else if (!ft_strncmp(s->length, "ll", 2))
		str = ft_itoabase(va_arg(vl, long long), 16);
	else if (!ft_strncmp(s->length, "l", 1))
		str = ft_itoabase(va_arg(vl, long), 16);
	else
		str = ft_itoabase(va_arg(vl, int), 16);
	len = ft_strlen(str);
	if (len < s->precision)
	{
		temp = str;
		str = ft_strnew(s->precision);
		ft_memset(str, '0', s->precision);
		ft_memcpy(str + (s->precision - len), temp, len);
		free(temp);
	}
	if (s->binary_prefix)
		str = ft_strjoin("0x", str);
	if (c == 'X')
		str = str_toupper(str);
	return (str);
}
