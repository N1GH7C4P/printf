/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 01:14:47 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/31 23:36:38 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

//%[flags][width][.precision][length modifier]conversion

int	counting_putchar(char c, t_dstr *s)
{
	if (s->null)
		ft_putchar(0);
	else
		ft_putchar(c);
	s->count++;
	return (1);
}

int	counting_putstr(char *str, t_dstr *s)
{
	int	len;

	len = ft_strlen(str);
	if (s->null && s->c != 'p')
		if (s->left)
			counting_putchar(0, s);
	ft_putstr(str);
	if (s->null && s->c != 'p')
		if (!s->left)
			counting_putchar(0, s);
	s->count += len;
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
			if (str[i] == '%' && counting_putchar(str[i++], output))
				continue ;
			if (str[i] == '.')
				i += handle_precision(output, str + i);
			if (str[i] == '%' && counting_putchar(str[i++], output))
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

	output = dstrnew();
	i = 0;
	va_start(vl, str);
	parse(str, i, output, vl);
	if (output->color_code)
		ft_putstr(STYLE_RESET);
	va_end (vl);
	return (output->count);
}
