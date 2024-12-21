NAME := minishell
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
SRC_FOLDER := src
LIBFT_FOLDER := libft
LIBFT := ${LIBFT_FOLDER}/libft.a
MAIN_FILE := ${SRC_FOLDER}/main.c

SIGS_FOLDER := ${addprefix ${SRC_FOLDER}, /signals/}
SIGS_FILENAMES := signals.c
SIGS_FILES := ${addprefix ${SIGS_FOLDER}, ${SIGS_FILENAMES}}

UTILS_FOLDER := ${addprefix ${SRC_FOLDER}, /utils/}
UTILS_FILENAMES := check_arg.c
UTILS_FILES := ${addprefix ${UTILS_FOLDER}, ${UTILS_FILENAMES}}

# HISTORY_FOLDER := ${addprefix ${SRC_FOLDER}, /history/}
# HISTORY_FILENAMES := history.c

SRC_FILES := ${MAIN_FILE} ${SIGS_FILES} ${UTILS_FILES}

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