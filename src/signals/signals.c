/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:57:10 by ylai              #+#    #+#             */
/*   Updated: 2025/03/14 16:54:09 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	setup_sig_interactive(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	ft_memset(&sa_int, 0, sizeof(struct sigaction));
	ft_memset(&sa_quit, 0, sizeof(struct sigaction));
	sa_int.sa_handler = sigint_handler;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sigaction(SIGINT, &sa_int, NULL);
	sa_quit.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa_quit, NULL);
}

void	setup_sig_exec(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_DFL;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	setup_sig_heredoc(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	ft_memset(&sa_int, 0, sizeof(struct sigaction));
	ft_memset(&sa_quit, 0, sizeof(struct sigaction));
	sa_int.sa_handler = sigint_heredoc;
	sa_int.sa_flags = 0;
	sigemptyset(&sa_int.sa_mask);
	sigaction(SIGINT, &sa_int, NULL);
	sa_quit.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa_quit, NULL);
}
