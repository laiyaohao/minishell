#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../libft/libft.h"

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

void	setup_sig(void);
int	check_arg(int argc);
void  shell_loop(void);
int	line_con(char *input);
void	strip(char **line);

#endif