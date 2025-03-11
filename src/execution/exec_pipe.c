/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:05:59 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/11 16:10:03 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_child(int mode, int pipe_fd[2], ast_node *node, t_shell *shell)
{
	if (mode == 1)
	{
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		{
			ft_putstr_fd("Error: Failed to dup2 left\n", 2);
			(close(pipe_fd[1]), exit(1));
		}
		close(pipe_fd[1]);
		exec_ast(node->left, shell);
		exit(0);
	}
	else
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		{
			ft_putstr_fd("Error: Failed to dup2 right\n", 2);
			(close(pipe_fd[0]), exit(1));
		}
		close(pipe_fd[0]);
		exec_ast(node->right, shell);
		exit(0);
	}
}

void	exec_pipe(ast_node *node, t_shell *shell)
{
	int	pipe_fd[2];
	int	pid_l;
	int	pid_r;

	if (pipe(pipe_fd) == -1)
		ft_putstr_fd("Error: Failed to pipe\n", 2);
	pid_l = fork();
	if (pid_l < 0)
		ft_putstr_fd("Error: Failed to fork left\n", 2);
	else if (pid_l == 0)
		handle_child(1, pipe_fd, node, shell);
	pid_r = fork();
	if (pid_r < 0)
		ft_putstr_fd("Error: Failed to fork right\n", 2);
	else if (pid_r == 0)
		handle_child(2, pipe_fd, node, shell);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid_l, NULL, 0);
	waitpid(pid_r, &shell->exit, 0);
}

void	exec_ast(ast_node *node, t_shell *shell)
{
	if (!node)
		return ;
	if (node->type == AST_CMD)
		exec_cmd(node, shell);
	else if (node->type == AST_PIPE)
		exec_pipe(node, shell);
}
