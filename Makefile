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
UTILS_FILENAMES := check_arg.c line_con.c strip.c
UTILS_FILES := ${addprefix ${UTILS_FOLDER}, ${UTILS_FILENAMES}}

MAIN_FOLDER := ${addprefix ${SRC_FOLDER}, /main/}
MAIN_FILENAMES := loop.c main.c
MAIN_FILES := ${addprefix ${MAIN_FOLDER}, ${MAIN_FILENAMES}}

SRC_FILES := ${SIGS_FILES} ${UTILS_FILES} ${MAIN_FILES}

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


# t_list struct (named cmds)

# --------------------------------
# |             |               |
# |             |               |
# | cmd struct  |  t_list *next |
# |             |               |
# |             |               |
# --------------------------------

# above is the structure for the whole entire line of commands
# cmd struct is the one chunk before a specific pipes
# e.g if command is "ls -l | cat", then cmd struct will contain "ls -l"
# length of this linked list will depends on the number of pipes.
# next will contain the address to the next t_list struct
# for example, using the above example (ls -l | cat)
# next will point to the address of the t_list struct for "cat"



# cmd struct

# --------------------------------
# |             |               |
# |             |               |
# | char cmd    |   
# |             |               |
# |             |               |
# --------------------------------