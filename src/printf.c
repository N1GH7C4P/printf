/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 01:14:47 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/25 23:13:23 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

//%[flags][width][.precision][length modifier]conversion

static void	parse(char *str, int i, t_dstr *output, va_list vl)
{
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
				i += handle_precision(output, str + i);
			i += handle_length(output, str + i);
			handle_conversion(output, vl, str[i]);
		}
		else
			output = dstrncat(output, &str[i], 1);
		i++;
	}
}

int	ft_printf(char *str, ...)
{
	va_list			vl;
	int				i;
	static t_dstr	*output;

	output = dstrnew("");
	i = 0;
	va_start(vl, str);
	parse(str, i, output, vl);
	ft_putstr(output->content);
	va_end (vl);
	return (ft_strlen(output->content));
}
