/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:28:09 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/27 14:34:35 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	rep_length(int num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		num /= -10;
		len += 2;
	}
	else if (num == 0)
		len = 1;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				pos;
	unsigned int	pnbr;
	char			*res;

	pos = rep_length(n);
	res = malloc(sizeof(char) * pos + 1);
	if (!res)
		return (NULL);
	res[pos--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		pnbr = n * -1;
	}
	else
		pnbr = n;
	if (pnbr == 0)
		res[0] = '0';
	while (pnbr)
	{
		res[pos--] = pnbr % 10 + '0';
		pnbr /= 10;
	}
	return (res);
}
