/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:06:08 by linuxlite         #+#    #+#             */
/*   Updated: 2022/04/01 01:31:43 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../include/libft.h"

void	apply_modifications(char *input, t_dstr *options)
{
	if (options -> c == 'i' || options -> c == 'd' || options -> c == 'u')
		modify_integers(input, options);
	else if (options -> c == 'f')
		modify_floats(input, options);
	else if (options -> c == 'p')
		modify_pointers(input, options);
	free(input);
}

