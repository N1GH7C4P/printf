/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 01:14:47 by linuxlite         #+#    #+#             */
/*   Updated: 2022/09/21 14:18:45 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

//%[flags][width][.precision][length modifier]conversion

int	counting_putchar(char c, t_dstr *s)
{
	print_style_modifiers(s);
	ft_putchar(c);
	s->count++;
	return (1);
}

int	counting_putstr(char *str, t_dstr *s)
{
	print_style_modifiers(s);
	s->count += ft_strlen(str);
	ft_putstr(str);
	return (1);
}

static void	parse(char *str, int i, t_dstr *output, va_list vl)
{
	while (str && str[i])
	{
		reset_all_but_count(output);
		if (str[i++] == '%')
		{
			i += handle_style(output, str + i);
			i += handle_flags(output, str + i);
			i += handle_width(output, str + i);
			if (str[i] == '%' && modify_percent_sign(output, i++))
				continue ;
			if (str[i] == '.')
				i += handle_precision(output, str + i);
			if (str[i] == '%' && modify_percent_sign(output, i++))
				continue ;
			i += handle_length(output, str + i);
			handle_conversion(output, vl, str[i], NULL);
		}
		else
			counting_putchar(str[--i], output);
		i++;
	}
}

int	handle_style(t_dstr *output, char *input)
{
	int		i;

	i = 0;
	if (input[0] == '!')
	{
		i++;
		output->color_code = input[i++];
	}
	return (i);
}

int	ft_printf(char *str, ...)
{
	va_list	vl;
	int		i;
	t_dstr	*output;
	int		count;

	count = 0;
	output = dstrnew();
	i = 0;
	va_start(vl, str);
	parse(str, i, output, vl);
	if (output->color_code)
		ft_putstr(STYLE_RESET);
	va_end (vl);
	count = output->count;
	dstrdel(output);
	return (count);
}
