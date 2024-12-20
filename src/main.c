#include "../inc/minishell.h"

void handle_sigint(int sig) {
	(void)sig;
	rl_on_new_line();       // Inform Readline that a new line is starting
	rl_replace_line("", 0); // Clear the current input line
	rl_redisplay();         // Redisplay the prompt
}

int main()
{
	char *input;
	// should have a struct for linked list
	t_list *history;

	signal(SIGINT, handle_sigint);

	while (1) {
		input = readline("minishell> ");
		if (!input) {
			printf("exit\n");
			break;
		}
		if (*input) {
			add_history(input); // Save command in history
			printf("You entered: %s\n", input);
			// add input to linked list
		}
		// Simulate clearing history on specific input
		if (input && strcmp(input, "clear_history") == 0) {
			rl_clear_history();
			printf("History cleared!\n");
		}
		// Command to print history
		if (strcmp(input, "history") == 0) {
			HIST_ENTRY **history = history_list();
			if (history) {
				for (int i = 0; history[i]; i++) {
					printf("%d: %s\n", i + 1, history[i]->line);
				}
			}
		}
		free(input);
	}
	rl_clear_history(); // Free history memory before exiting
	return 0;
}
