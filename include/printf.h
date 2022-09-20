/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:02:10 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/20 14:23:42 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define BOOL char
# include <stdarg.h>
# include <unistd.h>

// Megastruct

typedef struct s_dstr
{
	char	c;
	char	color_code;
	char	*content;
	char	*length;
	size_t	size;
	size_t	width;
	size_t	precision;
	size_t	digits;
	size_t	count;
	size_t	lead0;
	BOOL	prefix;
	BOOL	z_pad;
	BOOL	space;
	BOOL	left;
	BOOL	force_sign;
	BOOL	is_negative;
	BOOL	padding;
	BOOL	dot;
	BOOL	z_prec;
	BOOL	null;
	BOOL	is_zero;

}	t_dstr;

// megastruct functions
t_dstr	*dstrnew(void);
void	reset_all_but_count(t_dstr *s);
void	dstrdel(t_dstr *s);
void	print_info(t_dstr *dstr);

// numbers to str conversion
char	*ft_itoabase(long long value, int base);
char	*ft_unsigned_itoabase(unsigned long long value, int base);
char	*ft_ftoa(long double n, size_t p, long double f_part, long long i_part);

// printf
int		ft_printf(char *str, ...);

// utility functions
int		find_dot(char *str);
int		check_f_digits(char *str);
int		count_fdigits(long double f, int max_precision);
int		counting_putstr(char *str, t_dstr *s);
int		counting_putchar(char c, t_dstr *s);

// handlers
int		handle_length(t_dstr *output, char *input);
int		handle_flags(t_dstr *output, char *input);
int		handle_width(t_dstr *output, char *input);
int		handle_precision(t_dstr *output, char *input);
int		handle_style(t_dstr *output, char *input);
void	handle_conversion(t_dstr *output, va_list vl, char c, char *str);

// formatting
char	*format_char(va_list vl, t_dstr *s);
char	*format_str(t_dstr *s, va_list vl);
char	*format_floats(t_dstr *s, va_list vl);
char	*format_hexadecimal_numbers(t_dstr *s, va_list vl);
char	*format_octal_numbers(t_dstr *s, va_list vl);
char	*format_binary_numbers(t_dstr *s, va_list vl);
char	*format_unsigned_numbers(t_dstr *s, va_list vl, int base);
char	*format_numbers(t_dstr *s, va_list vl, int base);
char	*format_pointers(t_dstr *s, va_list vl);

// Modifications
void	apply_modifications(char *str, t_dstr *output);

void	modify_floats(char *input, t_dstr *options);
void	modify_integers(char *input, t_dstr *options);
void	modify_pointers(char *input, t_dstr *options);
void	modify_hexadecimals(char *input, t_dstr *options);
void	modify_octals(char *input, t_dstr *options);
void	modify_strings(char *input, t_dstr *options);
int		modify_percent_sign(t_dstr *s, int i);

void	calculate_output_width(t_dstr *options);
void	fill_with_padding(t_dstr *options);
void	observe_minus_sign(t_dstr *options, char *input);
void	place_sign(t_dstr *options, int location);
size_t	count_digits(char *str);
void	add_precision_zeroes(t_dstr *options, int i);

// style

void	print_style_modifiers(t_dstr *output);

// color codes

// regular text
# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define WHT "\e[0;37m"

// bold text
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BWHT "\e[1;37m"

// reset
# define STYLE_RESET "\e[0m"

#endif