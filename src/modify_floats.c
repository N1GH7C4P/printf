#include "../include/printf.h"
#include "../include/libft.h"

static void	observe_minus_sign(t_dstr *options, char *str)
{
	if (str[0] == '-')
		options->is_negative = 1;
}

static void	calculate_output_width(t_dstr *options)
{
	if (options->width < options->digits)
		options->width = options->digits;
	if (options->width < options->precision)
	{
		if(options->is_negative || options->force_sign || options->space)
			options->precision++;
		options->width = options->precision;
	}
    else if (options->width == options->digits && (options->is_negative || options->force_sign || options->space))
        options->width++;
	else if (options->digits < options->width)
		options->padding = options->width - options->digits;
}

static void	fill_with_padding(t_dstr *options)
{
	if (options->z_pad && options->padding && !options->dot)
		ft_memset(options->content, '0', options->width);
	else
		ft_memset(options->content, ' ', options->width);
}

static void	copy_numbers(t_dstr *options, char *numbers)
{
	int skip_minus_sign;
	int sign;

	sign = 0;
	skip_minus_sign = 0;
	if ((options->is_negative || options->force_sign || options->space) && !options->z_prec)
		sign = 1;
	if (numbers[0] == '-')
		skip_minus_sign = 1;
	if (options->left)
		ft_memcpy(options->content + sign, numbers + skip_minus_sign, options->digits);
	else if (options->padding)
		ft_memcpy(options->content + options->padding, numbers + skip_minus_sign, options->digits);
	else
		ft_memcpy(options->content + options->padding + sign, numbers + skip_minus_sign, options->digits);
    options->content[options->width] = '\0';
}


static size_t	count_digits(char *str)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
        if (str[i] == '.')
            count++;
		if (str[i] >= '0' && str[i] <= '9')
			count++;
		i++;
	}
	return count;
}


static void	place_sign(t_dstr *options, int location)
{
	if (options->is_negative)
		options->content[location] = '-';
	else if (options->force_sign)
			options->content[location] = '+';
	else if (options->space)
		options->content[location] = ' ';
}


static void	handle_sign(t_dstr *options)
{
	int i;

	i = 0;
	if (options->z_pad)
		place_sign(options, 0);
	else
	{
		while(options->content[i] == ' ')
			i++;
		if (i == 0)
			place_sign(options, 0);
		else
			place_sign(options, i - 1);
	}
}

static void	add_precision_zeroes(t_dstr *options)
{
	int diff;
	int padd;

	diff = options->precision - options->digits;
	padd = options->width - options->digits - 1;
	while (diff > 0)
	{
		options->content[padd--] = '0';
		diff--;
	}
}

void	modify_floats(char *input, t_dstr *options)
{
	options->digits = count_digits(input);
	observe_minus_sign(options, input);
	calculate_output_width(options);
	options->content = ft_strnew(options->width);
	if(options->dot)
		options->z_pad = 0;
	fill_with_padding(options);
	if (options->dot)
		add_precision_zeroes(options);
	copy_numbers(options, input);
	handle_sign(options);
    print_info(options);
	counting_putstr(options->content, options);
	free(options->content);
}
