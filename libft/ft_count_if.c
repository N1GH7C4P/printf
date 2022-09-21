/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:41:40 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/03 13:41:33 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int		result;
	int		count;
	int		i;

	i = 0;
	count = 0;
	result = 0;
	if (!tab)
	{
		return (0);
	}
	while (tab[i])
	{
		result = f(tab[i]);
		if (result == 1)
		{
			count++;
		}
		i++;
	}
	return (count);
}
