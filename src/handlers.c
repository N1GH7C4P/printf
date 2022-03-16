/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:13:34 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/14 17:00:57 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include "stdint.h"

int	handle_width(t_dstr *output, char *input)
{
	int	i;

	output->width = ft_atoi(input);
	i = ft_countdigits(output->width, 10);
	return (i);
}

int	handle_flags(t_dstr *output, char *input)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (input[i] == '#')
			output->binary_prefix = 1;
		else if (input[i] == '0')
			output->zero_padding = 1;
		else if (input[i] == '-')
			output->left_justify = 1;
		else if (input[i] == '+')
			output->force_sign = 1;
		else if (input[i] == ' ')
			output->space = 1;
		else
			break ;
		i++;
	}
	return (i);
}

int	handle_length(t_dstr *output, char *input)
{
	int	i;

	i = 0;
	if (input[i] == 'l' || input[i] == 'h')
	{
		output->length[i] = input[i];
		i++;
		if (input[i] == input[i - 1])
		{
			output->length[i] = input[i];
			i++;
		}
	}
	else if (input[i] == 'L')
	{
		output->length[i] = 'L';
		i++;
	}
	return (i);
}

void	str_toupper(char **str)
{
	size_t	len;

	len = ft_strlen(*str);
	while (len)
	{
		*str[len - 1] = (char)ft_toupper((int)*str[len - 1]);
		len--;
	}
}

int	handle_conversion(t_dstr *output, va_list vl, char c)
{	
	char	*str;

	str = NULL;
	if (c == 'c')
	{
		str = ft_strnew(1);
		c = (char)va_arg(vl, int);
		ft_memcpy(str, &c, 1);
	}
	else if (c == 'u')
		str = format_unsigned_numbers(output, vl);
	else if (c == 'd' || c == 'i')
		str = format_real_numbers(output, vl);
	else if (c == 's')
		str = format_str(str, output, vl);
	else if (c == 'p')
		str = ft_strjoin("0x", ft_itoabase(va_arg(vl, unsigned long long), 16));
	else if (c == 'X' || c == 'x')
		str = format_hexadecimal_numbers(c, output, vl);
	else if (c == 'f')
		str = format_floats(output, vl);
	return (apply_modifications(str, output));
}
