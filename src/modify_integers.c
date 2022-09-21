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

static void	copy_nb(t_dstr *s, char *nb)
{
	int	skip_minus;
	int	sign;

	sign = 0;
	skip_minus = 0;
	if ((s->is_negative || s->force_sign || s->space) && !s->z_prec)
		sign = 1;
	if (nb[0] == '-')
		skip_minus = 1;
	if (s->left)
		ft_memcpy(s->content + sign + s->lead0, nb + skip_minus, s->digits);
	else if (s->padding)
		ft_memcpy(s->content + s->padding, nb + skip_minus, s->digits);
	else
		ft_memcpy(s->content + s->padding + sign, nb + skip_minus, s->digits);
}

static void	handle_sign(t_dstr *s)
{
	int	i;

	i = 0;
	if (s->z_pad)
		place_sign(s, 0);
	else
	{
		while (s->content[i] == ' ')
			i++;
		if (i == 0)
			place_sign(s, 0);
		else
			place_sign(s, i - 1);
	}
}

void	modify_integers(char *input, t_dstr *s)
{
	if (s->c == 'u')
	{
		s->force_sign = 0;
		s->space = 0;
	}
	s->digits = count_digits(input);
	if (s->z_prec && s->digits == 1 && input[0] == '0')
		s->digits = 0;
	observe_minus_sign(s, input);
	calculate_output_width(s);
	s->content = ft_strnew(s->width);
	if (s->dot)
		s->z_pad = 0;
	fill_with_padding(s);
	if (s->dot)
		add_precision_zeroes(s, 0);
	copy_nb(s, input);
	handle_sign(s);
	counting_putstr(s->content, s);
	free(s->content);
}
