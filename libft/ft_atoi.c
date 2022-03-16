/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:00:44 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/23 15:37:56 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	ft_calculate_output(char *str, int sign, int i)
{
	long	nb;

	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		if (nb > 2147483647 && sign > 0)
			return (-1);
		if (-nb < -2147483648 && sign < 0)
			return (0);
		i++;
	}
	return (nb);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	nb;
	int		i;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	nb = ft_calculate_output((char *)str, sign, i);
	return (sign * nb);
}
