#include "../../inc/minishell.h"

void  shell_loop(t_shell *shell)
{
  while (1)
	{
		shell->attr->full_line = readline("minishell> ");
		if (!shell->attr->full_line)
			break;
		if (*(shell->attr->full_line))
		{
			if (check_line(shell->attr))
				printf("have error lah deh: %s\n", (shell->attr->full_line));
			else
			{
				shell->tokens = lexer(shell->attr->full_line);
				if (!shell->tokens)
					ft_putstr_fd("Failed to tokenize\n", 2);
				if (grammar_check(shell->tokens))
					ft_putstr_fd("Syntax error near unexpected token\n", 2);
				else
				{
					shell->tree = parser(shell->tokens, shell);
					// debug_print_ast(shell->tree);
					exec_ast(shell->tree, shell);
					free_tree(shell->tree);
					free_tlist(shell->tokens);
				}
			}
			add_history((shell->attr->full_line));
		}
		free(shell->attr->full_line);
	}
	free(shell->attr->full_line);
	free(shell->attr->working_dir);
	free(shell->attr->old_working_dir);
}

// void  shell_loop(t_shell->attr *shell->attr)
// {
//   t_tok		*tokens;
//   ast_node	*tree;
  
//   while (1)
// 	{
// 		shell->attr->full_line = readline("minishell> ");
// 		if (!shell->attr->full_line)
// 			break;
// 		if (*(shell->attr->full_line))
// 		{
// 			if (check_line(shell->attr))
// 				printf("have error lah deh: %s\n", (shell->attr->full_line));
// 			else
// 			{
// 				tokens = lexer(shell->attr->full_line);
// 				if (!tokens)
// 					ft_putstr_fd("Failed to tokenize\n", 2);
// 				if (grammar_check(tokens))
// 					ft_putstr_fd("Syntax error near unexpected token\n", 2);
// 				else
// 				{
// 					tree = parser(tokens);
// 					debug_print_ast(tree);
// 					free_tree(tree);
// 					free_tlist(tokens);
// 				}
// 			}
// 			add_history((shell->attr->full_line));
// 		}
// 		free(shell->attr->full_line);
// 	}
// 	free(shell->attr->full_line);
// 	free(shell->attr->working_dir);
// 	free(shell->attr->old_working_dir);
// }

// void	reallocate(char **tbr, char **tbu)
// {
// 	char	*temp;

// 	temp = ft_strdup(*tbr);
// 	free(*tbr);
// 	*tbr = ft_strjoin(temp, *tbu);
// 	free(temp);
// }