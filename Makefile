NAME := minishell
CC := cc
CFLAGS := -Wall -Werror -Wextra -g
SRC_FOLDER := src
LIBFT_FOLDER := libft
LIBFT := ${LIBFT_FOLDER}/libft.a
# MAIN_FILE := ${SRC_FOLDER}/main.c

EXEC_FOLDER := ${addprefix ${SRC_FOLDER}, /execution/}
EXEC_FILENAMES := exec_cmd.c exec_pipe.c exec_rd.c
EXEC_FILES := ${addprefix ${EXEC_FOLDER}, ${EXEC_FILENAMES}}

ERROR_FOLDER := ${addprefix ${SRC_FOLDER}, /error/}
ERROR_FILENAMES := error_handle.c
ERROR_FILES := ${addprefix ${ERROR_FOLDER}, ${ERROR_FILENAMES}}

PARSE_FOLDER := ${addprefix ${SRC_FOLDER}, /parsing/}
PARSE_FILENAMES := cmd_expand.c parse.c parse_utils.c print_ast.c \
									rd_expand.c heredoc.c
PARSE_FILES := ${addprefix ${PARSE_FOLDER}, ${PARSE_FILENAMES}}

LEX_FOLDER := ${addprefix ${SRC_FOLDER}, /lexing/}
LEX_FILENAMES := lex.c lex_utils.c
LEX_FILES := ${addprefix ${LEX_FOLDER}, ${LEX_FILENAMES}}

SIGS_FOLDER := ${addprefix ${SRC_FOLDER}, /signals/}
SIGS_FILENAMES := signals.c
SIGS_FILES := ${addprefix ${SIGS_FOLDER}, ${SIGS_FILENAMES}}

UTILS_FOLDER := ${addprefix ${SRC_FOLDER}, /utils/}
UTILS_FILENAMES := check_arg.c ft_isspace.c ft_strndup.c split_args.c \
									strcjoin.c ft_split_app.c ft_strdup_app.c gnl.c
UTILS_FILES := ${addprefix ${UTILS_FOLDER}, ${UTILS_FILENAMES}}

INIT_FOLDER := ${addprefix ${SRC_FOLDER}, /init/}
INIT_FILENAMES := init.c init_shell.c
INIT_FILES := ${addprefix ${INIT_FOLDER}, ${INIT_FILENAMES}}

TOKENS_FOLDER := ${addprefix ${SRC_FOLDER}, /tokens/}
TOKENS_FILENAMES := check_line.c
TOKENS_FILES := ${addprefix ${TOKENS_FOLDER}, ${TOKENS_FILENAMES}}

ENV_FOLDER := ${addprefix ${SRC_FOLDER}, /env/}
ENV_FILENAMES := setup_env.c free_env.c print_env.c add_env.c \
									check_env.c del_env.c find_env.c update_env.c
ENV_FILES := ${addprefix ${ENV_FOLDER}, ${ENV_FILENAMES}}

BUILTINS_FOLDER := ${addprefix ${SRC_FOLDER}, /builtins/}
BUILTINS_FILENAMES := bi_pwd.c bi_env.c bi_export.c bi_cd.c bi_echo.c \
											bi_unset.c
BUILTINS_FILES := ${addprefix ${BUILTINS_FOLDER}, ${BUILTINS_FILENAMES}}

MAIN_FOLDER := ${addprefix ${SRC_FOLDER}, /main/}
MAIN_FILENAMES := loop.c main.c
MAIN_FILES := ${addprefix ${MAIN_FOLDER}, ${MAIN_FILENAMES}}

SRC_FILES := ${PARSE_FILES} ${LEX_FILES} ${SIGS_FILES} ${UTILS_FILES} ${MAIN_FILES} \
						${INIT_FILES} ${TOKENS_FILES} ${ENV_FILES} \
						${BUILTINS_FILES} ${ERROR_FILES} ${EXEC_FILES}

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
