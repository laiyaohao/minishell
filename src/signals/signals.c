/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:57:10 by ylai              #+#    #+#             */
/*   Updated: 2025/03/08 13:32:04 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void handle_sigint(int sig)
{
	(void)sig;
	rl_on_new_line();       // Inform Readline that a new line is starting
	rl_replace_line("", 1); // Clear the current input line
	write(2, "\n", 1);
	rl_redisplay();         // Redisplay the prompt
}

// // should be called just before forking
// void	block_sig(void)
// {
// 	sigset_t sigs;

// 	sigemptyset(&sigs);
// 	sigaddset(&sigs, SIGINT);
// 	sigaddset(&sigs, SIGQUIT);
// 	sigprocmask(SIG_BLOCK, &sigs, NULL);
// }

// // should be called just after forking
// void	unblock_sig(void)
// {
// 	sigset_t sigs;

// 	sigemptyset(&sigs);
// 	sigaddset(&sigs, SIGINT);
// 	sigaddset(&sigs, SIGQUIT);
// 	sigprocmask(SIG_UNBLOCK, &sigs, NULL);
// }

void	reset_child_sig(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	setup_sig(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
