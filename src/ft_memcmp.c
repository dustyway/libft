/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:01:24 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/26 18:59:59 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*su1 = s1;
	const unsigned char	*su2 = s2;

	while (n > 0)
	{
		if (*su1 != *su2)
			return (*su1 - *su2);
		su1++;
		su2++;
		n--;
	}
	return (0);
}
