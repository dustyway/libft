/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:21:28 by pschneid          #+#    #+#             */
/*   Updated: 2024/05/17 12:14:48 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

static int	print_conversion_num(t_print_data *pd)
{
	long			signed_value;
	unsigned long	unsigned_value;

	if (ft_strchr("di", pd->cd.specifier))
	{
		signed_value = (long)va_arg(pd->ap, int);
		if (signed_value < 0)
		{
			pd->cd.flags |= FLAG_ISNEGATIVE;
			unsigned_value = signed_value * -1;
		}
		else
			unsigned_value = signed_value;
	}
	else if ('p' == pd->cd.specifier)
		unsigned_value = (unsigned long)va_arg(pd->ap, void *);
	else
		unsigned_value = (unsigned long)va_arg(pd->ap, unsigned int);
	if (printnum(pd, unsigned_value) < 0)
		return (PRINT_ERROR);
	return (OK);
}

int	print_conversion(t_print_data *pd)
{
	if ('%' == pd->cd.specifier)
	{
		if (putchar_n(pd, '%', 1))
			return (PRINT_ERROR);
	}
	else if ('c' == pd->cd.specifier)
	{
		if (printchar(pd, va_arg(pd->ap, int)) < 0)
			return (PRINT_ERROR);
	}
	else if ('s' == pd->cd.specifier)
	{
		if (printstr(pd, va_arg(pd->ap, char *)) < 0)
			return (PRINT_ERROR);
	}
	else if (ft_strchr("dipxXu", pd->cd.specifier))
	{
		if (print_conversion_num(pd) < 0)
			return (PRINT_ERROR);
	}
	else
		return (SPECIFIER_ERROR);
	return (OK);
}

int	ft_printf(const char *fmt, ...)
{
	t_print_data	pd;

	if (!fmt)
		return (INVALID_ARGS_ERROR);
	ft_memset(&pd, 0, sizeof(t_print_data));
	va_start(pd.ap, fmt);
	pd.fmt = fmt;
	while (*pd.fmt)
	{
		if (*pd.fmt == '%' && *pd.fmt++)
		{
			if (parse_conversion(&pd))
				return (PARSE_ERROR);
			if (print_conversion(&pd))
				return (PRINT_ERROR);
		}
		else if (putchar_n(&pd, *pd.fmt, 1))
			return (PRINT_ERROR);
		pd.fmt++;
	}
	va_end(pd.ap);
	return (pd.chars_written);
}
