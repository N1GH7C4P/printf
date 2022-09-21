/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_octals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:06:08 by linuxlite         #+#    #+#             */
/*   Updated: 2022/09/21 14:10:19 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

static void	calculate_octal_output_width(t_dstr *s)
{
	if (s->z_prec && s->null)
		s->digits = 0;
	if (s->is_zero && !s->z_prec)
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

static void	copy_numbers(t_dstr *s, char *numbers)
{
	if (s->left)
		ft_memcpy(s->content + s->prefix, numbers, s->digits);
	else if (s->padding)
		ft_memcpy(s->content + s->padding + s->prefix, numbers, s->digits);
	else
		ft_memcpy(s->content + s->padding + s->prefix, numbers, s->digits);
}

static void	place_prefix(t_dstr *s, int location)
{
	s->content[location] = '0';
}

static void	handle_prefix(t_dstr *s)
{
	int	i;

	if (!s->prefix)
		return ;
	i = 0;
	if (s -> z_pad)
		place_prefix(s, 0);
	else
	{
		while (s -> content[i] == ' ')
			i++;
		if (i == 0)
			place_prefix(s, 0);
		else
			place_prefix(s, i - s->prefix);
	}
}

void	modify_octals(char *input, t_dstr *s)
{
	char	*temp;

	s->digits = ft_strlen(input);
	if (s->z_prec && s->digits == 1 && input[0] == '0')
		s->digits = 0;
	observe_minus_sign(s, input);
	calculate_octal_output_width(s);
	s->content = ft_strnew(s->width);
	if (s -> dot)
		s->z_pad = 0;
	fill_with_padding(s);
	if (s->dot)
		add_precision_zeroes(s, 0);
	copy_numbers(s, input);
	handle_prefix(s);
	if (s->c == 'X')
	{
		temp = ft_str_toupper(s->content);
		counting_putstr(temp, s);
		free(temp);
	}
	else
		counting_putstr(s->content, s);
	free(s->content);
}
