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

static void	padd_strings(t_dstr *s)
{
	ft_memset(s->content, ' ', s->width);
}

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
		ft_memcpy(s->content + sign, nb + skip_minus, s->digits);
	else if (s->padding)
		ft_memcpy(s->content + s->padding, nb + skip_minus, s->digits);
	else
		ft_memcpy(s->content + s->padding + sign, nb + skip_minus, s->digits);
}

void	modify_strings(char *input, t_dstr *s)
{
	s->digits = ft_strlen(input);
	calculate_output_width(s);
	s->content = ft_strnew(s->width);
	if (s->dot)
		s->z_pad = 0;
	padd_strings(s);
	copy_nb(s, input);
	counting_putstr(s->content, s);
	free(s->content);
}
