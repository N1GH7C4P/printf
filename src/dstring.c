/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:46:38 by linuxlite         #+#    #+#             */
/*   Updated: 2022/09/20 18:46:41 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

void	reset_all_but_count(t_dstr *dstr)
{
	free(dstr->length);
	dstr->length = ft_strnew(2);
	dstr->length[0] = ' ';
	dstr->prefix = 0;
	dstr->size = 0;
	dstr->width = 0;
	dstr->precision = 0;
	dstr->z_pad = 0;
	dstr->space = 0;
	dstr->left = 0;
	dstr->force_sign = 0;
	dstr->is_negative = 0;
	dstr->digits = 0;
	dstr->padding = 0;
	dstr->dot = 0;
	dstr->z_prec = 0;
	dstr->color_code = 0;
	dstr->c = 0;
	dstr->null = 0;
	dstr->is_zero = 0;
	dstr->lead0 = 0;
}

void	dstrdel(t_dstr *s)
{
	s->count = 0;
	free(s->length);
	free(s);
}

t_dstr	*dstrnew(void)
{	
	t_dstr	*dstr;

	dstr = (t_dstr *)malloc(sizeof(t_dstr));
	dstr->length = ft_strnew(2);
	dstr->length[0] = ' ';
	dstr->prefix = 0;
	dstr->size = 0;
	dstr->width = 0;
	dstr->precision = 0;
	dstr->z_pad = 0;
	dstr->space = 0;
	dstr->left = 0;
	dstr->force_sign = 0;
	dstr->is_negative = 0;
	dstr->digits = 0;
	dstr->padding = 0;
	dstr->dot = 0;
	dstr->z_prec = 0;
	dstr->color_code = 0;
	dstr->c = 0;
	dstr->null = 0;
	dstr->count = 0;
	dstr->is_zero = 0;
	dstr->lead0 = 0;
	return (dstr);
}

void	print_style_modifiers(t_dstr *output)
{
	if (output->color_code == 'R')
		ft_putstr(BRED);
	if (output->color_code == 'B')
		ft_putstr(BBLU);
	if (output->color_code == 'Y')
		ft_putstr(BYEL);
	if (output->color_code == 'G')
		ft_putstr(BGRN);
	if (output->color_code == 'W')
		ft_putstr(BWHT);
	if (output->color_code == 'r')
		ft_putstr(RED);
	if (output->color_code == 'b')
		ft_putstr(BLU);
	if (output->color_code == 'y')
		ft_putstr(YEL);
	if (output->color_code == 'g')
		ft_putstr(GRN);
	if (output->color_code == 'w')
		ft_putstr(WHT);
}
