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
		ft_memcpy(options->content + sign + options->lead0, numbers + skip_minus_sign, options->digits);
	else if (options->padding)
		ft_memcpy(options->content + options->padding, numbers + skip_minus_sign, options->digits);
	else
		ft_memcpy(options->content + options->padding + sign, numbers + skip_minus_sign, options->digits);
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

void	modify_integers(char *input, t_dstr *options)
{
	if (options->c == 'u')
	{
		options->force_sign = 0;
		options->space = 0;
	}
	options->digits = count_digits(input);
	if (options->z_prec && options->digits == 1 && input[0] == '0')
		options->digits = 0;
	observe_minus_sign(options, input);
	calculate_output_width(options);
	options->content = ft_strnew(options->width);
	if(options->dot)
		options->z_pad = 0;
	fill_with_padding(options);
	if (options->dot)
		add_precision_zeroes(options);
	copy_numbers(options, input);
	handle_sign(options);
	//print_info(options);
	counting_putstr(options->content, options);
	free(options->content);
}
