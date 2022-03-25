/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:11:55 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/25 23:37:20 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

char	*format_floats(t_dstr *s, va_list vl)
{
	char	*str;

	if (!s->precision && !s->zero_precision)
		s->precision = 6;
	if (s->length[0] == 'L')
		str = ft_ftoa((long double)va_arg(vl, long double), s->precision);
	else
		str = ft_ftoa((double)va_arg(vl, double), s->precision);
	s->digits = ft_strlen(str);
	return (str);
}

char	*format_str(t_dstr *s, va_list vl)
{
	char	*str;

	if (s->precision)
		str = ft_strsub(va_arg(vl, char *), 0, s->precision);
	else
		str = ft_strdup(va_arg(vl, char *));
	if (str)
		s->digits = ft_strlen(str);
	return (str);
}

char	*format_hexadecimal_numbers(char c, t_dstr *s, va_list vl)
{
	char	*str;
	char	*temp;
	size_t	len;

	str = format_numbers(s, vl, 16);
	len = ft_strlen(str);
	if (len < s->precision)
	{
		temp = str;
		str = ft_strnew(s->precision);
		ft_memset(str, '0', s->precision);
		ft_memcpy(str + (s->precision - len), temp, len);
		free(temp);
	}
	if (s->hex_prefix)
		str = ft_strjoin("0x", str);
	if (c == 'X')
		str = ft_str_toupper(str);
	s->digits = ft_strlen(str);
	return (str);
}
