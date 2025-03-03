/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:34:16 by pschneid          #+#    #+#             */
/*   Updated: 2024/05/17 17:12:24 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	_atoi(t_print_data *pd)
{
	int	value;

	value = 0;
	while (ft_isdigit(*pd->fmt))
		value = (value * 10) + (*pd->fmt++ - '0');
	return (value);
}

static void	parse_num(t_print_data *pd, int *value, char fix_neg)
{
	if (*pd->fmt == '*')
	{
		*value = va_arg(pd->ap, int);
		pd->fmt++;
		if (fix_neg && *value <= 0)
		{
			*value *= (-1);
			pd->cd.flags |= FLAG_LEFT;
		}
		return ;
	}
	*value = _atoi(pd);
}

static void	parse_flags(t_print_data *pd)
{
	while (ft_strchr(FLAGS, *pd->fmt))
	{
		if ('-' == *pd->fmt)
			pd->cd.flags |= FLAG_LEFT;
		else if ('0' == *pd->fmt)
			pd->cd.flags |= FLAG_ZEROPAD;
		else if ('#' == *pd->fmt)
			pd->cd.flags |= FLAG_HASH;
		else if (' ' == *pd->fmt)
			pd->cd.flags |= FLAG_SPACE;
		else if ('+' == *pd->fmt)
			pd->cd.flags |= FLAG_PLUS;
		pd->fmt++;
	}
}

int	parse_conversion(t_print_data *pd)
{
	ft_memset(&pd->cd, 0, sizeof(t_conversion_data));
	pd->cd.precision = -1;
	parse_flags(pd);
	parse_num(pd, &pd->cd.width, 1);
	if (*pd->fmt == '.' && *(pd->fmt++))
		parse_num(pd, &pd->cd.precision, 0);
	if (!ft_strchr(SPECIFIERS, *pd->fmt))
		return (PARSE_ERROR);
	else
	{
		pd->cd.specifier = *pd->fmt;
		if (ft_strchr("diu", pd->cd.specifier))
			pd->cd.base = 10;
		else if (ft_strchr("xXp", pd->cd.specifier))
		{
			pd->cd.base = 16;
			if ('X' == pd->cd.specifier)
				pd->cd.flags |= FLAG_UPPERCASE;
		}
	}
	return (OK);
}
