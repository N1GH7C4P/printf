/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:56:38 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/22 16:09:42 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char			*heystack;
	unsigned char	needle;

	heystack = (char *)str;
	needle = (unsigned char)c;
	while (*heystack != needle)
	{
		if (needle != '\0' && *heystack == '\0')
			break ;
		heystack++;
	}
	if (needle == *heystack)
		return (heystack);
	return (0);
}
