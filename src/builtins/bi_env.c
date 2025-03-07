#include "../../inc/minishell.h"

/**
 * bi_env - prints out the environment variables
 * need handle -i
 * @env_ll: linked list that contains key-value pairs of env variables
 *
 * Return: void
 */
void	bi_env(t_list **env_ll, char **args)
{
	int	i;
	int	i_flag;

	i = 1;
	i_flag = 0;
	while (args[i] && is_flag(args[i], 'i'))
	{
		i_flag = 1;
		i++;
	}
	if (!i_flag)
		print_env(env_ll, 0);
	else
		return ; // need to double check this, rmb there are lke 4 things to print
}
