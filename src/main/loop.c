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
  t_tok		*tokens;
  ast_node	*tree;
  
  while (1)
	{
		attr->full_line = readline("minishell> ");
		if (!attr->full_line)
			break;
		if (*(attr->full_line))
		{
			if (check_line(attr))
				printf("error with %s\n", (attr->full_line));
			add_history((attr->full_line));
			tokens = lexer(attr->full_line);
			if (!tokens)
				printf("Failed to tokenize\n");
			if (grammar_check(tokens))
				printf("Syntax error near unexpected token\n");
			else
			{
				tree = parser(tokens);
				debug_print_ast(tree);
			}
		}
		free(attr->full_line);
	}
	free(attr->full_line);
}
