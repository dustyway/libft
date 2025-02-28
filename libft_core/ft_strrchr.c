/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:07:29 by pschneid          #+#    #+#             */
/*   Updated: 2024/04/21 16:15:10 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	ch = c;
	const char	*sc;

	sc = NULL;
	while (1)
	{
		if (*s == ch)
			sc = s;
		if (*s == '\0')
			return ((char *)sc);
		s++;
	}
}
