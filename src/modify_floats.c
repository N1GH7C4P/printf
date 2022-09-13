#include "../include/printf.h"
#include "../include/libft.h"

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
