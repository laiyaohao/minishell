/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:06:04 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/15 15:52:32 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_redir(t_redirect *rd, int fd)
{
	if (rd->type == T_REDIR_IN || rd->type == T_HEREDOC)
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
	if (rd && rd->type != T_HEREDOC)
		close(fd);
}

t_redirect	*check_last_hd(t_redirect *rd)
{
	t_redirect	*last;

	last = NULL;
	while (rd)
	{
		if (rd->type == T_HEREDOC)
			last = rd;
		rd = rd->next;
	}
	return (last);
}

void	prep_fd(t_redirect *current, int *fd)
{
	if (current->type == T_REDIR_IN)
		*fd = open(current->file, O_RDONLY);
	else if (current->type == T_REDIR_OUT)
		*fd = open(current->file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (current->type == T_REDIR_APP)
		*fd = open(current->file, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else if (current->type == T_HEREDOC)
	{
		*fd = current->fd;
		if (*fd == -1)
		{
			ft_putstr_fd("Error: Failed to create heredoc\n", 2);
			return ;
		}
	}
}

void	rd_err(t_redirect *rd)
{
	if (errno == EACCES)
	{
		ft_putstr_fd(rd->file, 2);
		ft_putstr_fd(" : Permission denied\n", 2);
	}
	else
	{
		ft_putstr_fd(rd->file, 2);
		ft_putstr_fd(" : No such file or directory\n", 2);
	}
}

int	exec_rd(t_redirect *rd, t_shell *shell)
{
	int			fd;
	t_redirect	*current;
	t_redirect	*last_hd;

	fd = -1;
	current = rd;
	last_hd = check_last_hd(rd);
	while (current)
	{
		prep_fd(current, &fd);
		if (fd < 0)
		{
			rd_err(rd);
			shell->exit = 1;
			return (1);
		}
		if (current->type == T_REDIR_OUT || current->type == T_REDIR_APP
			|| current->type == T_REDIR_IN)
			handle_redir(current, fd);
		if (current->type == T_HEREDOC && current == last_hd)
			handle_redir(current, fd);
		current = current->next;
	}
	return (0);
}
