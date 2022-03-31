/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:36:30 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/01 01:18:57 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

char	*format_number_metadata(t_dstr *s, char *str, char *temp, int diff)
{
	s->digits = ft_strlen(str);
	if (str[0] == '-')
		s->is_negative = 1;
	if (s->z_prec)
		if (!ft_strcmp(str, "0"))
			str = ft_strnew(0);
	if (s->digits < s->precision)
	{
		temp = ft_strnew(s->precision);
		diff = s->precision - s->digits;
		if (str[0] == '-')
		{
			str++;
			diff++;
		}
		ft_memset(temp, '0', s->precision);
		ft_memcpy(temp + diff, str, s->digits);
		str = ft_strdup(temp);
		free(temp);
	}
	s->digits = ft_strlen(str);
	if ((s->digits < s->width) && str[0])
		s->padding = 1;
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
	str = format_number_metadata(s, str, NULL, 0);
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
	str = format_number_metadata(s, str, NULL, 0);
	return (str);
}

char	*format_hexadecimal_numbers(t_dstr *s, va_list vl)
{
	char	*str;
	char	*temp;
	size_t	len;

	str = format_unsigned_numbers(s, vl, 16);
	len = ft_strlen(str);
	if (len < s->precision)
	{
		temp = str;
		str = ft_strnew(s->precision);
		ft_memset(str, '0', s->precision);
		ft_memcpy(str + (s->precision - len), temp, len);
		free(temp);
	}
	s->digits = ft_strlen(str);
	return (str);
}

char	*format_octal_numbers(t_dstr *s, va_list vl)
{
	char	*str;
	char	*temp;
	size_t	len;

	str = format_unsigned_numbers(s, vl, 8);
	len = ft_strlen(str);
	if (len < s->precision)
	{
		temp = str;
		str = ft_strnew(s->precision);
		ft_memset(str, '0', s->precision);
		ft_memcpy(str + (s->precision - len), temp, len);
		free(temp);
	}
	str = format_number_metadata(s, str, NULL, 0);
	s->digits = ft_strlen(str);
	return (str);
}
