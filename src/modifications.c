/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:06:08 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/22 01:16:29 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

int	apply_modifications(char *str, t_dstr *output)
{
	if (output->precision > output->width)
	{
		output->width = output->precision;
		output->padding = 1;
	}
	output->digits = ft_strlen(str) - 1;
	if (str[0] == '-')
	{
		output->is_negative = 1;
		output->digits--;
		if (output->padding)
			output->width++;
	}
	if (output->width > output->precision && output->width > output->digits)
		output->padding = 1;
	apply_width_modification(&str, output);
	apply_space_modification(&str, output);
	apply_forced_sign_modification(&str, output);
	output = dstrcat(output, str);
	return (ft_strlen(str));
}

void	apply_width_modification(char **str, t_dstr *output)
{
	char	*ret;
	size_t	str_len;
	int		diff;

	str_len = ft_strlen(*str);
	if (output->width > str_len)
	{
		ret = ft_strnew(output->width);
		if (output->zero_padding && !output->left_justify && output->padding)
			ft_memset(ret, '0', output->width);
		else
			ft_memset(ret, ' ', output->width);
		if (output->left_justify)
			ft_memcpy(ret, *str, str_len);
		else
		{
			diff = output->width - str_len;
			if (output->zero_padding && output->is_negative && output->padding)
			{
				if (output->is_negative)
					ret[0] = '-';
				ft_memcpy(ret + diff + 1, *str + 1, str_len - 1);
			}
			else
				ft_memcpy(ret + diff, *str, str_len);
		}
		free(*str);
		*str = ft_strdup(ret);
		free(ret);
	}
}

void	apply_space_modification(char **str, t_dstr *output)
{
	char	*temp;

	if (output->zero_padding && output->padding && *str[0] == '0')
		*str[0] = ' ';
	else if (output->space && *str[0] != '-' && *str[0] != '+' && *str[0] != ' ')
	{
		if (*str[0] <= '9' && *str[0] >= '0')
		{
			temp = ft_strdup(*str);
			*str = ft_strnew(output->width + 1);
			*str[0] = ' ';
			ft_memcpy(*str + 1, temp, output->width);
			free(temp);
		}
		else
			*str[0] = ' ';
	}
}

void	apply_forced_sign_modification(char **str, t_dstr *output)
{
	char*	temp;
	int		str_len;
	int		i;

	str_len = ft_strlen(*str);
	i = 0;
	while (i < str_len)
	{
		if (*str[i] != ' ')
			break ;
		i++;
	}
	if (output->force_sign && *str[0] != '-')
	{
		temp = ft_strdup(*str);
		free(*str);
		*str = ft_strnew(str_len + 1);
		*str[0] = '+';
		*str = ft_strjoin(*str, temp);
		free(temp);
	}
}
