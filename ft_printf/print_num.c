/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:48:53 by pschneid          #+#    #+#             */
/*   Updated: 2024/05/17 17:27:04 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	calculate_num_sign_len(t_print_data *pd, unsigned long value)
{
	if (value == 0)
		pd->cd.nbr_len = 1;
	while (value && ++pd->cd.nbr_len)
		value /= pd->cd.base;
	if ((ft_strchr("xX", pd->cd.specifier) && (pd->cd.flags & FLAG_HASH)
			&& value != 0) || pd->cd.specifier == 'p')
		pd->cd.sign_len += 2;
	else if (pd->cd.flags & (FLAG_ISNEGATIVE | FLAG_PLUS | FLAG_SPACE))
		pd->cd.sign_len++;
}

static int	_putnum(t_print_data *pd, unsigned long value)
{
	char	c;

	if (value < pd->cd.base)
	{
		if (pd->cd.flags & FLAG_UPPERCASE)
			c = NUM_UPP[value];
		else
			c = NUM_LOW[value];
		if (putchar_n(pd, c, 1) < 0)
			return (PRINT_ERROR);
		return (OK);
	}
	else
	{
		if (_putnum(pd, value / pd->cd.base) < 0 || _putnum(pd, value
				% pd->cd.base) < 0)
			return (PRINT_ERROR);
		return (OK);
	}
}

static int	put_sign(t_print_data *pd, unsigned long value)
{
	if (pd->cd.base == 16)
	{
		if ((ft_strchr("xX", pd->cd.specifier) && (pd->cd.flags & FLAG_HASH)
				&& value != 0) || pd->cd.specifier == 'p')
		{
			if (pd->cd.flags & FLAG_UPPERCASE)
				return (putstr(pd, "0X", 2));
			else
				return (putstr(pd, "0x", 2));
		}
	}
	else if (pd->cd.flags & FLAG_ISNEGATIVE)
		return (putchar_n(pd, '-', 1));
	else if (pd->cd.flags & FLAG_PLUS)
		return (putchar_n(pd, '+', 1));
	else if (pd->cd.flags & FLAG_SPACE)
		return (putchar_n(pd, ' ', 1));
	return (OK);
}

void	set_padding(t_print_data *pd)
{
	if (pd->cd.precision >= 0)
	{
		if (pd->cd.precision > pd->cd.nbr_len)
			pd->cd.pad_zeros = pd->cd.precision - pd->cd.nbr_len;
	}
	else if ((pd->cd.flags & FLAG_ZEROPAD && !(pd->cd.flags & FLAG_LEFT))
		&& (pd->cd.width > pd->cd.nbr_len))
		pd->cd.pad_zeros = pd->cd.width - pd->cd.nbr_len - pd->cd.sign_len;
	if (pd->cd.pad_zeros < 0)
		pd->cd.pad_zeros = 0;
	pd->cd.pad_spaces = pd->cd.width - pd->cd.pad_zeros - pd->cd.nbr_len
		- pd->cd.sign_len;
}

int	printnum(t_print_data *pd, unsigned long value)
{
	if (pd->cd.specifier == 'p' && value == 0)
		return (pd->cd.precision = 5, printstr(pd, "(nil)") < 0);
	else if (pd->cd.precision == 0 && value == 0)
		return (putchar_n(pd, ' ', pd->cd.width));
	calculate_num_sign_len(pd, value);
	set_padding(pd);
	if (pd->cd.flags & FLAG_LEFT)
	{
		if (put_sign(pd, value) < 0 || putchar_n(pd, '0', pd->cd.pad_zeros) < 0
			|| _putnum(pd, value) < 0 || putchar_n(pd, ' ',
				pd->cd.pad_spaces) < 0)
			return (PRINT_ERROR);
	}
	else if (putchar_n(pd, ' ', pd->cd.pad_spaces) < 0 || put_sign(pd,
			value) < 0 || putchar_n(pd, '0', pd->cd.pad_zeros) < 0
		|| _putnum(pd, value) < 0)
		return (PRINT_ERROR);
	return (OK);
}
