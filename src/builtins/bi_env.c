#include "../../inc/minishell.h"

/**
 * if env variables is empty, no need to print here
 */
void	bi_env(t_list **env_ll)
{
	print_env(env_ll);
}
