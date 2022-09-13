/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:11:55 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/01 01:18:56 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

char	*format_char(va_list vl, t_dstr *s)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = (char)va_arg(vl, int);
	if (!str[0])
		s->null = 1;
	s->digits = 1;
	return (str);
}

char	*format_floats(t_dstr *s, va_list vl)
{
	char	*str;

	if (!s->precision && !s->z_prec)
		s->precision = 6;
	if (s->length[0] == 'L')
		str = ft_ftoa((long double)va_arg(vl, long double), s->precision, 0, 0);
	else
		str = ft_ftoa((double)va_arg(vl, double), s->precision, 0, 0);
	s->digits = ft_strlen(str);
	if (!ft_strcmp("", str))
		str = ft_strdup("0");
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

char	*format_binary_numbers(t_dstr *s, va_list vl)
{
	char	*str;
	char	*temp;
	size_t	len;

	str = format_unsigned_numbers(s, vl, 2);
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

char	*format_pointers(t_dstr *s, va_list vl)
{
	char	*str;
	char	*temp;
	size_t	len;
	
	s->prefix = 1;
	str = ft_itoabase(va_arg(vl, unsigned long long), 16);
	len = ft_strlen(str);
	if (!ft_strcmp("0", str))
	{
		str = ft_strdup("(nil)");
		s->null = 1;
		s->prefix = 0;
	}
	else if (len < s->precision)
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
