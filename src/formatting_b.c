/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:36:30 by linuxlite         #+#    #+#             */
/*   Updated: 2022/09/20 16:41:12 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

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
	return (str);
}

char	*format_hexadecimal_numbers(t_dstr *s, va_list vl)
{
	char	*str;
	char	*output;
	size_t	len;

	str = format_unsigned_numbers(s, vl, 16);
	len = ft_strlen(str);
	if (len < s->precision)
	{
		output = ft_strnew(s->precision);
		ft_memset(output, '0', s->precision);
		ft_memcpy(output + (s->precision - len), str, len);
	}
	else
		output = ft_strdup(str);
	if (len == 1 && str[0] == '0')
		s->is_zero = 1;
	free(str);
	return (output);
}

char	*format_octal_numbers(t_dstr *s, va_list vl)
{
	char	*str;
	char	*output;
	size_t	len;

	if (s->prefix)
		s->prefix = 1;
	str = format_unsigned_numbers(s, vl, 8);
	len = ft_strlen(str);
	if (len < s->precision)
	{
		output = ft_strnew(s->precision);
		ft_memset(output, '0', s->precision);
		ft_memcpy(output + (s->precision - len), str, len);
	}
	else
		output = ft_strdup(str);
	if (len == 1 && str[0] == '0')
		s->is_zero = 1;
	free(str);
	return (output);
}
