#include "../../inc/minishell.h"

void	parse(char *input)
{
	(void)input;
}

void	reallocate(char **tbr, char **tbu)
{
	char	*temp;

	temp = ft_strdup(*tbr);
	free(*tbr);
	*tbr = ft_strjoin(temp, *tbu);
	free(temp);
}



void  shell_loop(void)
{
  char  *input;
	char	*full_line;
	int		con_flag;

	full_line = ft_strdup("");
	con_flag = 0;
  while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break;
		if (*input)
		{
			if (con_flag == 0)
			{
				free(full_line);
				full_line = ft_strdup(input);
			}
			if (con_flag)
			{
				reallocate(&full_line, &input);
				con_flag = 0;
			}
			if (line_con(input))
			{
				strip(&full_line);
				con_flag = 1;
			}
			add_history(full_line);
			parse(full_line);
		}
		free(input);
	}
	free(full_line);
}
