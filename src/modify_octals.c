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

static void	observe_minus_sign(t_dstr *options, char *str)
{
	if (str[0] == '-')
		options->is_negative = 1;
}

static void	calculate_output_width(t_dstr *options)
{
	if (options->width < options->digits + options->prefix)
		options->width = options->digits + options->prefix;
	if (options->width < options->precision)
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
	if (options->z_pad && options->padding && !options->dot)
		ft_memset(options->content, '0', options->width);
	else
		ft_memset(options->content, ' ', options->width);
}

static void	copy_numbers(t_dstr *options, char *numbers)
{
	if (options->left)
		ft_memcpy(options->content + options->prefix, numbers, options->digits);
	else if (options->padding)
		ft_memcpy(options->content + options->padding + options->prefix, numbers, options->digits);
	else
		ft_memcpy(options->content + options->padding + options->prefix, numbers, options->digits);
}


static void	place_prefix(t_dstr *options, int location)
{
	options->content[location] = '0';
}


static void	handle_prefix(t_dstr *options)
{
	int i;

	if(!options->prefix || options->is_zero)
		return;
	i = 0;
	if (options->z_pad)
		place_prefix(options, 0);
	else
	{
		while(options->content[i] == ' ')
			i++;
		if (i == 0)
			place_prefix(options, 0);
		else
			place_prefix(options, i - options->prefix);
	}
}


static void	add_precision_zeroes(t_dstr *options)
{
	int diff;
	int padd;

	diff = options->precision - options->digits;
	padd = options->width - options->digits - 1;
	while (diff > 0)
	{
		options->content[padd--] = '0';
		diff--;
	}
}

void	modify_octals(char *input, t_dstr *options)
{
    char *temp;

	options->digits = ft_strlen(input);
	observe_minus_sign(options, input);
	calculate_output_width(options);
	options->content = ft_strnew(options->width);
	if(options->dot)
		options->z_pad = 0;
	fill_with_padding(options);
	if (options->dot)
		add_precision_zeroes(options);
	copy_numbers(options, input);
	handle_prefix(options);
    if (options->c == 'X')
    {
        temp = ft_str_toupper(options->content);
        counting_putstr(temp, options);
        free(temp);
    }
    else
    {
        counting_putstr(options->content, options);
    }
	free(options->content);
}
