/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 01:14:47 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/12 01:04:50 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include "stdint.h"

//%[flags][width][.precision][length modifier]conversion

int	ft_printf(char *str, ...)
{
	va_list			vl;
	int				i;
	static t_dstr	*output;
	
	output = dstrnew("");
	i = 0;
	va_start(vl, str);
	while (str && str[i])
	{
		reset_dstr_flags_and_mods(output);
		if (str[i] == '%')
		{
			i++;
			i += handle_flags(output, str + i);
			i += handle_width(output, str + i);
			if (str[i] == '%')
			{
				output = dstrncat(output, &str[i], 1);
				i++;
				continue ;
			}
			if (str[i] == '.')
			{
				output->precision = ft_atoi(str + ++i);
				i += ft_countdigits(output->precision, 10);
			}
			else
				output->precision = 6;
			i = i + handle_length(output, str + i);
			handle_conversion(output, vl, str[i]);
		}
		else
			output = dstrncat(output, &str[i], 1);
		i++;
	}
	ft_putstr(output->content);
	dstrdel(output);
	va_end(vl);
	return (i);
}
