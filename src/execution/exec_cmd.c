#include "../../inc/minishell.h"

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

void    exec_cmd(ast_node *node, t_shell *shell)
{
    int     pid;
    t_exec  exec;
    
    pid = fork();
    if (pid == -1)
        ft_putstr_fd("Error: Failed to fork\n", 2);
    else if (pid == 0)
    {
        (reset_signals_in_child(), exec_rd(node->rd));
        if (node->args && node->args[0])
        {
            extract_paths(&exec, shell->env_ll);
            check_path(&exec, node);
            shell->exit = execve(exec.cmd, node->args, shell->env);
            if (shell->exit == -1)
            {
                ft_putstr_fd("Error: Execve failed\n", 2);
                exit(WEXITSTATUS(shell->exit));
            }
        }
        else
            exit(0);
    }
    else
        waitpid(pid, &shell->exit, 0);
}
