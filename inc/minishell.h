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

typedef struct s_cmd
{
	char	*cmd;
	int		infd;

}					t_cmd;

typedef struct s_attr
{
	int	con_flag;
	char	*full_line;
}					t_attr;

void	setup_sig(void);
int	check_arg(int argc);
void  shell_loop(t_attr *attr);
void	init_attr(t_attr *attr);
void	line_con(t_attr *attr, char **full_line, char **input);
int	backslash(char *input);
void	strip(char **line);
int  check_line(t_attr *attr);

#endif