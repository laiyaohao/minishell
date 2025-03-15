/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:54:43 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/15 15:09:21 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_ddot(t_ast *node, t_shell *shell)
{
	char	*path;

	path = get_env(shell->env_ll, "PATH");
	if (path)
	{
		ft_putstr_fd("Error: Command not found: ", 2);
		ft_putstr_fd(node->args[0], 2);
		ft_putstr_fd("\n", 2);
		shell->exit = 127;
	}
	else
	{
		ft_putstr_fd("Error: Is a directory: ", 2);
		ft_putstr_fd(node->args[0], 2);
		ft_putstr_fd("\n", 2);
		shell->exit = 126;
	}
}

void	handle_acc(t_ast *node)
{
	struct stat	file_stat;

	if (stat(node->args[0], &file_stat) == 0 && S_ISDIR(file_stat.st_mode))
	{
		ft_putstr_fd("Error: Is a directory: ", 2);
		ft_putstr_fd(node->args[0], 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd("Error: Permission denied: ", 2);
		ft_putstr_fd(node->args[0], 2);
		ft_putstr_fd("\n", 2);
	}
}

void	no_ent_err(t_ast *node, char *path)
{
	if (!path)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(node->args[0], 2);
		ft_putstr_fd(": No such file or directory", 2);
	}
	else
	{
		ft_putstr_fd("Error: Command not found: ", 2);
		ft_putstr_fd(node->args[0], 2);
	}
	ft_putstr_fd("\n", 2);
}

void	handle_no_ent(t_ast *node, t_shell *shell)
{
	struct stat	file_stat;
	char		*path;

	path = get_env(shell->env_ll, "PATH");
	if (ft_strncmp(node->args[0], "./", 2) == 0)
	{
		if (stat(node->args[0], &file_stat) != 0)
		{
			ft_putstr_fd("Error: ", 2);
			ft_putstr_fd(node->args[0], 2);
			ft_putstr_fd(": No such file or directory", 2);
			ft_putstr_fd("\n", 2);
		}
	}
	else
		no_ent_err(node, path);
}

void	exec_err(t_ast *node, t_shell *shell)
{
	if (ft_strncmp(node->args[0], "..", 3) == 0)
		handle_ddot(node, shell);
	else if (errno == ENOENT)
	{
		handle_no_ent(node, shell);
		shell->exit = 127;
	}
	else if (errno == EACCES)
	{
		handle_acc(node);
		shell->exit = 126;
	}
	else
	{
		ft_putstr_fd("Error: execve failed\n", 2);
		shell->exit = 1;
	}
	close(shell->std_in);
	close(shell->std_out);
	exit(shell->exit);
}
