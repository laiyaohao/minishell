#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum
{
	T_PIPE = 1,
	T_REDIR_OUT = 2,
	T_REDIR_APP = 3,
	T_REDIR_IN = 4,
	T_HEREDOC = 5,
	T_WORD = 6,
	T_VAR = 7,
	T_EOF = 8
};

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

typedef struct s_cmd
{
	char			**args;
	int				in_fd;
	int				out_fd;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_attr
{
	int				con_flag;
	char			*full_line;
}					t_attr;

typedef struct s_node
{
	int				type;
	char			*value;
	struct s_node	*next;
}					t_node;

typedef struct s_tok
{
	t_node			*head;
	int				count;
}					t_tok;

typedef struct s_ast
{
	t_node			*head;
	t_node			*left;
	t_node			*right;
}					t_ast;

void				setup_sig(void);
int					check_arg(int argc);
void				shell_loop(t_attr *attr);
void				init_attr(t_attr *attr);
int					check_line(t_attr *attr);
int					ft_isspace(int c);
t_tok				*lexer(char *input);
void				handle_pipe(char **s, int *i);
void				handle_word(char **s, int *i, char **temp);
void				handle_redir_in(char **s, int *i);
void				handle_redir_out(char **s, int *i);
t_cmd				*parser(t_tok *list);

#endif