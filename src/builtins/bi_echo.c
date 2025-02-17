#include "../../inc/minishell.h"

int	is_n_flag(char *arg)
{
	int		i;
	int	n_flag;

	n_flag = 0;
	i = 0;
	if (arg[i] != '-')
		return (n_flag);
	i++;
	while (arg[i] && arg[i] == 'n')
		i++;
	if (arg[i] == '\0')
		n_flag = 1;
	return (n_flag);
}

/* print_args:
*	Prints the given array of aruments to STDOUT.
*/
void	print_args(char **args, int n_flag, int i)
{
	if (!args[i])
	{
		if (!n_flag)
			ft_putchar_fd('\n', STDOUT_FILENO);
		return ;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		else if (!args[i + 1] && !n_flag)
			ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
}

/* bi_echo:
*	Executes the echo builtin command: prints the given strings
*	and adds a \n character or not depending on the -n option.
*	Returns 1 on completion.
*/
int	bi_echo(char **args)
{
	int		i;
	int	n_flag;

	n_flag = 0;
	i = 1;
	while (args[i] && is_n_flag(args[i]))
	{
		n_flag = 1;
		i++;
	}
	print_args(args, n_flag, i);
	return (EXIT_SUCCESS);
}
