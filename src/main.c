/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:50:41 by ylai              #+#    #+#             */
/*   Updated: 2024/12/21 18:38:34 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int main(int argc, char **argv, char **env)
{
	char *input;
	// should have a struct for linked list
	// t_list *history;
	(void)argv;
	(void)env;
	if (!check_arg(argc))
		return (0);
	setup_sig();
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break;
		if (*input)
			add_history(input);
		// Simulate clearing history on specific input
		if (input && strcmp(input, "clear_history") == 0) {
			rl_clear_history();
			printf("History cleared!\n");
		}
		// Command to print history
		// if (strcmp(input, "history") == 0) {
		// 	HIST_ENTRY **history = history_list();
		// 	if (history) {
		// 		for (int i = 0; history[i]; i++) {
		// 			printf("%d: %s\n", i + 1, history[i]->line);
		// 		}
		// 	}
		// }
		free(input);
	}
	rl_clear_history(); // Free history memory before exiting
	return 0;
}
