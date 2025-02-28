#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschneid <pschneid@student.42berl...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 21:20:23 by pschneid          #+#    #+#              #
#    Updated: 2025/02/26 18:33:21 by pschneid         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
SRC_LIBFT = libft_core
SRC_LIBFT_ADD = libft_addendum
SRC_FTPRINTF = ft_printf
SRC_GETNEXTLINE = get_next_line
SRC_HASHTABLE = hashtable
SRC_QUEUE = queue
SRC_STACK = stack
INCLUDE_DIR	= include
BUILD_DIR = build

CC = cc
CFLAGS = -I$(INCLUDE_DIR) -g -Wall -Wextra -Werror
NAME = libft.a
AR = ar rcs

LIBFT_CFILENAMES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 
LIBFT_ADD_CFILENAMES = absf.c atohex.c count_words.c error_exit.c lst_nth.c \
	safe_malloc.c safe_malloc2.c safe_write.c sign.c lst_del_node.c maxf.c strip_nl.c

FTPRINTF_CFILENAMES = ft_printf.c parse_conversion.c print_char_str.c print_num.c

GNL_CFILENAMES = get_next_line.c

HT_CFILENAMES = hash_table_init.c hash_table_insert.c hash_table_free.c \
		hash_table_has_key.c string_hash.c

QU_CFILENAMES = clear_queue.c dequeue.c enqueue.c init_queue.c is_empty.c \
		queue_peek.c queue_peek_n.c

ST_CFILENAMES = init_stack.c push_stack.c peek_stack.c pop_stack.c stack_size.c \
		clear_stack.c

CFILES = $(addprefix $(SRC_LIBFT)/,$(LIBFT_CFILENAMES))\
		$(addprefix $(SRC_LIBFT_ADD)/,$(LIBFT_ADD_CFILENAMES))\
		$(addprefix $(SRC_FTPRINTF)/,$(FTPRINTF_CFILENAMES))\
		$(addprefix $(SRC_GETNEXTLINE)/,$(GNL_CFILENAMES))\
		$(addprefix $(SRC_HASHTABLE)/,$(HT_CFILENAMES))\
		$(addprefix $(SRC_QUEUE)/,$(QU_CFILENAMES))\
		$(addprefix $(SRC_STACK)/,$(ST_CFILENAMES))\

OBJECTS = $(addprefix $(BUILD_DIR)/,${CFILES:.c=.o})

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

$(BUILD_DIR)/%.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean:	clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
