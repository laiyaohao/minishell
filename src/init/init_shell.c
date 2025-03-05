#include "../../inc/minishell.h"

void    init_shell(t_shell *shell, char **env)
{
    shell->env_ll = NULL;
    shell->attr = malloc(sizeof(t_attr));
    if (!shell->attr)
        ft_putstr_fd("Error: Failed to malloc for attr\n", 2);
    shell->tokens = NULL;
    shell->tree = NULL;
    shell->env = env;
    shell->exit = 0;
}
