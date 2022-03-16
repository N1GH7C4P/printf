/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:46:38 by linuxlite         #+#    #+#             */
/*   Updated: 2022/03/14 16:11:19 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	reset_dstr_flags_and_mods(t_dstr *dstr)
{
	free(dstr->length);
	dstr->length = ft_strnew(2);
	dstr->binary_prefix = 0;
	dstr->size = 0;
	dstr->width = 0;
	dstr->precision = 0;
	dstr->zero_padding = 0;
	dstr->space = 0;
	dstr->left_justify = 0;
	dstr->force_sign = 0;
	dstr->is_negative = 0;
	dstr->digits = 0;
	dstr->padding = 0;
}

void	dstrdel(t_dstr *s)
{
	free(s->content);
	free(s->length);
	free(s);
}

t_dstr	*dstrnew(char *src)
{	
	t_dstr	*new_dstr;
	size_t	src_len;

	src_len = ft_strlen(src);
	new_dstr = (t_dstr *)malloc(sizeof(t_dstr));
	new_dstr->length = ft_strnew(2);
	if (src_len)
		new_dstr->size = src_len;
	else
		new_dstr->size = 0;
	if (*src)
		new_dstr->content = ft_strdup(src);
	else
		new_dstr->content = ft_strnew(0);
	return (new_dstr);
}

t_dstr	*dstrcat(t_dstr *dst, char *src)
{
	char	*temp;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst->content);
	if (dst->size <= src_len + dst_len)
	{
		while (dst->size <= src_len + dst_len)
			dst->size = (dst->size + 1) * 2;
		temp = ft_strdup(dst->content);
		free(dst->content);
		dst->content = ft_strnew(dst->size);
		ft_memcpy(dst->content, temp, dst_len);
		free(temp);
	}
	ft_memcpy(dst->content + dst_len, src, src_len);
	dst->content[dst_len + src_len] = '\0';
	return (dst);
}

t_dstr	*dstrncat(t_dstr *dst, char *src, size_t n)
{
	char	*temp;
	size_t	dst_len;

	dst_len = ft_strlen(dst->content);
	if (dst->size < n + dst_len + 1)
	{
		while (dst->size < n + dst_len + 1)
			dst->size = (dst->size + 1) * 2;
		temp = ft_strdup(dst->content);
		free(dst->content);
		dst->content = ft_strnew(dst->size);
		ft_memcpy(dst->content, temp, dst_len);
		free(temp);
	}
	ft_memcpy(dst->content + dst_len, src, n);
	dst->content[dst_len + n] = '\0';
	return (dst);
}
