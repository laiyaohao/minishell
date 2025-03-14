/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:40:21 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/14 16:51:57 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

volatile sig_atomic_t	g_sigint;

void	sigint_heredoc(int sig)
{
	(void)sig;
	g_sigint = 1;
	rl_done = 1;
}

int	heredoc_rl_event(void)
{
	if (g_sigint)
	{
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return (0);
}

void	sigint_handler(int sig)
{
	(void)sig;
	g_sigint = 1;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
