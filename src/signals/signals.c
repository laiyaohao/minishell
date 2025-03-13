/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:57:10 by ylai              #+#    #+#             */
/*   Updated: 2025/03/13 14:36:56 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

volatile sig_atomic_t in_heredoc = 0;

void	sigint_handler(int sig)
{
    (void)sig;
    if (in_heredoc)
	{
        in_heredoc = 0;
        write(STDOUT_FILENO, "\n", 1);
    } 
	else
	{
        write(STDOUT_FILENO, "\n", 1);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
}

void	sigquit_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "QUIT (core dumped)", 18);
}

void	setup_sig_interactive(void)
{
    struct sigaction sa;
    
    sa.sa_handler = sigint_handler; // Custom handler for SIGINT
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    
    sa.sa_handler = SIG_IGN;  // Ignore SIGQUIT (CTRL+\)
    sigaction(SIGQUIT, &sa, NULL);
}

void	setup_sig_exec(void)
{
    struct sigaction sa;
    
    sa.sa_handler = SIG_DFL;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGQUIT, &sa, NULL);
}

void	setup_sig_heredoc(void)
{
	struct sigaction sa;
	
	sa.sa_handler = SIG_DFL;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}
