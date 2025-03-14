/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:23:31 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/14 16:49:10 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	write_to_fd(int mode, int pipe_fd, char **line, t_shell *shell)
{
	char	*temp;

	temp = NULL;
	if (mode == 0)
		temp = heredoc_expand(*line, shell);
	else
		temp = ft_strdup(*line);
	write(pipe_fd, temp, ft_strlen(temp));
	write(pipe_fd, "\n", 1);
	free(*line);
	free(temp);
}

void	heredoc_rl(char *delim, t_shell *shell, int mode, int pipe_fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		if (g_sigint)
		{
			shell->exit = 130;
			break ;
		}
		line = readline("> ");
		if (!line)
		{
			rl_null(delim);
			break ;
		}
		if (ft_strncmp(line, delim, ft_strlen(line)) == 0)
		{
			free(line);
			break ;
		}
		write_to_fd(mode, pipe_fd, &line, shell);
	}
	rl_event_hook = NULL;
}

int	create_heredoc(char *delim, t_shell *shell, int mode)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		ft_putstr_fd("Error: Failed to pipe\n", 2);
		return (-1);
	}
	setup_sig_heredoc();
	rl_event_hook = heredoc_rl_event;
	heredoc_rl(delim, shell, mode, pipe_fd[1]);
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}
