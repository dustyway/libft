/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:14:58 by pschneid          #+#    #+#             */
/*   Updated: 2024/12/18 12:56:32 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	safe_write(int fd, const void *buf, size_t count)
{
	ssize_t	bytes_written;

	bytes_written = write(fd, buf, count);
	if (bytes_written < 0 || (size_t)bytes_written != count)
	{
		ft_putstr_fd("Failed to write, aborting...\n", 2);
		exit(EXIT_FAILURE);
	}
}
