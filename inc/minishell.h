#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

extern volatile sig_atomic_t g_sigint;

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
	int					fd;
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

typedef struct s_exec
{
	char	**paths;
	char	*cmd;
}						t_exec;

typedef struct s_shell
{
	t_list				*env_ll;
	t_attr				*attr;
	t_tok				*tokens;
	ast_node			*tree;
	char				**env;
	int					exit;
	int					std_in;
	int					std_out;
}						t_shell;

// Main
void    				init_shell(t_shell *shell, char **env);
void					shell_loop(t_shell *shell);
void					init_attr(t_attr *attr, t_list **env_ll);
int						check_arg(int argc);

// Signals
void					setup_sig_interactive(void);
void					setup_sig_exec(void);
void					setup_sig_heredoc(void);
void					sigint_handler(int sig);
void					sigint_heredoc(int sig);
int    					heredoc_rl_event(void);

// Env
void					setup_env(t_list **env_ll, char **env);
void					add_env(char **env, int i, t_list **env_ll);
void					update_value(t_list **env_ll, char *key, char *new_v);
void					add_env_direct(t_list **env_ll, char *k, char *v);
int						check_key(int key_len, char *env);
int						check_value(int key_len, char *env);
char					*find_value(t_list **env_ll, char *key);
t_env					*find_node(t_list **env_ll, char *key);
void					fill_value(t_env *key_v, int val_len, char *env);
void					fill_key(t_env *key_v, int key_len, char *env);
void					add_empty_key_help(char **env, int i, t_list **env_ll);
void					add_empty_key(t_list **env_ll, char **env, char *key, int i);


// Input Validation
int						check_line(t_attr *attr);
int						set_status(int status, char *line, int i);


// Lexing
void					handle_pipe(char **s, int *i);
void					handle_word(char **s, int *i, char **temp);
void					handle_redir_in(char **s, int *i);
void					handle_redir_out(char **s, int *i);
int						grammar_check(t_tok *list);
t_tok					*lexer(char *input);


// Parsing
void					parse_word(char **buffer, char *s, t_shell *shell);
void					handle_var(char **s, char **res, t_shell *shell);
void					debug_print_ast(ast_node *root);
int    					check_quote(char *s);
char					*cmd_expand(char *s, t_shell *shell);
char					*rd_expand(char *s, int mode, t_shell *shell);
char					*get_env(t_list *env_ll, char *key);
ast_node				*create_ast_node(ast_type type);
ast_node				*parser(t_tok *list, t_shell *shell);
t_redirect				*create_rd(void);

// Heredoc
int    					create_heredoc(char *delim, t_shell *shell, int mode);
int						check_quote(char *s);
char					*heredoc_expand(char *s, t_shell *shell);
void					rl_null(char *delim);

// Execution
void					extract_paths(t_exec *exec, t_list *env_ll);
void					check_path(t_exec *exec, ast_node *node);
void    				exec_ast(ast_node *node, t_shell *shell);
void					exec_cmd(ast_node *node, t_shell *shell);
void					exec_err(ast_node *node, t_shell *shell);
int						exec_rd(t_redirect *rd, t_shell *shell);
char    				**env_arr(t_list *env_ll);

// Builtins
int						bi_echo(char **args);
void					bi_cd(t_list **env_ll, t_attr *attr, char **args);
void  					bi_pwd(void);
void  					bi_export(t_list **env_ll, char **args);
void  					bi_unset(t_list **env_ll, char **args);
void					bi_env(t_list **env_ll);
void  					bi_exit(t_shell *sh_atr, char **args);
void    				bi_dot(ast_node *node);
void					print_env(t_list **env_ll, int expo);

// Memory
void					free_env(t_list **env_ll);
void					free_node(t_env *node);
void					del_env(char **env, int i, t_list **env_ll);
void					free_2d(char **memory);
void					free_tlist(t_tok *tokens);
void					free_tree(ast_node *tree);
void    				free_shell(t_shell *shell);
void					free_every(t_shell *sh_atr);
void					free_rd(t_redirect *rd);
void					close_rd(ast_node *tree);

// Utils
void					process_args(char ***array);
void					strcjoin(char s, char **res);
char					*gnl(int fd);
char					*ft_strndup(char *s, int len);
char					**split_args(char *s);
char					*ft_strdup_app(const char *s, size_t len, char c);
char					**ft_split_app(char const *s, char c);
int						ft_atoll(const char *str, long long *result);
int						is_flag(char *arg, char c);
int						more_args(char **args, int cd);
int						ft_isspace(int c);

#endif