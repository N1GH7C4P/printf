/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:02:10 by kpolojar          #+#    #+#             */
/*   Updated: 2022/03/25 16:36:23 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define BUFF_SIZE 100
# include <stdarg.h>
# include <unistd.h>

// Dynamic Strings

typedef struct s_dstr
{
	char	*content;
	char	*length;
	size_t	size;
	size_t	width;
	size_t	precision;
	size_t	digits;
	int		hex_prefix;
	int		zero_padding;
	int		space;
	int		left_justify;
	int		force_sign;
	int		is_negative;
	int		padding;
	int		dot;
	int		zero_precision;
}	t_dstr;

//Totally unintentional megastruct
t_dstr	*dstrnew(char *src);
t_dstr	*dstrcat(t_dstr *dst, char *src);
t_dstr	*dstrncat(t_dstr *dst, char *src, size_t n);
void	reset_dstr_flags_and_mods(t_dstr *dstr);
void	dstrdel(t_dstr *s);

// numbers to str conversion
char	*ft_itoabase(long long value, int base);
char	*ft_unsigned_itoabase(unsigned long long value, int base);
char	*ft_ftoa(long double n, size_t precision);

// printf
int		ft_printf(char *str, ...);

// utility functions
char	*str_toupper(char *src);

// handlers
int		handle_length(t_dstr *output, char *input);
int		handle_flags(t_dstr *output, char *input);
int		handle_width(t_dstr *output, char *input);
int		handle_conversion(t_dstr *output, va_list vl, char c);
int		handle_precision(t_dstr *output, char *input);

// formatting
char	*format_floats(t_dstr *s, va_list vl);
char	*format_hexadecimal_numbers(char c, t_dstr *s, va_list vl);
char	*format_str(t_dstr *s, va_list vl);
char	*format_unsigned_numbers(t_dstr *s, va_list vl, int base);
char	*format_numbers(t_dstr *s, va_list vl, int base);

//Modifications
int		apply_modifications(char *str, t_dstr *output);
char	*apply_width_modification(char *str, t_dstr *output);
char	*apply_sign_modification(char *str, t_dstr *output);

#endif