/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:54:43 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/12 17:31:03 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_acc(ast_node *node)
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

void	handle_no_ent(ast_node *node)
{
	struct stat	file_stat;

	if (ft_strncmp(node->args[0], "./", 2) == 0)
	{
		if (stat(node->args[0], &file_stat) != 0)
		{
			ft_putstr_fd("Error: No such file or directory: ", 2);
			ft_putstr_fd(node->args[0], 2);
			ft_putstr_fd("\n", 2);
		}
	}
	else
	{
		ft_putstr_fd("Error: Command not found: ", 2);
		ft_putstr_fd(node->args[0], 2);
		ft_putstr_fd("\n", 2);
	}
}

void	exec_err(ast_node *node, t_shell *shell)
{
	if (errno == EACCES)
	{
		handle_acc(node);
		shell->exit = 126;
	}
	else if (errno == ENOENT)
	{
		handle_no_ent(node);
		shell->exit = 127;
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
