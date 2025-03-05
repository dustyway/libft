/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:07:30 by pschneid          #+#    #+#             */
/*   Updated: 2024/05/17 17:24:15 by pschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define FLAGS "-0# +"
# define FLAG_LEFT 1
# define FLAG_ZEROPAD 2
# define FLAG_HASH 4
# define FLAG_SPACE 8
# define FLAG_PLUS 16
# define FLAG_UPPERCASE 32
# define FLAG_ISNEGATIVE 64
/* #define FLAGS_PRECISION 128 */

# define SPECIFIERS "cspdiuxX%"
# define NUM_LOW "0123456789abcdef"
# define NUM_UPP "0123456789ABCDEF"

typedef struct s_conversion_data
{
	unsigned int		flags;
	char				specifier;
	int					width;
	int					precision;
	unsigned int		base;
	int					nbr_len;
	int					sign_len;
	int					pad_spaces;
	int					pad_zeros;
}						t_conversion_data;

typedef struct s_print_data
{
	va_list				ap;
	const char			*fmt;
	int					chars_written;
	t_conversion_data	cd;
}						t_print_data;

typedef enum e_error
{
	OK = 0,
	INVALID_ARGS_ERROR = -1,
	PRINT_ERROR = -2,
	PARSE_ERROR = -3,
	SPECIFIER_ERROR = -4
}						t_error;

int						parse_conversion(t_print_data *pd);
int						putchar_n(t_print_data *pd, int c, int n);
int						printchar(t_print_data *pd, int c);
int						putstr(t_print_data *pd, char *s, int maxlen);
int						printstr(t_print_data *pd, char *s);
int						printnum(t_print_data *pd, unsigned long value);
int						ft_printf(const char *fmt, ...);

#endif
