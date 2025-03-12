/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:05:35 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/11 18:05:46 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	child_ve(ast_node *node, t_shell *shell, t_exec *exec)
{
	char	**env;

	extract_paths(exec, shell->env_ll);
	check_path(exec, node);
	env = env_arr(shell->env_ll);
	execve(exec->cmd, node->args, env);
	free_2d(env);
	exec_err(node, shell);
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
		reset_child_sig();
		if (node->args && node->args[0])
			child_ve(node, shell, &exec);
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

void	what_exec(ast_node *node, t_shell *shell)
{
	if (ft_strncmp(node->args[0], "echo", 5) == 0)
		shell->exit = bi_echo(node->args);
	else if (ft_strncmp(node->args[0], "cd", 3) == 0)
		bi_cd(&shell->env_ll, shell->attr, node->args);
	else if (ft_strncmp(node->args[0], "pwd", 4) == 0)
		bi_pwd();
	else if (ft_strncmp(node->args[0], "export", 7) == 0)
		bi_export(&shell->env_ll, node->args);
	else if (ft_strncmp(node->args[0], "unset", 6) == 0)
		bi_unset(&shell->env_ll, node->args);
	else if (ft_strncmp(node->args[0], "env", 4) == 0)
		bi_env(&shell->env_ll);
	else if (ft_strncmp(node->args[0], "exit", 5) == 0)
		bi_exit(shell, node->args);
	else
		exec_ve(node, shell);
}

void	exec_cmd(ast_node *node, t_shell *shell)
{
	int	saved_stdout;
	int	saved_stdin;

	saved_stdout = dup(STDOUT_FILENO);
	saved_stdin = dup(STDIN_FILENO);
	if (saved_stdout < 0 || saved_stdin < 0)
	{
		ft_putstr_fd("Error: Failed to save stdout or stdin\n", 2);
		exit(-1);
	}
	exec_rd(node->rd);
	what_exec(node, shell);
	if (dup2(saved_stdout, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd("Error: Failed to restore stdout\n", 2);
		exit(-1);
	}
	if (dup2(saved_stdin, STDIN_FILENO) < 0)
	{
		ft_putstr_fd("Error: Failed to restore stdin\n", 2);
		exit(-1);
	}
	close(saved_stdout);
	close(saved_stdin);
}
