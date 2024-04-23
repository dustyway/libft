#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 21:20:23 by pschneid          #+#    #+#              #
#    Updated: 2024/04/23 15:20:12 by pschneid         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
CFILES_DIR = srcs
HEADERS	= .

CFILENAMES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c #ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c 

#$(addprefix prefix,names…)
CFILES = $(foreach C,$(CFILENAMES),$(CFILES_DIR)/$(C))
OBJECTS = ${CFILES:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HEADERS)
NAME = libft.a
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-rm -f $(OBJECTS)

fclean:	clean
	-rm -rf $(NAME)

re:		fclean all

bonus:

.PHONY: all clean fclean re
