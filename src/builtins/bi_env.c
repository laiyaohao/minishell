#include "../../inc/minishell.h"

/**
 * bi_env - prints out the environment variables
 * @env_ll: linked list that contains key-value pairs of env variables
 *
 * Return: void
 */
void	bi_env(t_list **env_ll)
{
	print_env(env_ll, 0);
}
