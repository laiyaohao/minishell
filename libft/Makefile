# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 19:24:17 by ylai              #+#    #+#              #
#    Updated: 2024/06/02 22:14:26 by ylai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := cc
CFLAGS := -Wall -Werror -Wextra
SRCS := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_islower.c ft_isupper.c ft_abs.c ft_isnegative.c ft_ispositive.c
OBJS := ${SRCS:.c=.o}
BONUS := ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJS := ${BONUS:.c=.o}

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

${NAME}: ${OBJS}
	ar rcs $@ $^

all: ${NAME}

bonus: ${BONUS_OBJS}
	ar rcs ${NAME} ${BONUS_OBJS}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}
fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re