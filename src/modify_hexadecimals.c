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
    options->content[location + 1] = 'x';
}


static void	handle_prefix(t_dstr *options)
{
	int i;

	if(options->prefix == 0)
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

void	modify_hexadecimals(char *input, t_dstr *options)
{
    char *temp;

	options->digits = ft_strlen(input);
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
