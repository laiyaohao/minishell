NAME := minishell
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
SRC_FOLDER := src
LIBFT_FOLDER := libft
LIBFT := ${LIBFT_FOLDER}/libft.a
# MAIN_FILE := ${SRC_FOLDER}/main.c

SIGS_FOLDER := ${addprefix ${SRC_FOLDER}, /signals/}
SIGS_FILENAMES := signals.c
SIGS_FILES := ${addprefix ${SIGS_FOLDER}, ${SIGS_FILENAMES}}

UTILS_FOLDER := ${addprefix ${SRC_FOLDER}, /utils/}
UTILS_FILENAMES := check_arg.c
UTILS_FILES := ${addprefix ${UTILS_FOLDER}, ${UTILS_FILENAMES}}

INIT_FOLDER := ${addprefix ${SRC_FOLDER}, /init/}
INIT_FILENAMES := init.c
INIT_FILES := ${addprefix ${INIT_FOLDER}, ${INIT_FILENAMES}}

TOKENS_FOLDER := ${addprefix ${SRC_FOLDER}, /tokens/}
TOKENS_FILENAMES := check_line.c
TOKENS_FILES := ${addprefix ${TOKENS_FOLDER}, ${TOKENS_FILENAMES}}

MAIN_FOLDER := ${addprefix ${SRC_FOLDER}, /main/}
MAIN_FILENAMES := loop.c main.c
MAIN_FILES := ${addprefix ${MAIN_FOLDER}, ${MAIN_FILENAMES}}

SRC_FILES := ${SIGS_FILES} ${UTILS_FILES} ${MAIN_FILES} ${INIT_FILES} ${TOKENS_FILES}

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
