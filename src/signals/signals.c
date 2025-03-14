/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:57:10 by ylai              #+#    #+#             */
/*   Updated: 2025/03/14 15:29:20 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

volatile sig_atomic_t global_sigint;

void	sigint_handler(int sig)
{
    (void)sig;
    global_sigint = 1;
    write(STDOUT_FILENO, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

void	setup_sig_interactive(void)
{
    struct sigaction sa_int;
    struct sigaction sa_quit;
    
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
    struct sigaction sa;
    
    sa.sa_handler = SIG_DFL;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGQUIT, &sa, NULL);
}

void    sigint_heredoc(int sig)
{
    (void)sig;
    global_sigint = 1;
    rl_done = 1;
}

int    heredoc_rl_event(void)
{
    if (global_sigint)
    {
        rl_replace_line("", 0);
        rl_redisplay();
        global_sigint = 0;
    }
    return (0);
}

void	setup_sig_heredoc(void)
{
	struct sigaction sa_int;
    struct sigaction sa_quit;
	
    ft_memset(&sa_quit, 0, sizeof(struct sigaction));
	sa_int.sa_handler = sigint_heredoc;
	sa_int.sa_flags = 0;
	sigemptyset(&sa_int.sa_mask);
	sigaction(SIGINT, &sa_int, NULL);
	sa_quit.sa_handler = SIG_IGN;
    sigaction(SIGQUIT, &sa_quit, NULL);
}
