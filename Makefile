#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 21:20:23 by pschneid          #+#    #+#              #
#    Updated: 2024/04/24 17:57:29 by pschneid         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
SRC_DIR = src
INCLUDE_DIR	= include
OBJ_DIR = obj
TEST_DIR = tests

CC = cc
OFLAG ?= -O0
CFLAGS = $(OFLAG) -I$(INCLUDE_DIR) -Wall -Wextra -Werror -g
NAME = libft.a
AR = ar rcs

CFILENAMES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c #ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c 

BONUS_CFILENAMES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 

CFILES = $(addprefix $(SRC_DIR)/,$(CFILENAMES))
OBJECTS = ${CFILES:.c=.o}

BONUS_CFILES = $(addprefix $(SRC_DIR)/,$(BONUS_CFILENAMES))
BONUS_OBJECTS = ${BONUS_CFILES:.c=.o}

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

test: all
	@echo "Testing"
	@$(MAKE) -C $(TEST_DIR) run

clean:
	-rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean:	clean
	-rm -rf $(NAME)

re:	fclean all

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	$(AR) $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

.PHONY: all clean fclean re bonus
