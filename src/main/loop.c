#include "../../inc/minishell.h"

void	parse(char *input)
{
	
}

void  shell_loop(void)
{
  char  *input;

  while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break;
		if (*input)
		{
			add_history(input);
			parse(input);
		}
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
}
