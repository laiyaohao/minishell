#include "../../inc/minishell.h"

void	parse(char *input)
{
	(void)input;
}

// void	reallocate(char **tbr, char **tbu)
// {
// 	char	*temp;

// 	temp = ft_strdup(*tbr);
// 	free(*tbr);
// 	*tbr = ft_strjoin(temp, *tbu);
// 	free(temp);
// }



void  shell_loop(t_attr *attr)
{
  // char  *input;
  while (1)
	{
		attr->full_line = readline("minishell> ");
		if (!attr->full_line)
			break;
		if (*(attr->full_line))
		{
			// line_con(attr, &(attr->full_line), &input);
			// if (backslash(input))
			// {
			// 	strip(&(attr->full_line));
			// 	attr->con_flag = 1;
			// }
			if (check_line(attr))
				printf("have error lah deh %s\n", (attr->full_line));
			add_history((attr->full_line));
			parse((attr->full_line));
		}
		free(attr->full_line);
	}
	free(attr->full_line);
}
