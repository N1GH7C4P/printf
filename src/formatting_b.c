/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:36:30 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/25 23:36:32 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

char	*format_number_metadata(t_dstr *s, char *str)
{
	s->digits = ft_strlen(str);
	if (str[0] == '-')
	{
		s->digits--;
		s->is_negative = 1;
	}
	if (s->zero_precision)
		if (!ft_strcmp(str, "0"))
			str = ft_strnew(0);
	if ((ft_strlen(str) < s->width || ft_strlen(str) < s->precision) && str[0])
	{
		s->padding = 1;
		if (s->precision > s->digits)
			s->zero_padding = 1;
	}
	s->digits = ft_strlen(str);
	return (str);
}

char	*format_unsigned_numbers(t_dstr *s, va_list vl, int base)
{
	char	*str;

	if (!ft_strncmp(s->length, "hh", 2))
		str = ft_unsigned_itoabase((unsigned char)va_arg(vl, int), base);
	else if (!ft_strncmp(s->length, "h", 1))
		str = ft_unsigned_itoabase((unsigned short)va_arg(vl, int), base);
	else if (!ft_strncmp(s->length, "ll", 2))
		str = ft_unsigned_itoabase(va_arg(vl, unsigned long long), base);
	else if (!ft_strncmp(s->length, "l", 1))
		str = ft_unsigned_itoabase(va_arg(vl, unsigned long), base);
	else
		str = ft_unsigned_itoabase(va_arg(vl, unsigned int), base);
	str = format_number_metadata(s, str);
	return (str);
}

char	*format_numbers(t_dstr *s, va_list vl, int base)
{
	char	*str;

	if (!ft_strncmp(s->length, "hh", 2))
		str = ft_itoabase((char)va_arg(vl, int), base);
	else if (!ft_strncmp(s->length, "h", 1))
		str = ft_itoabase((short)va_arg(vl, int), base);
	else if (!ft_strncmp(s->length, "ll", 2))
		str = ft_itoabase(va_arg(vl, long long), base);
	else if (!ft_strncmp(s->length, "l", 1))
		str = ft_itoabase(va_arg(vl, long), base);
	else
		str = ft_itoabase(va_arg(vl, int), base);
	s->digits = ft_strlen(str);
	str = format_number_metadata(s, str);
	return (str);
}
