/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:23:31 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/10 21:40:28 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*heredoc_expand(char *s, t_shell *shell)
{
	char	*res;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (s && *s)
	{
		if (*s == '$')
			handle_var(&s, &res, shell);
		else
		{
			strcjoin(*s, &res);
			s++;
		}
	}
	strcjoin('\0', &res);
	return (res);
}

int	check_quote(char *s)
{
	int	i;

    i = 0;
	while (*s)
	{
		if (*s == '\'' || *s == '"')
			i = 1;
		s++;
	}
	return (i);
}

void    heredoc_rl(char *delim, t_shell *shell, int mode, int pipe_fd)
{
    char    *line;
    char    *temp;
    
    temp = NULL;
    line = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strncmp(line, delim, ft_strlen(delim)) == 0)
		{
			free(line);
			break ;
		}
		if (mode == 0)
			temp = heredoc_expand(line, shell);
		else
			temp = ft_strdup(line);
		write(pipe_fd, temp, ft_strlen(temp));
		write(pipe_fd, "\n", 1);
		free(line);
		free(temp);
	}
}

int	create_heredoc(char *delim, t_shell *shell, int mode)
{
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		ft_putstr_fd("Error: Failed to pipe\n", 2);
		return (-1);
	}
    heredoc_rl(delim, shell, mode, pipe_fd[1]);
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}

// int    create_heredoc(char *delim, t_shell *shell, int mode)
// {
//     int     pipe_fd[2];
//     char    *line;
//     char    *temp;

//     if (pipe(pipe_fd) == -1)
//     {
//         ft_putstr_fd("Error: Failed to pipe\n", 2);
//         return (-1);
//     }
//     ft_putstr_fd(">", 0);
//     while ((line = gnl(0)))
//     {
//         if (!(ft_strncmp(line, delim, ft_strlen(delim))))
//             break ;
//         if (mode == 0)
//             temp = heredoc_expand(line, shell);
//         else
//             temp = ft_strdup(line);
//         write(pipe_fd[1], temp, ft_strlen(temp));
//         free(line);
//         free(temp);
//         ft_putstr_fd(">", 0);
//     }
//     free(line);
//     close(pipe_fd[1]);
//     return (pipe_fd[0]);
// }
