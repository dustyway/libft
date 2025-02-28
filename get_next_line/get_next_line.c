/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:06:55 by pschneid          #+#    #+#             */
/*   Updated: 2024/10/04 21:06:48 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	free_and_set(char **to_free, char *new_value)
{
	free(*to_free);
	*to_free = new_value;
}

char	*get_line_and_decrease_stash(char **stash, ssize_t bytes_read)
{
	int		idx_next_line;
	char	*line;
	char	*new_stash;

	if (bytes_read < 0 || *stash == NULL)
	{
		if (*stash)
			free_and_set(stash, NULL);
		return (NULL);
	}
	else if (bytes_read == 0 && !ft_strchr(*stash, '\n'))
	{
		line = ft_strdup(*stash);
		free_and_set(stash, NULL);
		return (line);
	}
	idx_next_line = ft_strchr(*stash, '\n') - *stash + 1;
	line = ft_substr(*stash, 0, idx_next_line);
	new_stash = NULL;
	if (ft_strlen(*stash) - idx_next_line > 0)
		new_stash = ft_substr(*stash, idx_next_line, ft_strlen(*stash)
				- idx_next_line);
	free_and_set(stash, new_stash);
	return (line);
}

char	*extend_stash(char *stash, char *buf)
{
	char	*new_stash;

	if (!stash)
		new_stash = ft_strdup(buf);
	else
	{
		new_stash = ft_strjoin(stash, buf);
		free(stash);
	}
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_OPEN_FILES];
	char		*buf;
	ssize_t		bytes_read;

	if (fd < 0 || fd >= MAX_OPEN_FILES || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash[fd] && ft_strchr(stash[fd], '\n'))
		return (get_line_and_decrease_stash(&stash[fd], 0));
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buf[bytes_read] = '\0';
		stash[fd] = extend_stash(stash[fd], buf);
		if (ft_strchr(stash[fd], '\n'))
			break ;
	}
	free(buf);
	return (get_line_and_decrease_stash(&stash[fd], bytes_read));
}
