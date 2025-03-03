/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:40:03 by pschneid          #+#    #+#             */
/*   Updated: 2024/05/17 17:28:06 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "unistd.h"

int	putchar_n(t_print_data *pd, int c, int n)
{
	int	i;

	i = 0;
	while (i < n && ++i)
	{
		if (write(1, &c, 1) == 1)
			pd->chars_written++;
		else
			return (PRINT_ERROR);
	}
	return (OK);
}

int	putstr(t_print_data *pd, char *s, int maxlen)
{
	int	len;

	len = ft_strlen(s);
	if (maxlen < len)
		len = maxlen;
	if (write(1, s, len) == len)
		pd->chars_written += len;
	else
		return (PRINT_ERROR);
	return (OK);
}

int	printchar(t_print_data *pd, int c)
{
	int	width;

	width = pd->cd.width;
	if (pd->cd.flags & FLAG_LEFT)
	{
		if (putchar_n(pd, c, 1) < 0 || putchar_n(pd, ' ', width - 1) < 0)
			return (PRINT_ERROR);
	}
	else
	{
		if (putchar_n(pd, ' ', width - 1) < 0 || putchar_n(pd, c, 1) < 0)
			return (PRINT_ERROR);
	}
	return (OK);
}

static void	calculate_str_padding(t_print_data *pd, char *s)
{
	int	len;

	len = ft_strlen(s);
	if (pd->cd.width > 0)
	{
		if (pd->cd.precision >= 0)
		{
			if (pd->cd.precision >= len)
				pd->cd.pad_spaces = pd->cd.width - len;
			else if (pd->cd.precision < len)
				pd->cd.pad_spaces = pd->cd.width - pd->cd.precision;
		}
		else
			pd->cd.pad_spaces = pd->cd.width - len;
	}
}

int	printstr(t_print_data *pd, char *s)
{
	int	len;

	if (!s && ((pd->cd.precision == -1 || pd->cd.precision >= 6)))
		s = "(null)";
	else if (!s)
		s = "";
	calculate_str_padding(pd, s);
	len = ft_strlen(s);
	if (pd->cd.precision >= 0)
		len = pd->cd.precision;
	if (pd->cd.flags & FLAG_LEFT)
	{
		if (putstr(pd, s, len) < 0 || putchar_n(pd, ' ',
				pd->cd.pad_spaces) < 0)
			return (PRINT_ERROR);
	}
	else
	{
		if (putchar_n(pd, ' ', pd->cd.pad_spaces) < 0 || putstr(pd, s,
				len) < 0)
			return (PRINT_ERROR);
	}
	return (OK);
}
