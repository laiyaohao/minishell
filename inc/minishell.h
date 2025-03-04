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
	T_EOF
}						t_type;

typedef enum
{
	AST_PIPE,
	AST_CMD
}						ast_type;

typedef struct s_redirect
{
	t_type				type;
	char				*file;
	struct s_redirect	*next;
}						t_redirect;

typedef struct ast_node
{
	ast_type			type;
	char				**args;
	t_redirect			*rd;
	struct ast_node		*left;
	struct ast_node		*right;
}						ast_node;

typedef struct s_node
{
	t_type				type;
	char				*value;
	struct s_node		*next;
}						t_node;

typedef struct s_tok
{
	t_node				*head;
	int					count;
}						t_tok;

typedef struct s_env
{
	char				*key;
	char				*value;
}						t_env;

typedef struct s_attr
{
	int					con_flag;
	char				*full_line;
	char				*working_dir;
	char				*old_working_dir;
}						t_attr;

typedef struct s_shell
{
	t_tok				*list;
	ast_node			*tree;
	t_env				*env;
	t_attr				*attr;
}						t_shell;

void					setup_sig(void);
int						check_arg(int argc);
void					shell_loop(t_attr *attr);
void					init_attr(t_attr *attr, t_list **env_ll);
int						check_line(t_attr *attr);
int						set_status(int status, char *line, int i);
void					setup_env(t_list **env_ll, char **env);
void					add_env(char **env, int i, t_list **env_ll);
int						check_key(int key_len, char *env);
int						check_value(int key_len, char *env);
char					*find_value(t_list **env_ll, char *key);
t_env					*find_node(t_list **env_ll, char *key);
void					free_env(t_list **env_ll);
void					free_node(t_env *node);
void					del_env(char **env, int i, t_list **env_ll);
void					print_env(t_list **env_ll, int expo);
void					update_value(t_list **env_ll, char *key, char *new_v);
void					bi_env(t_list **env_ll);
int						ft_isspace(int c);
void					handle_pipe(char **s, int *i);
void					handle_word(char **s, int *i, char **temp);
void					handle_redir_in(char **s, int *i);
void					handle_redir_out(char **s, int *i);
t_tok					*lexer(char *input);
int						grammar_check(t_tok *list);
void					parse_word(char **buffer, char *s);
t_redirect				*create_rd(void);
ast_node				*create_ast_node(ast_type type);
ast_node				*parser(t_tok *list);
void					handle_var(char **s, char **res);
char					*get_var(char **s);
char					*handle_expand(char *s);
char					*rd_expand(char *s, int mode);
char					*ft_strndup(char *s, int len);
char					**split_args(char *s);
void					process_args(char ***array);
void					strcjoin(char s, char **res);
void					debug_print_ast(ast_node *root);
void					free_2d(char **memory);
void					free_tlist(t_tok *tokens);
void					free_tree(ast_node *tree);

#endif