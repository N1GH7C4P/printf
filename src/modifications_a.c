/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:06:08 by linuxlite         #+#    #+#             */
/*   Updated: 2022/09/20 18:26:41 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

void	apply_modifications(char *input, t_dstr *s)
{
	if (s -> c == 'i' || s -> c == 'd' || s -> c == 'u')
		modify_integers(input, s);
	else if (s -> c == 'f')
		modify_floats(input, s);
	else if (s -> c == 'p')
		modify_pointers(input, s);
	else if (s -> c == 'x' || s -> c == 'X')
		modify_hexadecimals(input, s);
	else if (s -> c == 'o')
		modify_octals(input, s);
	else if (s -> c == 's' || s -> c == 'c')
		modify_strings(input, s);
	free(input);
}

void	calculate_output_width(t_dstr *s)
{
	if (s->z_prec && s->null)
		s->digits = 0;
	if (((s->null || s->is_zero) && s->c != 'o'))
		s->prefix = 0;
	if (s->width < s->digits + s->prefix && !s->null)
		s->width = s->digits + s->prefix;
	if (s->width < s->precision && s->digits > 0)
	{
		if (s->is_negative || s->force_sign || s->space)
			s->precision++;
		s->width = s->precision;
	}
	if (s->digits < s->width - s->prefix)
		s->padding = s->width - s->digits - s->prefix;
}

void	observe_minus_sign(t_dstr *s, char *str)
{
	if (str[0] == '-')
		s->is_negative = 1;
}

void	add_precision_zeroes(t_dstr *s, int i)
{
	int	diff;
	int	padd;

	diff = s->precision - s->digits;
	padd = s->width - s->digits - 1;
	if (!s->left)
	{
		while (diff > 0)
		{
			s->content[padd--] = '0';
			diff--;
		}
	}
	else
	{
		if (s -> is_negative || s->force_sign || s -> space)
			i++;
		while (diff > 0)
		{
			s->content[i] = '0';
			s->lead0++;
			diff--;
			i++;
		}
	}
}

void	fill_with_padding(t_dstr *s)
{
	if (s->z_pad && s->padding && !s->dot && !s->left)
		ft_memset(s->content, '0', s->width);
	else
		ft_memset(s->content, ' ', s->width);
}
