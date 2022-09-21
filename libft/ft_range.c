/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:52:36 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/03 19:55:14 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*range;
	int		i;
	int		l;

	if (min >= max)
	{
		return (0);
	}
	i = 0;
	l = max - min;
	range = (int *) malloc(l + 1);
	while (i < l)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
