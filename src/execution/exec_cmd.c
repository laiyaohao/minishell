/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:05:35 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/10 20:05:36 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	extract_paths(t_exec *exec, t_list *env_ll)
{
	t_list	*env;
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
			break ;
		}
		env = env->next;
	}
}

void	check_path(t_exec *exec, ast_node *node)
{
	int	i;

	i = 0;
	if (exec->paths)
	{
		while (exec->paths[i])
		{
			if (node->args[0][0] != '.')
				exec->cmd = ft_strjoin(exec->paths[i], node->args[0]);
			else
				exec->cmd = ft_strdup(node->args[0]);
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

void	exec_err(ast_node *node, t_shell *shell)
{
	if (errno == EACCES)
	{
		ft_putstr_fd("Error: Permission denied: ", 2);
		ft_putstr_fd(node->args[0], 2);
		ft_putstr_fd("\n", 2);
		shell->exit = 126;
		exit(shell->exit);
	}
	else if (errno == ENOENT)
	{
		ft_putstr_fd("Error: Command not found: ", 2);
		ft_putstr_fd(node->args[0], 2);
		ft_putstr_fd("\n", 2);
		shell->exit = 127;
		exit(shell->exit);
	}
	else
		ft_putstr_fd("Error: execve failed\n", 2);
	shell->exit = 1;
	exit(shell->exit);
}

void	exec_ve(ast_node *node, t_shell *shell)
{
	int		pid;
	t_exec	exec;

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
			execve(exec.cmd, node->args, shell->env);
			exec_err(node, shell);
		}
		else
			exit(0);
	}
	else
	{
		waitpid(pid, &shell->exit, 0);
		if (WIFEXITED(shell->exit))
			shell->exit = WEXITSTATUS(shell->exit);
	}
}

void	exec_cmd(ast_node *node, t_shell *shell)
{
	exec_ve(node, shell);
}

	// if (ft_strncmp(node->args[0], "echo", ft_strlen(node->args[0])))
	// 	shell->exit = bi_echo(node->args);
	// else if (ft_strncmp(node->args[0], "cd", ft_strlen(node->args[0])))
	// 	bi_cd(shell->env_ll, shell->attr, node->args);
	// else if (ft_strncmp(node->args[0], "pwd", ft_strlen(node->args[0])))
	// 	bi_pwd();
	// else if (ft_strncmp(node->args[0], "export", ft_strlen(node->args[0])))
	// 	bi_export();
	// else if (ft_strncmp(node->args[0], "pwd", ft_strlen(node->args[0])))
	// 	bi_unset();
	// else if (ft_strncmp(node->args[0], "env", ft_strlen(node->args[0])))
	// 	bi_env();
	// else if (ft_strncmp(node->args[0], "exit", ft_strlen(node->args[0])))
	// 	bi_exit();
	// else