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
	s->content[location + 1] = 'x';
}

static void	handle_prefix(t_dstr *s)
{
	int	i;

	i = 0;
	if (s->z_pad)
		place_prefix(s, 0);
	else
	{
		while (s->content[i] == ' ')
			i++;
		if (i == 0)
			place_prefix(s, 0);
		else
			place_prefix(s, i - 2);
	}
}

void	modify_pointers(char *input, t_dstr *s)
{
	s->digits = ft_strlen(input);
	observe_minus_sign(s, input);
	calculate_output_width(s);
	s->content = ft_strnew(s->width);
	if (s->dot)
		s->z_pad = 0;
	fill_with_padding(s);
	if (s->dot)
		add_precision_zeroes(s, 0);
	copy_numbers(s, input);
	handle_prefix(s);
	counting_putstr(s->content, s);
	free(s->content);
}
