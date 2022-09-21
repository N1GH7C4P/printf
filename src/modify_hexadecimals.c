/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_hexadecimals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:06:08 by linuxlite         #+#    #+#             */
/*   Updated: 2022/09/21 14:01:51 by kpolojar         ###   ########.fr       */
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

	if (s->prefix == 0)
		return ;
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
			place_prefix(s, i - s->prefix);
	}
}

void	modify_hexadecimals(char *input, t_dstr *s)
{
	char	*temp;

	s->digits = ft_strlen(input);
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
