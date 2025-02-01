#include "../../inc/minishell.h"

void	parse(char *input)
{
	(void)input;
}

int	line_con(char *input)
{
	// char	*temp;
	// find if there is a '\' in input
	// if there is, join previous full_input with current input
	if (ft_strchr(input, 92))
	{
		// printf("input: %s\n", input);
		// temp = ft_strdup(*full_input);
		// *full_input = ft_strjoin(temp, input);
		// free(temp);
		return (1);
	}
	else
		return (0);
}



void  shell_loop(void)
{
  char  *input;
	// full_input will be the final one
	// so even if input is okay, we will still need to copy to full_input.
	char	*full_line;
	int		con_flag;

	full_line = ft_strdup("");
	con_flag = 0;
  while (1)
	{
		input = readline("minishell> ");
		// printf("input: %s\n", input);
		if (!input)
			break;
		if (*input)
		{
			if (con_flag == 0)
				full_line = ft_strdup(input);
			printf("full_line 1: %s\n", full_line);
			if (con_flag)
			{
				full_line = ft_strjoin(full_line, input);
				con_flag = 0;
				// continue;
			}
			printf("full_input 2: %s\n", full_line);
			if (line_con(input))
			{
				// full_line = ft_strjoin(full_line, input);
				printf("full_input 3: %s\n", full_line);
				con_flag = 1;
				// continue;
			}
			// full_line = ft_strjoin(full_line, input);
			printf("full_input 4: %s\n", full_line);
			add_history(full_line);
			parse(full_line);
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
		if (!con_flag)
			full_line = ft_strdup("");
		free(input);
	}
	free(full_line);
}
