/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:43:00 by kpolojar          #+#    #+#             */
/*   Updated: 2022/03/13 21:18:14 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countdigits(unsigned long long nb, int base)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / base;
		count++;
	}
	return (count);
}
