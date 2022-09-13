/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:06:08 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/01 01:31:43 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

void	apply_modifications(char *input, t_dstr *options)
{
	if (options -> c == 'i' || options -> c == 'd' || options -> c == 'u')
		modify_integers(input, options);
	else if (options -> c == 'f')
		modify_floats(input, options);
	else if (options -> c == 'p')
		modify_pointers(input, options);
	else if (options -> c == 'x' || options -> c == 'X')
		modify_hexadecimals(input, options);
	else if (options -> c == 'o')
		modify_octals(input, options);
	else if (options -> c == 's' || options -> c == 'c')
		modify_strings(input, options);
	free(input);
}

void	calculate_output_width(t_dstr *options)
{
	if (options->z_prec && options->null)
		options->digits = 0;
	if (options->is_zero || options->z_prec || options->null)
		options->prefix = 0;
	if (options->width < options->digits + options->prefix && !options->null)
		options->width = options->digits + options->prefix;
	if (options->width < options->precision && options->digits > 0)
	{
		if (options->is_negative || options->force_sign || options->space)
			options->precision++;
		options->width = options->precision;
	}
	if (options->digits < options->width - options->prefix)
		options->padding = options->width - options->digits - options->prefix;
}

void	observe_minus_sign(t_dstr *options, char *str)
{
	if (str[0] == '-')
		options->is_negative = 1;
}

void	add_precision_zeroes(t_dstr *options, int i)
{
	int	diff;
	int	padd;

	diff = options->precision - options->digits;
	padd = options->width - options->digits - 1;
	if (!options->left)
	{
		while (diff > 0)
		{
			options->content[padd--] = '0';
			diff--;
		}
	}
	else
	{
		if (options -> is_negative || options->force_sign || options -> space)
			i++;
		while (diff > 0)
		{
			options->content[i] = '0';
			options->lead0++;
			diff--;
			i++;
		}
	}
}

void	fill_with_padding(t_dstr *options)
{
	if (options->z_pad && options->padding && !options->dot && !options->left)
		ft_memset(options->content, '0', options->width);
	else
		ft_memset(options->content, ' ', options->width);
}
