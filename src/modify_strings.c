/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:06:08 by linuxlite         #+#    #+#             */
/*   Updated: 2022/09/20 17:17:04 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

static void	padd_strings(t_dstr *s)
{
	if (s->null)
	{
		if (s->left)
			counting_putchar(0, s);
		if (s->padding)
		{
			s->padding--;
			s->width--;
		}
	}
	ft_memset(s->content, ' ', s->width);
}

static void	copy_str(t_dstr *s, char *str)
{
	if (s->left)
		ft_memcpy(s->content, str, s->digits);
	else
		ft_memcpy(s->content + s->padding, str, s->digits);
}

void	modify_strings(char *input, t_dstr *s)
{
	s->digits = ft_strlen(input);
	calculate_output_width(s);
	s->content = ft_strnew(s->width);
	if (s->dot)
		s->z_pad = 0;
	padd_strings(s);
	copy_str(s, input);
	counting_putstr(s->content, s);
	if (s->null && !s->left)
		counting_putchar(0, s);
	free(s->content);
}
