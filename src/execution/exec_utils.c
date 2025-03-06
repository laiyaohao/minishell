#include "../../inc/minishell.h"

void    handle_redir(t_redirect *rd, int fd)
{
    if (!rd || rd->type == T_REDIR_IN || rd->type == T_HEREDOC)
    {
        if (dup2(fd, STDIN_FILENO) == -1)
        {
            ft_putstr_fd("Error: Failed to dup2\n", 2);
            close(fd);
			return ;
        }
    }
    else if (rd->type == T_REDIR_OUT || rd->type == T_REDIR_APP)
    {
        if (dup2(fd, STDOUT_FILENO) == -1)
        {
            ft_putstr_fd("Error: Failed to dup2\n", 2);
            close(fd);
			return ;
        }
    }
    close(fd);
}

void	extract_paths(t_exec *exec, t_list *env_ll)
{
	t_list  *env;
	t_env	*env_var;

	exec->paths = NULL;
    env = env_ll;
	while (env)
	{
		env_var = (t_env *)env->content;
		if (env_var && env_var->key && ft_strncmp(env_var->key, "PATH", 5) == 0)
		{
			if (env_var->value)
				exec->paths = ft_split_app(env_var->value, ':');
			break;
		}
		env = env->next;
	}
}

void	check_path(t_exec *exec, ast_node *node)
{
    int i;

    i = 0;
	if (exec->paths)
	{
		while (exec->paths[i])
		{
			exec->cmd = ft_strjoin(exec->paths[i], node->args[0]);
			if (!exec->cmd)
			{
				ft_putstr_fd("Error: Path creation issue\n", 2);
				return ;
			}
			if (access(exec->cmd, F_OK) == 0)
				break ;
			free(exec->cmd);
			exec->cmd = NULL;
			i++;
		}
	}
	if (!exec->cmd)
		exec->cmd = ft_strdup(node->args[0]);
}
