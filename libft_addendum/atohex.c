/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atohex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:49:30 by pschneid          #+#    #+#             */
/*   Updated: 2024/12/08 14:49:43 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdint.h>

static int	hexval(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

uint32_t	atohex(const char *nptr)
{
	uint32_t	n;
	int			hv;

	n = 0;
	if (nptr[0] == '0' && nptr[1] == 'x')
	{
		nptr += 2;
		while (1)
		{
			hv = hexval(*nptr++);
			if (hv < 0)
				break ;
			n = 16 * n + hv;
		}
	}
	return (n);
}
