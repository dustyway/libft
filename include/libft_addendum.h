/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_addendum.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:24:32 by pschneid          #+#    #+#             */
/*   Updated: 2025/02/26 14:30:35 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_ADDENDUM_H
# define LIBFT_ADDENDUM_H

# include "libft.h"
# include <stddef.h>
# include <stdint.h>


uint32_t	atohex(const char *nptr);
size_t		count_words(char const *s, char c);
void		error_exit(char *msg);
void		lst_del_node(t_list **lst, void *key);
float		maxf(float x, float y);
void		*safe_malloc(size_t bytes);
void		*safe_malloc2(size_t bytes, t_list **allocs);
void		safe_write(int fd, const void *buf, size_t count);
char		*strip_nl(char *s);
void		*lst_nth(t_list *lst, size_t n);
#endif
