#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

typedef struct s_env
{
	char	*key;
	char	*value;
}					t_env;

typedef struct s_attr
{
	int	con_flag;
	char	*full_line;
	char	*working_dir;
	char	*old_working_dir;
}					t_attr;

void	setup_sig(void);
int	check_arg(int argc);
void  shell_loop(t_attr *attr);
void	init_attr(t_attr *attr, t_list **env_ll);
int  check_line(t_attr *attr);
int set_status(int status, char *line, int i);
void  setup_env(t_list **env_ll, char **env);
void  add_env(char **env, int i, t_list **env_ll);
int	check_key(int key_len, char *env);
int	check_value(int key_len, char *env);
char  *find_value(t_list **env_ll, char *key);
t_env	*find_node(t_list **env_ll, char *key);
void  free_env(t_list **env_ll);
void  free_node(t_env *node);
void  del_env(char **env, int i, t_list **env_ll);
void	print_env(t_list **env_ll, int expo);
void  update_value(t_list **env_ll, char *key, char *new_v);
void	bi_env(t_list **env_ll);

#endif