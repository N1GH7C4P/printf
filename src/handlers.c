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

int	handle_width(t_dstr *output, char *input)
{
	int	i;

	output->width = ft_atoi(input);
	i = ft_countdigits(output->width, 10);
	return (i);
}

int	handle_flags(t_dstr *output, char *input)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (input[i] == '#')
			output->prefix = 1;
		else if (input[i] == '0')
			output->z_pad = 1;
		else if (input[i] == '-')
			output->left = 1;
		else if (input[i] == '+')
			output->force_sign = 1;
		else if (input[i] == ' ')
			output->space = 1;
		else
			break ;
		i++;
	}
	return (i);
}

int	handle_length(t_dstr *output, char *input)
{
	int	i;

	i = 0;
	if (input[i] == 'l' || input[i] == 'h')
	{
		output->length[i] = input[i];
		i++;
		if (input[i] == input[i - 1])
		{
			output->length[i] = input[i];
			i++;
		}
	}
	else if (input[i] == 'L')
	{
		output->length[i] = 'L';
		i++;
	}
	return (i);
}

int	handle_precision(t_dstr *output, char *input)
{
	int	i;

	i = 1;
	output->dot = 1;
	while (input[i] == '0')
		i++;
	if (input[i] > '0' && input[i] <= '9')
	{
		output->precision = ft_atoi(input + i);
		i += ft_countdigits(output->precision, 10);
		return (i);
	}
	else
	{
		output->precision = 0;
		output->z_prec = 1;
	}
	return (i);
}

void	handle_conversion(t_dstr *output, va_list vl, char c, char *str)
{	
	output->c = c;
	if (c == 'c')
		str = format_char(vl, output);
	else if (c == 'u')
		str = format_unsigned_numbers(output, vl, 10);
	else if (c == 'd' || c == 'i')
		str = format_numbers(output, vl, 10);
	else if (c == 's')
		str = format_str(output, vl);
	else if (c == 'p')
		str = format_pointers(output, vl);
	else if (c == 'X' || c == 'x')
		str = format_hexadecimal_numbers(output, vl);
	else if (c == 'o')
		str = format_octal_numbers(output, vl);
	else if (c == 'b')
		str = format_binary_numbers(output, vl);
	else if (c == 'f')
		str = format_floats(output, vl);
	if (!str)
		str = ft_strdup("(null)");
	apply_modifications(str, output);
}
