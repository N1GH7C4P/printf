/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:11:55 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/14 17:06:11 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

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

	if (s->length[0] == 'L')
		str = ft_ftoa((long double)va_arg(vl, long double), s->precision);
	else
		str = ft_ftoa((double)va_arg(vl, double), s->precision);
	return (str);
}

char	*format_str(char *str, t_dstr *s, va_list vl)
{
	char	*temp;

	if (!s->precision)
		s->precision = 0;
	temp = ft_strsub(va_arg(vl, char *), 0, s->precision);
	free(str);
	str = ft_strdup(temp);
	free(temp);
	return (str);
}

char	*format_hexadecimal_numbers(char c, t_dstr *s, va_list vl)
{
	char	*str;
	char	*temp;
	size_t	len;

	str = ft_itoabase(va_arg(vl, long long), 16);
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
		str_toupper(&str);
	return (str);
}
