/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:06:08 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/25 22:56:40 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

char *place_sign(char *str, t_dstr *output, int index)
{
	char *temp;
	int len;

	if (index == 0 && str[0] > '0' && str[0] < '9')
	{
		temp = ft_strdup(str);
		len = ft_strlen(str);
		str = ft_strnew(len + 1);
		ft_memcpy(str + 1, temp, len);
	}
	if (output->is_negative)
		str[index] = '-';
	else if (output->force_sign)
		str[index] = '+';
	else if (output->space)
		str[index] = ' ';
	return(str);
}

int	apply_modifications(char *str, t_dstr *output)
{
	if(str[0] == '-')
	{
		output->is_negative = 1;
		str = ft_strdup(str + 1);
	}
	if (output->width < output->digits)
		output->width = output->digits;
	if (output->width < output->precision)
		output->width = output->precision;
	if (output->digits < output->width)
		output->padding = 1;
	str = apply_width_modification(str, output);
	str = apply_sign_modification(str, output);
	output = dstrcat(output, str);
	return (ft_strlen(str));
}

char	*add_spaces_and_zeroes(t_dstr *output)
{
	char	*ret;
	int		precision;
	int		width;
	width = output->width;
	precision = output->precision;
	ret = ft_strnew(output->width);
	if (output->zero_padding && !output->left_justify && output->padding && !output->zero_precision)
	{	
		while (precision)
		{
			ret[--width] = '0';
			precision--;
		}
	}
	while (width > 0)
		ret[--width] = ' ';
	return (ret);
}

char	*apply_width_modification(char *str, t_dstr *output)
{
	char	*ret;
	int		diff;

	if (output->padding)
	{
		ret = add_spaces_and_zeroes(output);
		if (output->left_justify)
			ft_memcpy(ret, str, output->digits);
		else
		{
			diff = output->width - output->digits;
			ft_memcpy(ret + diff, str, output->digits);
		}
		str = ft_strdup(ret);
		free(ret);
	}
	return (str);
}

char	*apply_sign_modification(char *str, t_dstr *output)
{
	char	*temp;
	int 	i;

	i = 0;
	if (output->space || output->force_sign || output->is_negative)
	{
		while (str[i + 1] == ' ')
			i++;
		temp = ft_strdup(str);
		str = ft_strnew(output->width + 1);
		ft_memcpy(str, temp, output->width + 1);
		str = place_sign(str, output, i);
		free(temp);
	}
	return (str);
}
