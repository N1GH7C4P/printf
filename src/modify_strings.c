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

static void	calculate_output_width(t_dstr *options)
{
	if(options->z_prec)
		options->digits = 0;
	if(options->is_zero || options->z_prec || options->null)
		options->prefix = 0;
	if (options->width < options->digits + options->prefix && !options->null)
		options->width = options->digits + options->prefix;
	if (options->width < options->precision && options->digits > 0)
	{
		if(options->is_negative || options->force_sign || options->space)
			options->precision++;
		options->width = options->precision;
	}
	if (options->digits < options->width - options->prefix)
		options->padding = options->width - options->digits - options->prefix;
}

static void	fill_with_padding(t_dstr *options)
{

	ft_memset(options->content, ' ', options->width);
}

static void	copy_numbers(t_dstr *options, char *numbers)
{
	int skip_minus_sign;
	int sign;

	sign = 0;
	skip_minus_sign = 0;
	if ((options->is_negative || options->force_sign || options->space) && !options->z_prec)
		sign = 1;
	if (numbers[0] == '-')
		skip_minus_sign = 1;
	if (options->left)
		ft_memcpy(options->content + sign, numbers + skip_minus_sign, options->digits);
	else if (options->padding)
		ft_memcpy(options->content + options->padding, numbers + skip_minus_sign, options->digits);
	else
		ft_memcpy(options->content + options->padding + sign, numbers + skip_minus_sign, options->digits);
}

static void	place_sign(t_dstr *options, int location)
{
	if (options->is_negative)
		options->content[location] = '-';
	else if (options->force_sign)
			options->content[location] = '+';
	else if (options->space)
		options->content[location] = ' ';
}


static void	handle_sign(t_dstr *options)
{
	int i;

	i = 0;
	if (options->z_pad)
		place_sign(options, 0);
	else
	{
		while(options->content[i] == ' ')
			i++;
		if (i == 0)
			place_sign(options, 0);
		else
			place_sign(options, i - 1);
	}
}

void	modify_strings(char *input, t_dstr *options)
{
	options->digits = ft_strlen(input);
	calculate_output_width(options);
	options->content = ft_strnew(options->width);
	if(options->dot)
		options->z_pad = 0;
	fill_with_padding(options);
	copy_numbers(options, input);
	handle_sign(options);
	//print_info(options);
	counting_putstr(options->content, options);
	free(options->content);
}
