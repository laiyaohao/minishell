NAME := minishell
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
SRC_FOLDER := src
LIBFT_FOLDER := libft
LIBFT := ${LIBFT_FOLDER}/libft.a
MAIN_FILE := ${SRC_FOLDER}/main.c

# UTILS_FOLDER := ${addprefix ${SRC_FOLDER}, utils/}
# UTILS_FILENAMES := 
# UTILS_FILES := ${addprefix ${UTILS_FOLDER}, ${UTILS_FILENAMES}}

SRC_FILES := ${MAIN_FILE} 
# UTILS_FILES

OBJS := ${SRC_FILES:.c=.o}

all: ${LIBFT} ${NAME}

clean:
	@make -C ${LIBFT_FOLDER} clean
	rm -f ${OBJS}

fclean: clean
	@make -C ${LIBFT_FOLDER} fclean
	rm -f ${NAME}

re: fclean all


${LIBFT}:
	@make -C ${LIBFT_FOLDER} all
	@make -C ${LIBFT_FOLDER} bonus

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -lreadline -o $@

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

.PHONY: all clean fclean re