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



void  shell_loop(t_attr *attr)
{
  char  *input;
  while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break;
		if (*input)
		{
			line_con(attr, &(attr->full_line), &input);
			if (backslash(input))
			{
				strip(&(attr->full_line));
				attr->con_flag = 1;
			}
			else if (check_line(attr))
			{
				printf("error with %s\n", (attr->full_line));
				free(input);
				break;
			}
			printf("full_line: %s\n", attr->full_line);
			add_history((attr->full_line));
			parse((attr->full_line));
		}
		free(input);
	}
	free(attr->full_line);
}
