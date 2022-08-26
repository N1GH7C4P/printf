/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:13:34 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/01 01:19:14 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

int	handle_width(t_dstr *options, char *input)
{
	int	i;

	options->width = ft_atoi(input);
	i = ft_countdigits(options->width, 10);
	return (i);
}

int	handle_flags(t_dstr *options, char *input)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (input[i] == '#')
			options->prefix = 1;
		else if (input[i] == '0')
			options->z_pad = 1;
		else if (input[i] == '-')
			options->left = 1;
		else if (input[i] == '+')
			options->force_sign = 1;
		else if (input[i] == ' ')
			options->space = 1;
		else
			break ;
		i++;
	}
	return (i);
}

int	handle_length(t_dstr *options, char *input)
{
	int	i;

	i = 0;
	if (input[i] == 'l' || input[i] == 'h')
	{
		options->length[i] = input[i];
		i++;
		if (input[i] == input[i - 1])
		{
			options->length[i] = input[i];
			i++;
		}
	}
	else if (input[i] == 'L')
	{
		options->length[i] = 'L';
		i++;
	}
	return (i);
}

int	handle_precision(t_dstr *options, char *input)
{
	int	i;

	i = 1;
	options->dot = 1;
	while (input[i] == '0')
		i++;
	if (input[i] > '0' && input[i] <= '9')
	{
		options->precision = ft_atoi(input + i);
		i += ft_countdigits(options->precision, 10);
		return (i);
	}
	else
	{
		options->precision = 0;
		options->z_prec = 1;
	}
	return (i);
}

void	handle_conversion(t_dstr *options, va_list vl, char c, char *str)
{	
	options->c = c;
	if (c == 'c')
		str = format_char(vl, options);
	else if (c == 'u')
		str = format_unsigned_numbers(options, vl, 10);
	else if (c == 'd' || c == 'i')
		str = format_numbers(options, vl, 10);
	else if (c == 's')
		str = format_str(options, vl);
	else if (c == 'p')
		str = format_pointers(options, vl);
	else if (c == 'X' || c == 'x')
		str = format_hexadecimal_numbers(options, vl);
	else if (c == 'o')
		str = format_octal_numbers(options, vl);
	else if (c == 'b')
		str = format_binary_numbers(options, vl);
	else if (c == 'f')
		str = format_floats(options, vl);
	if (!str)
		str = ft_strdup("(null)");
	apply_modifications(str, options);
}
