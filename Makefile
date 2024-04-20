#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 21:20:23 by pschneid          #+#    #+#              #
#    Updated: 2024/04/19 19:42:48 by pschneid         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
CFILES_DIR = srcs
HEADERS	= .

CFILENAMES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c
CFILES = $(foreach C,$(CFILENAMES),$(CFILES_DIR)/$(C))
OBJECTS = ${CFILES:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
AR = ar rcs

all:		$(NAME)

$(NAME):	$(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

clean:
	-rm -f $(OBJECTS)

fclean:	clean
	-rm -rf $(NAME)

re:		fclean all

bonus:
