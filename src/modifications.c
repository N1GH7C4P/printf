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

char	*place_sign(char *r, t_dstr *s, int i)
{
	char	*temp;
	size_t	len;

	if (i == 0 && ((r[0] > '0' && r[0] <= '9') || (r[0] == '0' && !s->z_pad)))
	{
		temp = ft_strdup(r);
		len = ft_strlen(r);
		if (len < s->width)
			len--;
		r = ft_strnew(len);
		ft_memcpy(r + 1, temp, len);
		free(temp);
	}
	if (!r[i + 1])
		r[i + 1] = '0';
	if (s->is_negative)
		r[i] = '-';
	else if (s->force_sign)
		r[i] = '+';
	else if (s->space)
		r[i] = ' ';
	return (r);
}

void	apply_modifications(char *str, t_dstr *s)
{
	if (str[0] == '-')
	{
		s->is_negative = 1;
		str = ft_strdup(str + 1);
		s->digits--;
	}
	if (s->width < s->digits)
		s->width = s->digits;
	if (s->width < s->precision && s->digits && !(s->null))
		s->width = s->precision;
	if (s->digits < s->width)
		s->padding = 1;
	str = apply_width_modification(str, s);
	str = apply_sign_modification(str, s);
	if (s->c == 'X')
		str = ft_str_toupper(str);
	print_style_modifiers(s);
	if (s->null && s->width < 2)
		counting_putchar(str[0], s);
	else
		counting_putstr(str, s);
}

char	*add_prefix(t_dstr *s, char *str)
{
	int is_zero;
	int	i;

	is_zero = 1;
	i = 0;
	while (str[i])
	{
		if (str[i++] != '0')
			is_zero = 0;
	}
	if ((s->c == 'p' || s->c == 'x' || s->c == 'X') && s->prefix && !is_zero)
	{
		str = ft_strjoin("0x", str);
		s->digits += 2;
	}
	return (str);
}

char	*add_spaces_and_zeroes(t_dstr *s, char *str)
{
	char	*ret;
	int		width;

	width = s->width;
	ret = ft_strnew(s->width);
	if (!s->left && (s->z_pad) && str[0] != '0' && !s->null)
	{
		if (s->padding && !s->z_prec)
		{
			while (width)
				ret[--width] = '0';
		}
	}
	while (width)
		ret[--width] = ' ';
	return (ret);
}

char	*apply_width_modification(char *str, t_dstr *s)
{
	char	*ret;
	int		diff;

	str = add_prefix(s, str);
	if (s->padding)
	{
		ret = add_spaces_and_zeroes(s, str);
		if (s->left)
			ft_memcpy(ret, str, s->digits);
		else
		{
			diff = s->width - s->digits;
			ft_memcpy(ret + diff, str, s->digits);
		}
		str = ft_strdup(ret);
		free(ret);
	}
	return (str);
}

char	*apply_sign_modification(char *str, t_dstr *s)
{
	char	*temp;
	int		i;

	i = 0;
	if ((s->space || s->force_sign || s->is_negative) && s->c != 'u')
	{
		while (str[i + 1] == ' ')
			i++;
		temp = ft_strdup(str);
		str = ft_strnew(s->width + 1);
		ft_memcpy(str, temp, s->width + 1);
		str = place_sign(str, s, i);
		free(temp);
	}
	if (s->left && str[ft_strlen(str) - 1] == ' ' && ft_strlen(str) > s->width)
		str[ft_strlen(str) - 1] = 0;
	return (str);
}
