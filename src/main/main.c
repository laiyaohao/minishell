/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:50:41 by ylai              #+#    #+#             */
/*   Updated: 2025/02/01 15:15:03 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int main(int argc, char **argv, char **env)
{
	// char *input;
	// should have a struct for linked list
	t_list *cmds;
	t_attr	attr;

	(void)argv;
	(void)env;
	(void)cmds;
	if (!check_arg(argc))
		return (0);
	setup_sig();
	init_attr(&attr);
	shell_loop(&attr);
	rl_clear_history(); // Free history memory before exiting
	return (0);
}
