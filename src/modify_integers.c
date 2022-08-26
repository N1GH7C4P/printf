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

void	modify_integers(char *input, t_dstr *options)
{
	observe_minus_sign(options, input);
	calculate_output_width(options);
	options->content = ft_strnew(options->width);
	fill_with_padding(options);
	copy_numbers(options, input);
	place_sign(options);
	counting_putstr(options->content, options);
	free(input);
}

void observe_minus_sign(t_dstr *options, char *str)
{
	if (str[0] == '-')
		options->is_negative = 1;
}

void calculate_output_width(t_dstr *options)
{
	if (options->width < options->digits)
		options->width = options->digits;
	if (options->width < options->precision && options->digits && !(options->null))
		options->width = options->precision;
	if (options->digits < options->width)
		options->padding = 1;
}

void	fill_with_padding(t_dstr *options)
{
	if ((options->z_pad && options->left) || options->digits < options->precision)
		ft_memset(options->content, '0', options->width);
	else
		ft_memset(options->content, ' ', options->width);
}

void	copy_numbers(t_dstr *options, char *numbers)
{
	int diff;
    int sign;

    if (options->force_sign && !options->is_negative)
        sign = 1;
    else
        sign = 0;
	if (options->left)
			ft_memcpy(options->content + sign, numbers, options->digits);
	else
	{
		diff = options->width - options->digits;
		ft_memcpy(options->content + diff, numbers, options->digits);
	}
}

void	place_sign(t_dstr *options)
{
	int i;

	i = 0;
	if (options->is_negative)
		return;
	while(options->content[++i] == ' ')
	{}	
	if (options->force_sign)
		options->content[i] = '+';
	else if (options->space)
		options->content[i] = ' ';
}