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

typedef enum
{
	T_PIPE,
	T_REDIR_OUT,
	T_REDIR_APP,
	T_REDIR_IN,
	T_HEREDOC,
	T_WORD,
	T_VAR,
	T_EOF
}					t_type;

typedef enum
{
	AST_PIPE,
	AST_CMD
}					ast_type;

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

typedef struct s_redirect
{
	
}					t_redirect;


typedef struct ast_node
{
	ast_type		type;
	char			*cmd; //tbc if required
	char			**args;
	t_redirect		*rd;
	struct ast_node	*left;
	struct ast_node	*right;
}					ast_node;

typedef struct s_attr
{
	int				con_flag;
	char			*full_line;
}					t_attr;

typedef struct s_node
{
	t_type			type;
	char			*value;
	struct s_node	*next;
}					t_node;

typedef struct s_tok
{
	t_node			*head;
	int				count;
}					t_tok;

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
ast					*parser(t_tok *list);

#endif