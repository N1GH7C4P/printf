/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:18:55 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/22 16:08:36 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(const char *dest, const char *src)
{
	char	*start;
	char	*cdest;
	char	*csrc;

	csrc = (char *)src;
	cdest = (char *)dest;
	start = cdest;
	while (*csrc != '\0')
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
	}
	*cdest = '\0';
	return (start);
}
