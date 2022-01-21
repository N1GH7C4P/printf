/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 01:14:47 by linuxlite         #+#    #+#             */
/*   Updated: 2022/01/21 02:51:18 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int	ft_printf(char *str, ...)
{
	va_list	vl;
	int		i;
	int		j;
	char	buff[BUFF_SIZE];
	char	*tmp;

	i = 0;
	j = 0;
	va_start(vl, str);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				buff[j] = (char)va_arg(vl, int);
				j++;
				break ;
			}
			else if (str[i] == 'd')
			{
				tmp = ft_itoa(va_arg(vl, int));
				ft_strcpy(&buff[j], tmp);
				j += ft_strlen(tmp);
				break ;
			}
			else if (str[i] == 'x')
			{
				tmp = ft_itoa(va_arg(vl, int));
				ft_strcpy(&buff[j], tmp);
				j += ft_strlen(tmp);
				break ;
			}
		}
		else
		{
			buff[j] = str[i];
			j++;
		}
		i++;
	}
	write(1, buff, j);
	va_end(vl);
	return (j);
}
